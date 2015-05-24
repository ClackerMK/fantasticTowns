#include <SFML\Graphics.hpp>

#include "Volcanic_HeightMap.h"

int main()
{
	sf::RenderWindow wndw(sf::VideoMode(400, 400, 32), "HeightMap");

	CVolcanic_HeightMap map(400,400,1000);

	while (wndw.isOpen())
	{
		sf::Event evt;
		
		while (wndw.pollEvent(evt))
		{
			if (evt.type = sf::Event::Closed)
				wndw.close();
		}

		wndw.clear();

		wndw.draw(map);

		wndw.display();
	}

	return 0;
}