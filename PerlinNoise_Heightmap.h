#pragma once

#include "Heightmap.h"
#include "PerlinNoise.h"

class CPerlinNoise_Heightmap : public CHeightMap
{
private:
	CPerlinNoiseGenerator_2D	m_generator;
	float						m_drawingSize;

	double						m_interpolate(sf::Vector2f pos);
public:
								CPerlinNoise_Heightmap(sf::Vector2i size);
								CPerlinNoise_Heightmap(sf::Vector2i size, unsigned int seed);
	void						generate();

	// Getter
	CPerlinNoiseGenerator_2D& getPN_Generator()				{ return m_generator; }
	float					  getDrawingSize()	const		{ return m_drawingSize; }

	// Setter
	void						setDrawingSize(float size)	{ m_drawingSize = size; }

	// Draw
	void draw(sf::RenderTarget& trgt, sf::RenderStates states) const
	{
		sf::Color clr;
		sf::RectangleShape rect(sf::Vector2f(m_drawingSize, m_drawingSize));

		for (int x = 0; x < m_size.x; x++)
		{
			for (int y = 0; y < m_size.y; y++)
			{
				clr.b = clr.g = clr.r = 255 - static_cast<sf::Uint8>(static_cast<double>(m_map[x][y]) / static_cast<double>(getMaxEle()) * 255);
				rect.setPosition(sf::Vector2f(x * m_drawingSize, y * m_drawingSize));
				rect.setFillColor(clr);
				trgt.draw(rect, states);
			}
		}
	}
};