#include "Heightmap.h"

double Cosine_Interpolate(double a, double b, double x)
{
    double ft = x * 3.1415927;
    double f = (1 - cos(ft)) * .5;

    return  a*(1-f) + b*f;
}


// Constructor: Create the Map with the supplied x and y Dimensions and a starting value of 0
CHeightMap::CHeightMap(int x, int y):
	m_size(x,y)
{
	m_drawingSize = 1;
	m_map = new double*[x];
	for (int ix = 0; ix < x; ix++)
	{
		m_map[ix] = new double[y];
		for (int iy = 0; iy < y; iy++)
		{
			m_map[ix][iy] = 0;
		}
	}
} // Constructor

// Destructor
CHeightMap::~CHeightMap()
{
	for (int x = 0; x < m_size.x; x++)
	{
		delete[] m_map[x];
	}
	delete[] m_map;
} // Destructor

// Copyconstructor
CHeightMap::CHeightMap(CHeightMap &ref) :
    m_drawingSize(ref.m_drawingSize),
    m_size(ref.m_size),
    m_cached_maxEle(ref.m_cached_maxEle),
    m_cached_meanEle(ref.m_cached_meanEle),
    m_cached_medianEle(ref.m_cached_medianEle),
    m_cached_minEle(ref.m_cached_minEle)
{

    m_map = new double*[ref.getSize().x];
    for (int ix = 0; ix < ref.getSize().x; ix++)
    {
        m_map[ix] = new double[ref.getSize().y];
        for (int iy = 0; iy < ref.getSize().y; iy++)
        {
            m_map[ix][iy] = ref.getValue(sf::Vector2i(ix,iy));
        }
    }
} // Copyconstructor

// Assign Operator
CHeightMap& CHeightMap::operator =(CHeightMap& map)
{

    for (int x = 0; x < m_size.x; x++)
    {
        delete[] m_map[x];
    }
    delete[] m_map;

    m_map = new double*[map.getSize().x];
    for (int ix = 0; ix < map.getSize().x; ix++)
    {
        m_map[ix] = new double[map.getSize().y];
        for (int iy = 0; iy < map.getSize().y; iy++)
        {
            m_map[ix][iy] = map.getValue(sf::Vector2i(ix,iy));
        }
    }

    m_drawingSize = map.m_drawingSize;
    m_size = map.m_size;
    m_cached_maxEle = map.m_cached_maxEle;
    m_cached_meanEle = map.m_cached_meanEle;
    m_cached_medianEle = map.m_cached_medianEle;

} //Assign Operator

// getMaxEle()
// Returns the maximum Elevation of the entire Map and caches the Value
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
	m_cached_maxEle.value = max;
	return max;
} // getMaxEle()

// getMinEle()
// Return the lowest Elevation of the entire Map and caches the value
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
	m_cached_minEle.value = min;
	return min;
} // getMinEle()

// getMeanEle()
// get the mean Height of the HeightMap caches the value
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
	m_cached_meanEle.value = total / (m_size.x * m_size.y);
	return m_cached_meanEle.value;
} // getMeanEle()

// getMedianEle()
// returns the median of the elevations of the Map and caches the value
double CHeightMap::getMedianEle() const
{
	std::vector<int> values;

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

	if (values.size() % 2){
		m_cached_medianEle.value = values[(values.size() + 1) / 2];
		return m_cached_medianEle.value;
	}
	else{
			m_cached_medianEle.value = (values[values.size() / 2] + values[(values.size() / 2) + 1]) / 2;
			return m_cached_medianEle.value;
		}
} // getMedianEle()

// m_stretch()
// Stretches the Map by a given factor, without smoothing
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
} // m_stretch

