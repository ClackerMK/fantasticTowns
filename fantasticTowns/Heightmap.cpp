#include "Heightmap.h"


int CHeightMap::getMaxEle() const
{
	int max;

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

int CHeightMap::getMinEle() const
{
	int min;

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