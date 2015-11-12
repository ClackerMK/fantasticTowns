#ifndef GENERATEROADNETWORKSTATE_H
#define GENERATEROADNETWORKSTATE_H

#include <SFML/Graphics.hpp>


#include "State.h"

#include "Heightmap.h"
#include "Roads.h"
#include "Rivers.h"

class CGenerateRoadNetworkState :
	public CState
{

	CHeightMap*					m_map;
	
	CRivers						m_rivers;
	CRoads						m_roads;

	sf::Sprite					m_backgroundSprite;

	int 						m_seed;
public:
	CGenerateRoadNetworkState(CHeightMap* map, int seed);
	~CGenerateRoadNetworkState();

	// Event Handler
	void on_Enter();
	bool on_Update(sf::Time dt);
	void on_Render(sf::RenderTarget *target);
	void on_Exit();

	// Setter
	void setBackground(const sf::Texture& bgTexture)
		{ m_backgroundSprite.setTexture(sf::Texture(bgTexture)); }
	void setHeightMap(CHeightMap* map)
		{ m_roads.setHeightMap(map); m_map = map; }
	void setSeed(int seed)
		{ m_roads.setSeed(seed); m_seed = seed; }
};

#endif