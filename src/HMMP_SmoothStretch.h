#ifndef HMMP_SMOOTHSTRETCH_H
#define HMMP_SMOOTHSTRETCH_H

#include "HeightMapModificationProcess.h"


/* Heightmap Modification Process for stretching the Height Map 
 */
class HMMP_SmoothStretch : public CHeightmapModificationProcess
{
private: 
	int 	m_factor = 1;		// How much the Map will be stretched
public: 
	// () operator
	// Modifies the supplied HeightMap
	virtual void operator()(CHeightMap* map, int seed) {
		map->smoothStretchHeightMap(m_factor);
	}

	// Setter and Getter
	void 	setFactor (int factor)	{m_factor = factor;}
	int 	getFactor () 			{ return m_factor; }

};

#endif