// smooth_point
// Helper function for smoothing a certain Point on a Height-map by returning the average value of its neighbors
double smooth_point(double** map, sf::Vector2i size, int radius, sf::Vector2i point)
{
	int		amount = 0;
	double	total = 0;
	double  rad_sq = radius * radius;

	for (int x = point.x - radius; x <= point.x + radius; x++)
	{
		for (int y = point.y - radius; y <= point.y + radius; y++)
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
}; // smooth_point()

// smoothStretchHeightMap()
// stretches the map smoothly
void CHeightMap::smoothStretchHeightMap(int radius)
{
	// first just simply stretch the map
	m_stretch(sf::Vector2f(radius * 2, radius * 2 ));

	// then smooth every new point
	smoothHeightMap(radius);

	// reset cached values to invalid just to be sure
	m_cached_maxEle.valid = false;
	m_cached_meanEle.valid = false;
	m_cached_medianEle.valid = false;
	m_cached_minEle.valid = false;
} // smoothStretchHeightMap()

// smoothHeightMap()
// Smooths the height-map by making every Elevation equal to the elevation of all points in a radius around it
void CHeightMap::smoothHeightMap(int radius)
{
	// Create new Map
	double** dummy = new double*[m_size.x];
	// Fill new Map with averages of the Neighbors
	for (int x = 0; x < m_size.x; x++)
	{
		dummy[x] = new double[m_size.y];

		for (int y = 0; y < m_size.y; y++)
		{
			dummy[x][y] = smooth_point(m_map, m_size, radius, sf::Vector2i(x, y));
		}
	}

	// Copy Values of new dummy map into Height-map
	for (int x = 0; x < m_size.x; x++)
	{
		for (int y = 0; y < m_size.y; y++)
		{
			m_map[x][y] = dummy[x][y];
		}
	}

	// free Memory of dummy map
	for (int x = 0; x < m_size.x; x++)
	{
		delete[] dummy[x];
	}
	delete[] dummy;

	// reset cached values to invalid
	m_cached_maxEle.valid = false;
	m_cached_meanEle.valid = false;
	m_cached_medianEle.valid = false;
	m_cached_minEle.valid = false;
} // smoothHeightMap()

// interpolate()
// get the Interpolated Value between four points on the Height-map
double CHeightMap::m_interpolate(sf::Vector2f pos) const
{
	std::pair<int, int> range_x = std::pair<int, int>(std::floor(pos.x), std::ceil(pos.x));
	std::pair<int, int> range_y = std::pair<int, int>(std::floor(pos.y), std::ceil(pos.y));


    if (range_x.first < 0)
        range_x.first = range_x.second = 0;
    if (range_y.first < 0)
        range_y.first = range_y.second = 0;

    if (range_x.second >= m_size.x)
        range_x.first = range_x.second = m_size.x -1;
    if (range_y.second >= m_size.y)
        range_y.first = range_y.second = m_size.y -1;


    double R1 = Cosine_Interpolate(m_map[range_x.first][range_y.first], m_map[range_x.second][range_y.first], pos.x - range_x.first);
    double R2 = Cosine_Interpolate(m_map[range_x.first][range_y.second],m_map[range_x.second][range_y.second], pos.x - range_x.first);

    return (Cosine_Interpolate(R1, R2, pos.y-range_y.first));
} // interpolate()


void CHeightMap::draw(sf::RenderTarget& trgt, sf::RenderStates states) const
{
	sf::RectangleShape rect(sf::Vector2f(m_drawingSize, m_drawingSize));
	int colorvalue;
	
	for (int x = 0; x < m_size.x; x++)
	{
		for (int y = 0; y < m_size.y; y++)
		{
			if (getMaxEle() != 0)
			{
				colorvalue = ((getValue((sf::Vector2i(x,y))) - getMinEle()) / (getMaxEle() - getMinEle())) * 255;
			} else 
			{
				colorvalue = 0;
			}
			rect.setPosition(sf::Vector2f(x * m_drawingSize, y * m_drawingSize));
			rect.setFillColor(sf::Color(0,colorvalue,0));
			trgt.draw(rect, states);
		}
	}
}
