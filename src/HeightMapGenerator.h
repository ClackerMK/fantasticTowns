#pragma once

#include <vector>

#include "HeightMapModificationProcess.h"
#include "Heightmap.h"

class CHeightMapGenerator
{
private:
	// List of Modification Processes for generating a new height-map
	std::vector<CHeightmapModificationProcess*> m_generation_pipe;

public:
	// Constructor & Destructor
	CHeightMapGenerator();
	~CHeightMapGenerator();

	// Creates a new HeightMap and returns a pointer to it
	// @seed: seed for the random number generator
	CHeightMap* generate(int seed, sf::Vector2i size);
	
	// Manipulators of the Generation Pipeline
	// Adds a Process to the generation pipe (Applied in order of being added)
	void		pushProcess(CHeightmapModificationProcess* process)			{ m_generation_pipe.push_back(process);	}
	// Clears the Entire generation pipe
	void		clearPipe()													{ m_generation_pipe.clear(); }
	// Deletes the last added Process
	void		popProcess()												{ m_generation_pipe.pop_back(); }
};