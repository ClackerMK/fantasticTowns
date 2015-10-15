#include "HeightMapGenerator.h"

CHeightMapGenerator::CHeightMapGenerator()
{

}

CHeightMapGenerator::~CHeightMapGenerator()
{
	
}

CHeightMap* CHeightMapGenerator::generate(int seed, sf::Vector2i size)
{
	CHeightMap* op = new CHeightMap(size.x, size.y);

	for (int i = 0; i < m_generation_pipe.size(); i++)
	{
		(*m_generation_pipe[i])(op, seed);
	}

	return op;
}