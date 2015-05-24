#include "GenerateHeightMapState.h"



CGenerateHeightMapState::CGenerateHeightMapState():
	m_map(sf::Vector2i(80,80))
{
	// Initialize Map Values
	m_map.setDrawingSize(1.f);
	m_map.setStability(3);
	m_map.setStones(5000);
	m_map.setMinStoneSize(5);
	m_map.setMaxStoneSize(15);

	// Initialize Shape
	m_shp.setFillColor(sf::Color::Green);
	m_shp.setSize(sf::Vector2f(800, 800));
	m_shp.setPosition(sf::Vector2f(0, 0));

	// Set Pause and Alpha
	setAlpha(255);
	setPaused(false);
}


CGenerateHeightMapState::~CGenerateHeightMapState()
{
}

void CGenerateHeightMapState::on_Enter() {
	m_map.generate();
	m_map.smoothStretchHeightMap(10);
}

void CGenerateHeightMapState::on_Render(sf::RenderTarget *target) {
	target->draw(m_shp);
	target->draw(m_map, sf::RenderStates(sf::BlendMultiply));
}

bool CGenerateHeightMapState::on_Update(sf::Time t) {
	sf::Keyboard keyb;

	if (keyb.isKeyPressed(sf::Keyboard::Escape))
	{
		m_pManager->popState();
		return false;
	}

	return true;
}

void CGenerateHeightMapState::on_Exit() {

}
