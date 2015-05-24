#pragma once
#include "State.h"
#include "StateManager.h"

#include "Volcanic_HeightMap.h"

class CGenerateHeightMapState :
	public CState
{
private:
	CVolcanic_HeightMap	m_map;
	sf::RectangleShape  m_shp;
public:
	CGenerateHeightMapState();
	~CGenerateHeightMapState();

	void on_Enter();
	bool on_Update(sf::Time dt);
	void on_Render(sf::RenderTarget *target);
	void on_Exit();
};

