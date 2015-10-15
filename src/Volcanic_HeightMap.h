#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include <math.h>

#include "Heightmap.h"


class CVolcanic_HeightMap :
	public CHeightMap
{
	int				m_stones;			// Amount of "position changes"
	int				m_stones_size_min;	// Minumum Size of single deposit
	int				m_stones_size_max;	// Maximum Size of single deposit
	unsigned int	m_seed;				// Seed of the RNG
	int				m_stability_rad;	// Radius in which the stones may fall down
	float			m_drawingSize;		// The Size of a single Field

	double			m_interpolate(sf::Vector2f pos) const;

	void			rollingStones(sf::Vector2i pos);

	std::mt19937	m_randGenerator;
public:
	CVolcanic_HeightMap(sf::Vector2i size);
	CVolcanic_HeightMap(sf::Vector2i size, unsigned int seed);
	CVolcanic_HeightMap(const CVolcanic_HeightMap& ref);
	~CVolcanic_HeightMap();

	void generate();
	void draw(sf::RenderTarget& trgt, sf::RenderStates states) const
	{
		sf::Color clr;
		sf::RectangleShape rect(sf::Vector2f(m_drawingSize, m_drawingSize));
		
		for (int x = 0; x < m_size.x; x++)
		{
			for (int y = 0; y < m_size.y; y++)
			{
				clr.b = clr.g = clr.r = static_cast<sf::Uint8>((getValue(sf::Vector2f(x,y))-getMinEle()) / static_cast<double>(getMaxEle()-getMinEle()) * 255);
				rect.setPosition(sf::Vector2f(x * m_drawingSize, y * m_drawingSize));
				rect.setFillColor(clr);
				trgt.draw(rect,states);
			}
		}
	}

	// Getter
	int			 getStones() const			{ return m_stones; }
	int			 getMinStoneSize() const	{ return m_stones_size_min; }
	int			 getMaxStoneSize() const	{ return m_stones_size_max; }
	unsigned int getSeed() const			{ return m_seed; }
	int			 getStability() const		{ return m_stability_rad; }
	float		 getDrawingSize() const		{ return m_drawingSize; }

	// Setter
	void setStones (int stones)				{ m_stones = stones; }
	void setMinStoneSize (int minSize)		{ m_stones_size_min = minSize; }
	void setMaxStoneSize (int maxSize)		{ m_stones_size_max = maxSize; }
	void setSeed (unsigned int seed)		{ m_seed = seed; }
	void setStability (int stab)			{ m_stability_rad = stab; }
	void setDrawingSize (float size)		{ m_drawingSize = size; }
};

