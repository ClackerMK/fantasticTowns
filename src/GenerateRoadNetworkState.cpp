#include "GenerateRoadNetworkState.h"

#include <random>

CGenerateRoadNetworkState::CGenerateRoadNetworkState(CHeightMap* map, int seed)
: m_roads(map, seed)
{
	m_map = map;
	m_seed = seed;
}


CGenerateRoadNetworkState::~CGenerateRoadNetworkState()
{
}

void CGenerateRoadNetworkState::on_Enter()
{
}

bool CGenerateRoadNetworkState::on_Update(sf::Time dt)
{
	return false;
}

void CGenerateRoadNetworkState::on_Render(sf::RenderTarget * target)
{
}

void CGenerateRoadNetworkState::on_Exit()
{
}
