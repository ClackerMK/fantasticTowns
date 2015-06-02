#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include <math.h>

// CHeightMap
// Abstract Class for storing and generating of Heightmaps


class CHeightMap :
	public sf::Drawable
{
protected:
	double**		m_map;
	sf::Vector2i	m_size;


	// Cached Values
	template<typename T>
	struct cached
	{
		bool valid = false;
		T	 value;
	};

	mutable cached<double>		m_cached_minEle;
	mutable cached<double>		m_cached_maxEle;
	mutable cached<double>		m_cached_meanEle;
	mutable cached<double>		m_cached_medianEle;

	virtual double				m_interpolate(sf::Vector2f pos) = 0; // Interpolation function, implementation not given
	void						m_stretch(sf::Vector2f factor);

public:
	
	virtual void	generate()		= 0;
			void	smoothStretchHeightMap(int radius);
			void	smoothHeightMap(int radius);
	// Getter
	sf::Vector2i	getSize() { return m_size; }
	double			getValue(sf::Vector2f pos) { return m_map[int(pos.x)][int(pos.y)]; }//return m_interpolate(pos); }
	double			getMinEle() const;
	double			getMaxEle() const;
	double			getMeanEle()const;
	double			getMedianEle()const;

	// Setter
	void setValue(sf::Vector2u pos, int val) { 
		m_map[pos.x][pos.y] = val;
		if (m_cached_minEle.valid && m_cached_minEle.value < val)
			m_cached_minEle.value = val;
		if (m_cached_minEle.valid && m_cached_minEle.value > val)
			m_cached_minEle.value = val;

		m_cached_meanEle.valid = false;
		m_cached_medianEle.valid = false;
	}
};

