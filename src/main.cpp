#include <SFML\Graphics.hpp>

#include "StateManager.h"
#include "GenerateHeightMapState.h"

int main()
{
	sf::RenderWindow wndw(sf::VideoMode(800, 800, 32), "HeightMap");
	
	CStateManager manager(&wndw);

	CGenerateHeightMapState HM_State;
	
	// Register Manager
	HM_State.setManager(&manager);

	// Push State
	manager.pushState(&HM_State);

	manager.run();

	return 0;
}