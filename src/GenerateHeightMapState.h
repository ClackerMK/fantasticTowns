#pragma once
#include <SFML/Graphics.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#include <math.h>
#include <random>

#include "State.h"
#include "StateManager.h"

#include "Heightmap.h"
#include "HeightMapGenerator.h"

#include "HMMP_Volcanic.h"
#include "HMMP_Erosion.h"

class CGenerateHeightMapState :
	public CState
{
private:
	CHeightMap*								m_map;
	CHeightMapGenerator*					m_mapGenerator;
	std::vector<std::vector<sf::Vector2f>>	m_contours;
	sf::RectangleShape						m_shp;
	sf::RenderTexture						m_lines_renderTexture;
	sf::RenderTexture						m_map_renderTexture;
	sf::Sprite								m_lines_Sprite;
	sf::Sprite								m_map_Sprite;

	bool									underlay = true;
	bool									was_pressed = false;
public:
	CGenerateHeightMapState();
	~CGenerateHeightMapState();

	void on_Enter();
	bool on_Update(sf::Time dt);
	void on_Render(sf::RenderTarget *target);
	void on_Exit();
};

