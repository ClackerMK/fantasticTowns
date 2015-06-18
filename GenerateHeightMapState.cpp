#include "GenerateHeightMapState.h"
#include "SquiglyLine.h"

#include <iostream>

double getLength(sf::Vector2f vec)
{
	return std::sqrt(vec.x * vec.x + vec.y * vec.y);
}

CGenerateHeightMapState::CGenerateHeightMapState():
	m_map(new CVolcanic_HeightMap(sf::Vector2i(80,80)))
{
	// Initialize Map Values
	m_map->setDrawingSize(1.f);
	m_map->setStability(2);
	m_map->setStones(3000);
	m_map->setMinStoneSize(5);
	m_map->setMaxStoneSize(15);

	// Initialize Shape
	m_shp.setFillColor(sf::Color::White);
	m_shp.setSize(sf::Vector2f(800, 800));
	m_shp.setPosition(sf::Vector2f(0, 0));

	// Set Pause and Alpha
	setAlpha(255);
	setPaused(false);

	m_lines_renderTexture.clear();
	m_lines_renderTexture.create(800, 800);
	m_map_renderTexture.clear(sf::Color::White);
	m_map_renderTexture.create(800, 800);
}


CGenerateHeightMapState::~CGenerateHeightMapState()
{
}

void CGenerateHeightMapState::on_Enter() {
	SquiglyLine line;

	std::cout << "Start Generation" << std::endl;
	m_map->generate();
	std::cout << "Finished Generation" << std::endl;

	std::cout << "Start Smoothing" << std::endl;
	m_map->smoothStretchHeightMap(10);
	std::cout << "Finished Smoothing" << std::endl;
	
	m_map_renderTexture.draw(*m_map);
	m_map_renderTexture.display();
	m_map_Sprite.setTexture(m_map_renderTexture.getTexture());

	std::cout << "Start Contours" << std::endl;
	cv::Mat _map(cv::Size2d(m_map->getSize().x,m_map->getSize().y), cv::DataType<uchar>::type);
	std::vector<std::vector<cv::Point>> contours;
	for (double thresh = m_map->getMinEle()+0.5; thresh < m_map->getMaxEle(); thresh += 1)
	{
		for (int x = 0; x< m_map->getSize().x; x++)
		{
			for (int y = 0; y < m_map->getSize().y; y++)
				if (m_map->getValue(sf::Vector2f(x, y)) < thresh)
					_map.at<uchar>(y, x) = 0;
				else
					_map.at<uchar>(y, x) = 2;
					
		}
		cv::findContours(_map, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);
		for (std::vector<std::vector<cv::Point >>::const_iterator it = contours.begin();
			it != contours.end();
			it++)
		{
			std::vector<std::vector<sf::Vector2f>>::reverse_iterator ac;
			m_contours.push_back(std::vector<sf::Vector2f>());
			ac = m_contours.rbegin();
			for (std::vector<cv::Point >::const_iterator yt = it->begin();
				yt != it->end();
				yt++)
			{
				ac->push_back(sf::Vector2f(yt->x, yt->y));
			}
		}
		/*for (std::vector<std::vector<cv::Point>>::iterator it = contours.begin(); it != contours.end(); it++)
		{
			it->clear();
		}
		contours.clear();*/
	}
	std::cout << "Finished Contours" << std::endl;
	std::cout << "Start Drawing Contours" << std::endl;
	line.setPersistence(0.5);
	
	
	for (std::vector<std::vector<sf::Vector2f>>::const_iterator it = m_contours.begin();
	it != m_contours.end();
		it++)
	{

		for (std::vector<sf::Vector2f>::const_iterator point_it = it->begin();
		point_it != it->end();
			point_it++)
		{
			if (point_it == it->begin())
			{
				line.setPoint2(*point_it);
			}
			else
			{
				line.setPoints(line.getPoint2(), *point_it);
				line.setNoiseSamples(static_cast<int>(getLength(line.getPoint1() - line.getPoint2()))/ 20);
				line.setInterpolationSamples(2 + line.getNoiseSamples() * 15);
				m_lines_renderTexture.draw(line);
			}
		}
		line.setPoints(*(it->begin()), line.getPoint2());
		m_lines_renderTexture.draw(line);
	}
	
	m_lines_renderTexture.display();
	m_lines_Sprite.setTexture(m_lines_renderTexture.getTexture());
	m_lines_Sprite.setPosition(sf::Vector2f(0, 0));
	std::cout << "Finished Drawing Contours" << std::endl;
}

void CGenerateHeightMapState::on_Render(sf::RenderTarget *target) {
	
	
	target->draw(m_shp);
	if (underlay)
		target->draw(m_map_Sprite, sf::RenderStates(sf::BlendMultiply));
	target->draw(m_lines_Sprite);
}

bool CGenerateHeightMapState::on_Update(sf::Time t) {
	sf::Keyboard keyb;

	if (keyb.isKeyPressed(sf::Keyboard::Escape) && !was_pressed)
	{
		underlay = !underlay;
	}
	was_pressed = keyb.isKeyPressed(sf::Keyboard::Escape);
	return true;
}

void CGenerateHeightMapState::on_Exit() {

}
