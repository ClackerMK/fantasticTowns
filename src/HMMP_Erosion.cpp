#include "HMMP_Erosion.h"

HMMP_Erosion::HMMP_Erosion():
m_capacity(0),
m_evaporation(0),
m_iterations(0),
m_solubility(0),
m_rain_amount(0)
{

}

HMMP_Erosion::~HMMP_Erosion()
{

}
 
// return the lowest Points in the von Neumann Neighbourhood
// only returns points lower than the chosen point
std::vector<sf::Vector2i> getLowest_vNeumann (const CHeightMap *map, const std::vector<std::vector<int>>& water, sf::Vector2i pos)
{
	std::vector<sf::Vector2i> ret;
	sf::Vector2i check_trgt;
	int value1 = 0, value2 = 0;

	value2 = water[pos.x][pos.y] + static_cast<int>(map->getValue(sf::Vector2i(pos.x,pos.y)));

	check_trgt.x = pos.x - 1;
	for (sf::Vector2i p :  {sf::Vector2i(pos.x - 1, pos.y - 1),
							sf::Vector2i(pos.x - 1, pos.y + 1),
							sf::Vector2i(pos.x + 1, pos.y - 1),
							sf::Vector2i(pos.x + 1, pos.y + 1)})
	{
		if (p.x >= 0 && p.x < map->getSize().x && p.y >= 0 && p.y < map->getSize().y)
		{
			value1 = water[p.x][p.y] + static_cast<int>(map->getValue(sf::Vector2i(p.x,p.y)));
			if (value1 < value2)
			{
				if (ret.size() == 0)
					ret.push_back(p);
				else if (static_cast<int>(map->getValue(ret[0])) + water[ret[0].x][ret[0].y] == value1)
					ret.push_back(p);
				else if (static_cast<int>(map->getValue(ret[0])) + water[ret[0].x][ret[0].y] > value2)
				{
					ret.clear();
					ret.push_back(p);
				}
			}
		}
	}

	return ret;
}

void HMMP_Erosion::operator()(CHeightMap *map, int seed)
{
	// Initialization
	// Map Size
	const std::size_t size_x = map->getSize().x;
	const std::size_t size_y = map->getSize().y;

	// number of iterations
	int n = 0;

	// Secondary Maps
	std::vector<std::vector<int>> water_map;
	std::vector<std::vector<int>> sedimentary_map;
	std::vector<std::vector<int>> difference_map;

	// Random Number Generator
	std::mt19937 RNG(seed);

	// lowest Points in the v. Neumann Neighbourhood
	std::vector<sf::Vector2i> lwstNeighbours;

	// Set Secondary Maps to zero
	water_map.resize(size_x);
	sedimentary_map.resize(size_x);
	difference_map.resize(size_x);
	for (int x = 0; x < size_x; ++x)
	{
		water_map[x].resize(size_y);
		sedimentary_map[x].resize(size_y);
		difference_map[x].resize(size_y);
		for (int y = 0; y < size_y; ++y)
		{
			water_map[x][y] = sedimentary_map[x][y] = difference_map[x][y] = 0;
		}
	}

	// Start modifying the map
	while (n < m_iterations)
	{
		// Add rain
		for (std::vector<int>& x:water_map )
		{	
			for (auto& s:x )
			{	

				s += m_rain_amount;
			}
		}

		// Add sedimentary 
		for (int x = 0; x < size_x; ++x)
		{
			for (int y = 0; y < size_y; ++y)
			{
				if (map->getValue(sf::Vector2f(x,y)) <= m_solubility)
				{
					difference_map[x][y] -= map->getValue(sf::Vector2i(x,y));
					sedimentary_map[x][y] += map->getValue(sf::Vector2i(x,y));
				} else
				{
					difference_map[x][y] -= m_solubility;
					sedimentary_map[x][y] += m_solubility;
				}
			}
		}

		// Move Water
		for (int x = 0; x < size_x; ++x)
		{
			for (int y = 0; y < size_y; ++y)
			{
				lwstNeighbours = getLowest_vNeumann(map, water_map, sf::Vector2i(x,y));

				if (lwstNeighbours.size() > 0)
				{
					std::uniform_int_distribution<int> dist(0, lwstNeighbours.size() - 1);

					sf::Vector2i selection = lwstNeighbours[dist(RNG)];

					if (static_cast<int>(map->getValue(selection)) + water_map[selection.x][selection.y] < static_cast<int>(map->getValue(sf::Vector2i(x,y))))
					{
						water_map[selection.x][selection.y] += water_map[x][y];
						water_map[x][y] = 0; 
					} else 
					{
						int diff = (water_map[x][y] + static_cast<int>(map->getValue(sf::Vector2i(x,y))) - static_cast<int>(map->getValue(selection)) - water_map[selection.x][selection.y])/2;
						water_map[selection.x][selection.y] += diff;
						water_map[x][y] -= diff; 
					}
				}				
			}
		}

		// Remove Sedimentary and apply change/reset difference map 
		for (int x = 0; x < size_x; ++x)
		{
			for (int y = 0; y < size_y; ++y)
			{
				int evaporated_water = water_map[x][y] * m_evaporation;
				water_map[x][y] -= evaporated_water;

				if (sedimentary_map[x][y] <= evaporated_water * m_capacity)
				{
					difference_map[x][y] += sedimentary_map[x][y];
					sedimentary_map[x][y] = 0;
				} else {
					difference_map[x][y] += evaporated_water * m_capacity;
					sedimentary_map[x][y] -= evaporated_water * m_capacity;
				}

				map->setValue(sf::Vector2u(x,y), map->getValue(sf::Vector2i(x,y)) + difference_map[x][y]);
				difference_map[x][y] = 0;
			}
		}
	
		n++;
	}

}