#include "SquiglyLine.h"

#include <random>

SquiglyLine::SquiglyLine(sf::Vector2f point1, sf::Vector2f point2, sf::Color clr, double persistence, unsigned int Intersamples, unsigned int Noisesamples, int seed):
	m_Point1(point1),
	m_Point2(point2),
	m_Color(clr),
	m_InterpolationSamples(Intersamples),
	m_NoiseSamples(Noisesamples)
{
	m_noise_funcs.push_back(std::function<double(int)>([](int n)->double{
		n = (n >> 13) ^ n;
		int nn = (n * (n * n * 60493 + 19990303) + 1376312589) & 0x7fffffff;
		return 3 * (1.0 - ((double)nn / 1073741824.0));
	}));
	m_noise_funcs.push_back(std::function<double(int)>([](int n)->double {
		n = (n >> 13) ^ n;
		int nn = (n * (n * n * 1852699 + 15485867) + 488690747) & 0x7fffffff;
		return 3 * (1.0 - ((double)nn / 982110671.0));
	}));
	m_noise_funcs.push_back (std::function<double(int)> ([](int n)->double {
		n = (n >> 13) ^ n;
		int nn = (n * (n * n * 55579 + 32071759) + 472882639) & 0x7fffffff;
		return 3 * (1.0 - ((double)nn / 975152749.0));
	}));

	if (seed == -1)
	{
		std::random_device rand;
		m_Generator.setSeed(rand());
	}
	else
	{
		m_Generator.setSeed(seed);
	}

	m_Generator.setPersistence(persistence);
	m_Generator.addFunction(&(m_noise_funcs[0]));
	m_Generator.addFunction(&(m_noise_funcs[0]));
	m_Generator.addFunction(&(m_noise_funcs[0]));
}

SquiglyLine::~SquiglyLine()
{
}

void SquiglyLine::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	double foo;
	double val_a, val_b;
	int steps;
	int a, b;
	if (m_NoiseSamples != 0)
	{
		steps = m_InterpolationSamples / m_NoiseSamples;
	}
	else {
		steps = 1;
	}
	
	sf::Vector2f dir = m_Point2 - m_Point1;
	sf::Vector2f orth = dir;
	
	sf::VertexArray lines(sf::PrimitiveType::LinesStrip, m_InterpolationSamples);
	
	/*
	sf::VertexArray lines(sf::PrimitiveType::LinesStrip, 2);
	lines[0] = m_Point1;
	lines[1] = m_Point2;
	lines[0].color = lines[1].color = sf::Color::Black;
	*/

	foo = -orth.x;
	orth.x = orth.y;
	orth.y = foo;

	orth /= std::sqrt(orth.x * orth.x + orth.y * orth.y);
	
	for (int i = 0; i < m_InterpolationSamples; i++)
	{
		a = std::floor(static_cast<float>(i) / steps);
		b = std::ceil(static_cast<float>(i) / steps);

		lines[i].color = m_Color;
		
		if (i == 0)
			lines[i].position = m_Point1;
		else if (i == m_InterpolationSamples-1)
			lines[i].position = m_Point2;
		else
			lines[i].position = m_Point1 + dir * (static_cast<float>(i) / m_InterpolationSamples) + (orth * static_cast<float>(interpolate(m_Generator(a),m_Generator(b), static_cast<float>(static_cast<float>(i) / steps)-a)));
	}
	
	target.draw(lines, states);
}
