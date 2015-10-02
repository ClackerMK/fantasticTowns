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
	unsigned int							m_InterpolationSamples;
	unsigned int							m_NoiseSamples;
	CPerlinNoiseGenerator_1D				m_Generator;
	std::vector<std::function<double(int)>> m_noise_funcs;

	double									interpolate(double a, double b, float x) const {
		double ft = x * 3.1415927;
		double f = (1 - std::cos(ft)) * .5;

		return  a*(1 - f) + b*f;
	};
public:
	SquiglyLine(sf::Vector2f point1 = sf::Vector2f(0,0), sf::Vector2f point2 = sf::Vector2f(0,0), sf::Color clr = sf::Color::Black,double persistence = 0.5, unsigned int Interpolsamples = 20, unsigned int Noisesamples = 5, int seed = -1);
	~SquiglyLine();

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	// Setter
	void setPoints(sf::Vector2f p1, sf::Vector2f p2)	{ m_Point1 = p1; m_Point2 = p2; }
	void setPoint1(sf::Vector2f p1)						{ m_Point1 = p1; }
	void setPoint2(sf::Vector2f p2)						{ m_Point2 = p2; }
	void setPersistence(double persistence)				{ m_Generator.setPersistence(persistence); }
	void setNoiseSamples(unsigned int samples)			{ m_NoiseSamples = samples; }
	void setInterpolationSamples(unsigned int samples)	{ m_InterpolationSamples = samples; }

	// Getter
	sf::Vector2f getPoint1()				{ return m_Point1; }
	sf::Vector2f getPoint2()				{ return m_Point2; }
	unsigned int getNoiseSamples()			{ return m_NoiseSamples; }
	unsigned int getInterpolationSamples()	{ return m_InterpolationSamples; }
	double		 getPersisitence()			{ return m_Generator.getPersistence(); }
};

