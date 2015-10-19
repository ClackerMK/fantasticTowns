#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>

// CHeightMap
// Class for storing and modifying of height maps
class CHeightMap :
	public sf::Drawable
{
protected:
	int				m_drawingSize;

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

	double						m_interpolate(sf::Vector2f pos) const;
	void						m_stretch(sf::Vector2f factor);

public:
	// Constructor and Destructor
	CHeightMap(int x, int y);
	~CHeightMap();

	// Smoothing
	void			smoothStretchHeightMap(int radius);
	void			smoothHeightMap(int radius);
	
	// Drawing
	void			draw(sf::RenderTarget& trgt, sf::RenderStates states) const;

	// Getter
	sf::Vector2i	getSize() const { return m_size; }
	double			getValue(sf::Vector2f pos) const { return m_interpolate(pos); }
	double 			getValue(sf::Vector2i pos) const { return m_map[pos.x][pos.y]; }
	double			getMinEle() const;
	double			getMaxEle() const;
	double			getMeanEle()const;
	double			getMedianEle()const;
	int				getDrawingSize()const { return m_drawingSize; }

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
	void setDrawingSize(int size) { m_drawingSize = size; }
};

