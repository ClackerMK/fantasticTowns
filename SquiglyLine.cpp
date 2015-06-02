#include "SquiglyLine.h"


SquiglyLine::SquiglyLine(sf::Vector2f point1, sf::Vector2f point2, sf::Color clr, double persistence, unsigned int samples, int seed):
	m_Point1(point1),
	m_Point2(point2),
	m_Color(clr),
	m_Samples(samples)
{
	m_noise_funcs.push_back(std::function<double(int)>([](int n)->double{
		n = (n >> 13) ^ n;
		int nn = (n * (n * n * 60493 + 19990303) + 1376312589) & 0x7fffffff;
		return 0 * (1.0 - ((double)nn / 1073741824.0));
	}));
	m_noise_funcs.push_back(std::function<double(int)>([](int n)->double {
		n = (n >> 13) ^ n;
		int nn = (n * (n * n * 1852699 + 15485867) + 488690747) & 0x7fffffff;
		return 0 * (1.0 - ((double)nn / 982110671.0));
	}));
	m_noise_funcs.push_back (std::function<double(int)> ([](int n)->double {
		n = (n >> 13) ^ n;
		int nn = (n * (n * n * 55579 + 32071759) + 472882639) & 0x7fffffff;
		return 0 * (1.0 - ((double)nn / 975152749.0));
	}));

	if (seed == -1)
	{
		m_Generator.setSeed(std::time(0));
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
	sf::Vector2f dir = m_Point2 - m_Point1;
	sf::Vector2f orth = dir;
	
	//sf::VertexArray lines(sf::PrimitiveType::LinesStrip, m_Samples);
	sf::VertexArray lines(sf::PrimitiveType::LinesStrip, 2);
	lines[0] = m_Point1;
	lines[1] = m_Point2;
	lines[0].color = lines[1].color = sf::Color::Black;
	foo = -orth.x;
	orth.x = orth.y;
	orth.y = foo;

	orth /= std::sqrt(orth.x * orth.x + orth.y * orth.y);
	/*
	for (int i = 0; i < m_Samples; i++)
	{
		lines[i].color = m_Color;
		lines[i].position = m_Point1 + dir * (static_cast<float>(i) / m_Samples) + (orth * static_cast<float>(m_Generator(i)));
	}*/
	
	target.draw(lines, states);
}
