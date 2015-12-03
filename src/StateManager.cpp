#include "StateManager.h"


CStateManager::CStateManager()
{

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
    while (m_states.size() != 0)
	{
		dt = clk.restart();

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
	for (std::list<CState*>::reverse_iterator it = m_states.rbegin(); it != m_states.rend(); ++it)
	{
        (*it)->on_Render();
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
