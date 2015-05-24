#include "StateManager.h"


CStateManager::CStateManager(sf::RenderWindow *wndw)
{
	m_Window = wndw;
}


CStateManager::~CStateManager()
{
	while (m_states.size != 0)
	{
		popState();
	}
}

void CStateManager::run()
{
	sf::Clock clk;
	sf::Time  dt;
	while (m_Window->isOpen())
	{
		dt = clk.restart();
		sf::Event evt;
		while (m_Window->pollEvent(evt))
		{
			if (evt.type == sf::Event::Closed)
			{
				m_Window->close();
			}
		}

		Update(dt);
		Render();
	}
}

void CStateManager::Update(sf::Time t)
{
	for (std::list<CState*>::iterator it = m_states.begin(); it != m_states.end(); it++)
	{
		(*it)->on_Update(t);

		if ((*it)->isPaused())
			break;
	}
}

void CStateManager::Render()
{
	for (std::list<CState*>::iterator it = m_states.begin(); it != m_states.end(); it++)
	{
		(*it)->on_Render(m_Window);

		if ((*it)->getAlpha == 255)
			break;
	}
}

void CStateManager::pushState(CState* state)
{
	m_states.push_front(state);
	state->on_Enter();
}

void CStateManager::popState()
{
	(*m_states.begin())->on_Exit();
	m_states.pop_front();
}

void CStateManager::switchState(CState* state)
{
	popState();
	pushState(state);
}