#include "GenerateRoadNetworkState.h"

#include <random>

CGenerateRoadNetworkState::CGenerateRoadNetworkState()
: m_roads(NULL, std::random_device()())
{

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
