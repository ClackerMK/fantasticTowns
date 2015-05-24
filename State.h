#pragma once

#include <SFML\Graphics.hpp>

class CStateManager;

class CState
{
private:
	CStateManager*	m_pManager;
	sf::Uint8		m_Alpha;
	bool			m_Paused;
public:
	virtual void on_Render(sf::RenderWindow *window) = 0;
	virtual void on_Update(sf::Time dt) = 0;
	virtual void on_Enter() = 0;
	virtual void on_Exit() = 0;

	// Getter
	sf::Uint8	getAlpha() const { return m_Alpha; }
	bool		isPaused() const { return m_Paused; }
	

	// Setter
	void setAlpha (sf::Uint8 alpha)				{ m_Alpha = alpha; }
	void setPaused (bool paused)				{ m_Paused = paused; }
	void setManager (CStateManager* manager)	{ m_pManager = manager; }
};

