#include "HMMP_Volcanic.h"

// Standard constructor, initializes all values as 
HMMP_Volcanic::HMMP_Volcanic() :
	m_stones(0),
	m_stones_size_min(0),
	m_stones_size_max(0),
	m_stability_rad(0),
	m_trgt(NULL)
{

}

// Destructor
HMMP_Volcanic::~HMMP_Volcanic()
{

}

// operator()
// takes an already existing Height-map, modifies it and returns it
void HMMP_Volcanic::operator()(CHeightMap* map, int seed)
{
	int x, y, c = 0, cp = 0;
	sf::Vector2i size = map->getSize();

	// Initialize Randomizer

	m_randGenerator = std::mt19937(seed);
	

	// Define needed Distributions
	std::uniform_int_distribution<> map_dist_X(0, size.x - 1);
	std::uniform_int_distribution<> map_dist_Y(0, size.y - 1);
	std::uniform_int_distribution<> stones_amount(m_stones_size_min, m_stones_size_max);
	

	for (int i = 0; i < m_stones; i++)
	{
		x = map_dist_X(m_randGenerator);
		y = map_dist_Y(m_randGenerator);


		for (int z = stones_amount(m_randGenerator); z >= 0; z--)
		{
			rollingStones(map, sf::Vector2i(x, y));
		}

		m_trgt->clear();
		m_trgt->draw(*map);
		m_trgt->display();
	}
}

void HMMP_Volcanic::rollingStones(CHeightMap* map, sf::Vector2i pos)
{
	int min_x, min_y, max_x, max_y;
	
	sf::Vector2i size = map->getSize();
	std::vector<sf::Vector2i> smaler;

	min_x = pos.x - m_stability_rad;
	min_y = pos.y - m_stability_rad;
	max_x = pos.x + m_stability_rad;
	max_y = pos.y + m_stability_rad;

	for (int x = min_x; x < max_x; x++)
	{
		for (int y = min_y; y < max_y; y++)
		{
			if (x >= 0 && x < size.x && y >= 0 && y < size.y)
			{
				if (map->getValue(sf::Vector2f(pos.x,pos.y)) > map->getValue(sf::Vector2f(x, y)))
				{
					smaler.push_back(sf::Vector2i(x, y));
				}
			}
		}
	}

	if (smaler.size() == 0)
		map->setValue(sf::Vector2u(pos.x,pos.y), map->getValue(sf::Vector2f(pos.x, pos.y)) + 1);
	else
		rollingStones(map, smaler[std::uniform_int_distribution<>(0, smaler.size() - 1)(m_randGenerator)]);
}