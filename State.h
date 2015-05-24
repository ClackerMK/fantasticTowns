#pragma once

#include <SFML\Graphics.hpp>

class CStateManager;

class CState
{
protected:
	CStateManager*	m_pManager;
	sf::Uint8		m_Alpha;
	bool			m_Paused;
public:

	// Call Whenever the State should be Rendered
	// @param target The RenderTarget on which the State should be rendered on
	virtual void on_Render(sf::RenderTarget *target) = 0;
	// Call Whenever the State is updated
	// @para dt The Elapsed Time between Calls
	// @return false if the State was ended, true otherwise
	virtual bool on_Update(sf::Time dt) = 0;
	// Call Whenever the State is Entered
	virtual void on_Enter() = 0;
	// Call whenecer the State is left
	virtual void on_Exit() = 0;

	// Getter
	sf::Uint8	getAlpha() const { return m_Alpha; }
	bool		isPaused() const { return m_Paused; }
	

	// Setter
	void setAlpha (sf::Uint8 alpha)				{ m_Alpha = alpha; }
	void setPaused (bool paused)				{ m_Paused = paused; }
	void setManager (CStateManager* manager)	{ m_pManager = manager; }
};

