#pragma once

#include <SFML\Graphics.hpp>
#include <vector>


// CHeightMap
// Abstract Class for storing and generating of Heightmaps


class CHeightMap
{
protected:
	unsigned int**	m_map;
	sf::Vector2u	m_size;

	template<typename T>
	struct cached
	{
		bool valid = false;
		T	 value;
	};

	cached<unsigned int>	m_cached_minEle;
	cached<unsigned int>	m_cached_maxEle;
	cached<double>			m_cached_meanEle;
	cached<double>			m_cached_medianEle;

public:
	virtual void generate() = 0;

	// Getter
	sf::Vector2u getSize() { return m_size; }
	unsigned int getHeight(sf::Vector2u pos) { m_map[pos.x][pos.y];}
	unsigned int getMinEle();
	unsigned int getMaxEle();
	double		 getMeanEle();
	double		 getMedianEle();

	// Setter
	void setHeight(sf::Vector2u pos, unsigned int val) { 
		m_map[pos.x][pos.y] = val;
		m_cached_minEle.valid = false;
		m_cached_maxEle.valid = false;
		m_cached_meanEle.valid = false;
		m_cached_medianEle.valid = false;
	}
};

