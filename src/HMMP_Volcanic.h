#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include <math.h>
#include <iostream>

#include "HeightMapModificationProcess.h"


// Height-map Modificator that increases the height of the Map by depositing "dirt" particles which may "fall" to lower levels in the neighborhood
class HMMP_Volcanic : public CHeightmapModificationProcess
{
private:
	int				m_stones;			// Amount of "position changes"
	int				m_stones_size_min;	// Minimum Size of single deposit
	int				m_stones_size_max;	// Maximum Size of single deposit
	int				m_stability_rad;	// Radius in which the stones may fall down
	

	void			rollingStones(CHeightMap* map, sf::Vector2i pos);
	
	std::mt19937	m_randGenerator;
public:
	HMMP_Volcanic();
	~HMMP_Volcanic();

	virtual void operator()(CHeightMap* map, int seed);

	// Getter
	int		getStones() const 		{ return m_stones; }
	int		getMinStoneSize() const	{ return m_stones_size_min; }
	int		getMaxStoneSize() const	{ return m_stones_size_max; }
	int		getStability() const 	{ return m_stability_rad; }
	
	// Setter
	void 	setStones(int stones)		{ m_stones = stones; }
	void 	setMinStoneSize(int minSize)			{ m_stones_size_min = minSize; }
	void 	setMaxStoneSize(int maxSize)			{ m_stones_size_max = maxSize; }
	void 	setStability(int stab) 					{ m_stability_rad = stab; }
};