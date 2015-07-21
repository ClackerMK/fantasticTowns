#pragma once

#include "Heightmap.h"

// CHeightmapModificationProcess
// Abstract class for modifying (eg. adding or removing of "Particles")
class CHeightmapModificationProcess
{
public:
	/*  
	 *	Modifies a supplied Height-map
	 *  The exact way depends on implementation
	 *  @map: pointer to the Map
	 *	@seed: seed for random functions
	 */ 
	virtual void operator()(CHeightMap* map, int seed) = 0;
};