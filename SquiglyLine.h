#pragma once

#include <vector>

#include <SFML\Graphics.hpp>

#include "PerlinNoise.h"


class SquiglyLine :
	public sf::Drawable
{
private:
	sf::Vector2f							m_Point1;
	sf::Vector2f							m_Point2;
	sf::Color								m_Color;
	unsigned int							m_Samples;
	CPerlinNoiseGenerator_1D				m_Generator;
	std::vector<std::function<double(int)>> m_noise_funcs;

public:
	SquiglyLine(sf::Vector2f point1 = sf::Vector2f(0,0), sf::Vector2f point2 = sf::Vector2f(0,0), sf::Color clr = sf::Color::Black,double persistence = 0.5, unsigned int Samples = 1000, int seed = -1);
	~SquiglyLine();

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	// Setter
	void setPoints(sf::Vector2f p1, sf::Vector2f p2)	{ m_Point1 = p1; m_Point2 = p2; }
	void setPoint1(sf::Vector2f p1)						{ m_Point1 = p1; }
	void setPoint2(sf::Vector2f p2)						{ m_Point2 = p2; }
	void setPersistence(double persistence)				{ m_Generator.setPersistence(persistence); }
	void setSamples(unsigned int samples)				{ m_Samples = samples; }
	
	// Getter
	sf::Vector2f getPoint1()		{ return m_Point1; }
	sf::Vector2f getPoint2()		{ return m_Point2; }
	unsigned int getSamples()		{ return m_Samples; }
	double		 getPersisitence()	{ return m_Generator.getPersistence(); }
};

