#include "Volcanic_HeightMap.h"

#include <iostream>
#include <vector>


CVolcanic_HeightMap::CVolcanic_HeightMap(int height, int width, int stones)
{
	m_size.x = width;
	m_size.y = height;
	
	m_stones = stones;

	// Intialize Array
	m_map = new int*[width];
	for (int x = 0; x < width; x++)
	{
		m_map[x] = new int[height];
		for (int y = 0; y < height; y++)
		{
			m_map[x][y] = 0;
		}
	}
}

CVolcanic_HeightMap::~CVolcanic_HeightMap()
{
	// Free the Memory
	for (int x = 0; x < m_size.x; x++)
	{
		delete[] m_map[x];
	}
	delete[] m_map;
}

void CVolcanic_HeightMap::generate()
{
	int x, y;
	
	for (int i = 0; i < m_stones; i++)
	{
		x = m_rng.uniform(0, m_size.x);
		y = m_rng.uniform(0, m_size.y);

		rollingStones(sf::Vector2i(x, y));
		std::cout << "Stein: " << i << " von " << m_stones << std::endl;
	}
}

void CVolcanic_HeightMap::rollingStones(sf::Vector2i pos)
{
	int min_x, min_y, max_x, max_y;
	std::vector<sf::Vector2i> smaler;

	min_x = pos.x - 1;
	min_y = pos.y - 1;
	max_x = pos.x + 1;
	max_y = pos.y + 1;

	for (int x = min_x; x < max_x; x++)
	{
		for (int y = min_y; y < max_y; y++)
		{
			if (x >= 0 && x < m_size.x && y >= 0 && y < m_size.y)
			{
				if (m_map[pos.x][pos.y] > m_map[x][y])
				{
					smaler.push_back(sf::Vector2i(x, y));
				}
			}
		}
	}

	if (smaler.size() == 0)
		m_map[pos.x][pos.y]++;
	else
		rollingStones(*m_rng.choose(smaler.begin(), smaler.end()));
}