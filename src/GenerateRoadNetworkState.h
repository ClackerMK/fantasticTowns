#pragma once

#include <SFML/Graphics.hpp>


#include "State.h"

#include "Volcanic_HeightMap.h"
#include "Roads.h"
#include "Rivers.h"

class CGenerateRoadNetworkState :
	public CState
{
	CHeightMap*					m_map;
	
	CRivers						m_rivers;
	CRoads						m_roads;

	sf::Texture					m_backgorundTexture;
	sf::Sprite					m_backgroundSprite;
public:
	CGenerateRoadNetworkState();
	~CGenerateRoadNetworkState();

	// Event Handler
	void on_Enter();
	bool on_Update(sf::Time dt);
	void on_Render(sf::RenderTarget *target);
	void on_Exit();

	// Setter
	void setBackground(const sf::Texture& bgTexture)	{ m_backgorundTexture = bgTexture; m_backgroundSprite.setTexture(m_backgorundTexture); }
	void setHeightMap(CHeightMap* map)					{ m_map = map; }
};

