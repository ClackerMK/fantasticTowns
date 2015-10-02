#include "PerlinNoise_Heightmap.h"

CPerlinNoise_Heightmap::CPerlinNoise_Heightmap(sf::Vector2i size) 
{
	m_size = size;
	m_generator.setSeed(std::time(0));

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

CPerlinNoise_Heightmap::CPerlinNoise_Heightmap(sf::Vector2i size, unsigned int seed)
{
	m_size = size;
	m_generator.setSeed(seed);

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

void CPerlinNoise_Heightmap::generate()
{
	for (int x = 0; x < m_size.x; x++)
	{
		for (int y = 0; y < m_size.y; y++)
		{
			m_map[x][y] = m_generator(x, y);
		}
	}
}


double CPerlinNoise_Heightmap::m_interpolate(sf::Vector2f pos)
{
	std::pair<int, int> range_x = std::pair<int, int>(std::floor(pos.x), std::ceil(pos.x));
	std::pair<int, int> range_y = std::pair<int, int>(std::floor(pos.y), std::ceil(pos.y));


	double R1 = ((range_x.second - pos.x) * m_map[range_x.first][range_y.first]) + ((pos.x - range_x.first) * m_map[range_x.second][range_y.first]);
	double R2 = ((range_x.second - pos.x) * m_map[range_x.first][range_y.second]) + ((pos.x - range_x.first) * m_map[range_x.second][range_y.second]);

	return ((range_y.second - pos.y) * R1) + ((pos.y - range_y.first)*R2);
}