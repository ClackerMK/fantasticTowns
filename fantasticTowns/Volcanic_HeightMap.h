#pragma once

#include <SFML\Graphics.hpp>

#include "Heightmap.h"
#include "randutils.hpp"

class CVolcanic_HeightMap :
	public CHeightMap, public sf::Drawable
{
	int m_stones;
	randutils::mt19937_rng m_rng;

	void rollingStones(sf::Vector2i pos);
public:
	CVolcanic_HeightMap(int height, int width, int stones);
	~CVolcanic_HeightMap();

	void generate();
	void draw(sf::RenderTarget& trgt, sf::RenderStates states) const
	{
		sf::Color clr;
		sf::RectangleShape rect(sf::Vector2f(1.f, 1.f));
		for (int x = 0; x < m_size.x; x++)
		{
			for (int y = 0; y < m_size.y; y++)
			{
				clr.b = clr.g = clr.r = static_cast<sf::Uint8>(static_cast<double>(m_map[x][y]) / static_cast<double>(getMaxEle()) * 255);
				rect.setPosition(sf::Vector2f(x, y));
				rect.setFillColor(clr);
				trgt.draw(rect,states);
			}
		}
	}
};

