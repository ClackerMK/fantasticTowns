#include "Heightmap.h"


double CHeightMap::getMaxEle() const
{
	double max;

	// Was it already computed?
	if (m_cached_maxEle.valid)
		return m_cached_maxEle.value;

	// Start Value
	max = m_map[0][0];

	for (int x = 0; x < m_size.x; x++)
	{
		for (int y = 0; y < m_size.y; y++)
		{
			if (m_map[x][y] > max)
				max = m_map[x][y];
		}
	}

	m_cached_maxEle.valid = true;
	return m_cached_maxEle.value = max;
}

double CHeightMap::getMinEle() const
{
	double min;

	// Was it already computed?
	if (m_cached_minEle.valid)
		return m_cached_minEle.value;

	// Start Value
	min = m_map[0][0];

	for (int x = 0; x < m_size.x; x++)
	{
		for (int y = 0; y < m_size.y; y++)
		{
			if (m_map[x][y] < min)
				min = m_map[x][y];
		}
	}

	m_cached_minEle.valid = true;
	return m_cached_minEle.value = min;
}

double CHeightMap::getMeanEle() const
{
	int total = 0;

	// Was it already computed?
	if (m_cached_meanEle.valid)
		return m_cached_meanEle.value;

	for (int x = 0; x < m_size.x; x++)
	{
		for (int y = 0; y < m_size.y; y++)
		{
			total += m_map[x][y];
		}
	}

	m_cached_meanEle.valid = true;
	return m_cached_meanEle.value = total / (m_size.x * m_size.y);
}

double CHeightMap::getMedianEle() const
{
	std::vector<int> values;
	double median = 0.;

	// Was it already computed?
	if (m_cached_medianEle.valid)
		return m_cached_medianEle.value;

	for (int x = 0; x < m_size.x; x++)
	{
		for (int y = 0; y < m_size.y; y++)
		{
			values.push_back(m_map[x][y]);
		}
	}
	
	std::sort (values.begin(), values.end());

	m_cached_meanEle.valid = true;

	if (values.size() % 2)
		return m_cached_medianEle.value = values[(values.size() + 1) / 2];
	else
		return m_cached_medianEle.value = (values[values.size() / 2] + values[(values.size() / 2) + 1]) / 2;
}

void CHeightMap::m_stretch(sf::Vector2f factor)
{
	double** new_map;

	new_map = new double* [static_cast<int>(m_size.x * factor.x)];
	for (int x = 0; x < m_size.x * factor.x; x++)
	{
		new_map[x] = new double[static_cast<int>(m_size.y * factor.y)];
		for (int y = 0; y < m_size.y* factor.x; y++)
		{
			new_map[x][y] = m_map[static_cast<int>(x / factor.x)][static_cast<int>(y / factor.y)];
		}
	}

	// Free the Memory
	for (int x = 0; x < m_size.x; x++)
	{
		delete[] m_map[x];
	}
	delete[] m_map;

	m_map = new_map;
	m_size.x = static_cast<int>(m_size.x * factor.x);
	m_size.y = static_cast<int>(m_size.y * factor.y);
}

double smooth_point(double** map, sf::Vector2i size, int radius, sf::Vector2i point)
{
	int		amount = 0;
	double	total = 0;
	double  rad_sq = radius * radius;

	for (int x = point.x - radius; x < point.x + radius; x++)
	{
		for (int y = point.y - radius; y < point.y + radius; y++)
		{
			if (rad_sq > ((point.x - x) * (point.x - x) + (point.y - y) * (point.y - y)))
			{
				if (x >= 0 && x < size.x && y >= 0 && y < size.y)
				{
					amount++;
					total += map[x][y];
				}
			}
		}
	}

	return total / amount;
};

void CHeightMap::smoothStretchHeightMap(int radius)
{
	// first just simply stretch the map
	m_stretch(sf::Vector2f(radius , radius ));

	// then smooth every new point
	smoothHeightMap(radius);

	// reset cached values to invalid just to be sure
	m_cached_maxEle.valid = false;
	m_cached_meanEle.valid = false;
	m_cached_medianEle.valid = false;
	m_cached_minEle.valid = false;
}

void CHeightMap::smoothHeightMap(int radius)
{
	for (int x = 0; x < m_size.x; x++)
	{
		for (int y = 0; y < m_size.y; y++)
		{
			m_map[x][y] = smooth_point(m_map, m_size, radius, sf::Vector2i(x, y));
		}
	}

	// reset cached values to invalid just to be sure
	m_cached_maxEle.valid = false;
	m_cached_meanEle.valid = false;
	m_cached_medianEle.valid = false;
	m_cached_minEle.valid = false;
}