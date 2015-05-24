#include "Volcanic_HeightMap.h"

#include <iostream>
#include <vector>

// Konstruktor
CVolcanic_HeightMap::CVolcanic_HeightMap(sf::Vector2i size) :
	m_stones(0),
	m_stability_rad(0),
	m_stones_size_min(0),
	m_stones_size_max(0),
	m_drawingSize(0.f),
	m_seed(std::time(0))
{
	m_size = size;
	
	// Intialize Array
	m_map = new double*[m_size.x];
	for (int x = 0; x < m_size.x; x++)
	{
		m_map[x] = new double[m_size.y];
		for (int y = 0; y < m_size.y; y++)
		{
			m_map[x][y] = 0;
		}
	}
}

// Konstruktor
CVolcanic_HeightMap::CVolcanic_HeightMap(sf::Vector2i size, unsigned int seed) :
	m_stones(0),
	m_stability_rad(0),
	m_stones_size_min(0),
	m_stones_size_max(0),
	m_drawingSize(0.f),
	m_seed(seed)
{
	m_size = size;

	// Intialize Array
	m_map = new double*[m_size.x];
	for (int x = 0; x < m_size.x; x++)
	{
		m_map[x] = new double[m_size.y];
		for (int y = 0; y < m_size.y; y++)
		{
			m_map[x][y] = 0;
		}
	}
}

// Kopierkonstruktor
CVolcanic_HeightMap::CVolcanic_HeightMap(const CVolcanic_HeightMap& ref):
	m_stones(ref.m_stones),
	m_stability_rad(ref.m_stability_rad),
	m_stones_size_min(ref.m_stones_size_min),
	m_stones_size_max(ref.m_stones_size_max),
	m_drawingSize(ref.m_drawingSize),
	m_seed(ref.m_seed)
{
	m_size = ref.m_size;
	
	// Intialize Array
	m_map = new double*[ref.m_size.x];
	for (int x = 0; x < ref.m_size.x; x++)
	{
		m_map[x] = new double[ref.m_size.y];
		for (int y = 0; y < ref.m_size.y; y++)
		{
			m_map[x][y] = ref.m_map[x][y];
		}
	}
}

// Destruktor
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
	int x, y, c = 0, cp = 0;
	std::srand(m_seed);

	m_cached_maxEle.valid = false;
	m_cached_minEle.valid = false;
	m_cached_meanEle.valid = false;
	m_cached_medianEle.valid = false;

	for (int x = 0; x < m_size.x; x++)
	{
		for (int y = 0; y < m_size.y; y++)
		{
			m_map[x][y] = 0;
		}
	}

	for (int i = 0; i < m_stones; i++)
	{
		x = std::rand() % m_size.x;
		y = std::rand() % m_size.x;
		
		
		for (int z = m_stones_size_min + (std::rand() % (m_stones_size_max - m_stones_size_min + 1)); z >= 0; z--)
		{
			rollingStones(sf::Vector2i(x, y));
		}
		//std::cout << "Stein: " << i << " von " << m_stones << std::endl;
		c++;
		if (c > (m_stones / 100))
		{
			c = 0;
			cp++;
			std::cout << "Prozent: " << cp << std::endl;
		}
	}
}

void CVolcanic_HeightMap::rollingStones(sf::Vector2i pos)
{
	int min_x, min_y, max_x, max_y;
	std::vector<sf::Vector2i> smaler;


	min_x = pos.x - m_stability_rad;
	min_y = pos.y - m_stability_rad;
	max_x = pos.x + m_stability_rad;
	max_y = pos.y + m_stability_rad;

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
		rollingStones(smaler[rand() % smaler.size()]);
}

double CVolcanic_HeightMap::m_interpolate(sf::Vector2f pos)
{
	std::pair<int, int> range_x = std::pair<int,int>(std::floor(pos.x), std::ceil(pos.x));
	std::pair<int, int> range_y = std::pair<int, int>(std::floor(pos.y), std::ceil(pos.y));
	
	
	double R1 = ((range_x.second - pos.x) * m_map[range_x.first][range_y.first]) + ((pos.x - range_x.first) * m_map[range_x.second][range_y.first]);
	double R2 = ((range_x.second - pos.x) * m_map[range_x.first][range_y.second]) + ((pos.x - range_x.first) * m_map[range_x.second][range_y.second]);

	return ((range_y.second - pos.y) * R1) + ((pos.y - range_y.first)*R2);
}