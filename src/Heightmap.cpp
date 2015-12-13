#include "Heightmap.h"

double Interpolate(double a, double b, double x)
{

    return  a*(1-x) + b*x;
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


    double R1 = Interpolate(m_map[range_x.first][range_y.first], m_map[range_x.second][range_y.first], pos.x - range_x.first);
    double R2 = Interpolate(m_map[range_x.first][range_y.second],m_map[range_x.second][range_y.second], pos.x - range_x.first);

    return (Interpolate(R1, R2, pos.y-range_y.first));
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
