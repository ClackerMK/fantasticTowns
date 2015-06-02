#pragma once
#include <SFML\Graphics.hpp>
#include <opencv2\imgproc.hpp>
#include <vector>

#include "State.h"
#include "StateManager.h"

#include "Volcanic_HeightMap.h"

class CGenerateHeightMapState :
	public CState
{
private:
	CVolcanic_HeightMap						m_map;
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

