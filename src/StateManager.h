#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include <algorithm>

#include "State.h"

class CStateManager
{
private:
	std::list<CState*>		m_states;

	sf::RenderWindow*		m_Window;

	void					Update(sf::Time t);
	void					Render();
public:
							CStateManager(sf::RenderWindow* wndw);
							~CStateManager();

	void					run();
	void					pushState	(CState* state);
	void					popState	();
	void					popState	(CState* state);
	void					switchState	(CState* state);
};

