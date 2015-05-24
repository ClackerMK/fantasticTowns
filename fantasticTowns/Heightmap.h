#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

// CHeightMap
// Abstract Class for storing and generating of Heightmaps


class CHeightMap
{
protected:
	int**			m_map;
	sf::Vector2i	m_size;

	template<typename T>
	struct cached
	{
		bool valid = false;
		T	 value;
	};

	mutable cached<int>			m_cached_minEle;
	mutable cached<int>			m_cached_maxEle;
	mutable cached<double>		m_cached_meanEle;
	mutable cached<double>		m_cached_medianEle;

public:
	virtual void generate() = 0;

	// Getter
	sf::Vector2i	getSize() { return m_size; }
	int				getHeight(sf::Vector2u pos) { m_map[pos.x][pos.y];}
	int				getMinEle() const;
	int				getMaxEle() const;
	double			getMeanEle()const;
	double			getMedianEle()const;

	// Setter
	void setHeight(sf::Vector2u pos, int val) { 
		m_map[pos.x][pos.y] = val;
		m_cached_minEle.valid = false;
		m_cached_maxEle.valid = false;
		m_cached_meanEle.valid = false;
		m_cached_medianEle.valid = false;
	}
};

