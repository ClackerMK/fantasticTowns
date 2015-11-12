#include "StateManager.h"


CStateManager::CStateManager(sf::RenderWindow *wndw)
{
	m_Window = wndw;
}


CStateManager::~CStateManager()
{
	while (m_states.size() != 0)
	{
		popState();
	}
}

void CStateManager::run()
{
	sf::Clock clk;
	sf::Time  dt;
	while (m_Window->isOpen() && m_states.size() != 0)
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
	std::list<CState*>::iterator _it = m_states.begin();
	for (std::list<CState*>::iterator it = m_states.begin(); it != m_states.end(); ++it)
	{
		if ((*it)->on_Update(t))
		{
			if ((*it)->isPaused())
				break;

			_it = it;
		}
		else {
			it = _it;
		}
	}
}

void CStateManager::Render()
{
	m_Window->clear(sf::Color::White);


	for (std::list<CState*>::reverse_iterator it = m_states.rbegin(); it != m_states.rend(); ++it)
	{
		(*it)->on_Render(m_Window);
	}

	m_Window->display();
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

void CStateManager::popState(CState* state)
{
	std::list<CState*>::iterator it = m_states.begin();
	while (it != m_states.end())
	{
		if ((*it) == state)
		{
			m_states.erase(it);
			break;
		}
		++it;
	}
}


void CStateManager::switchState(CState* state)
{
	popState();
	pushState(state);
}