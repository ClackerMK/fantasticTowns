#include "PerlinNoise.h"

// Definition 1 Dimensional Perlin Noise Generator
// Stanardconstructor
CPerlinNoiseGenerator_1D::CPerlinNoiseGenerator_1D() :
	m_persistence(0), 
	m_seed(0)
{

}

// Copyconstructor
CPerlinNoiseGenerator_1D::CPerlinNoiseGenerator_1D(const CPerlinNoiseGenerator_1D& ref):
	m_persistence(ref.m_persistence),
	m_seed(ref.m_seed)
{
	std::for_each(ref.m_random_funcs.begin(), ref.m_random_funcs.end(), [this](std::function<double(int)>* fn) {
		addFunction(fn);
	});
}

// Fügt eine neue RNG-Generator Funktion hinzu
void CPerlinNoiseGenerator_1D::addFunction (std::function<double(int)>* func)
{
	m_random_funcs.push_back(func);
}

// Returns the specified Value
double CPerlinNoiseGenerator_1D::operator()(int x) const
{
	int i = 0;
	int val = 0;

	std::for_each(m_random_funcs.begin(), m_random_funcs.end(), [=, &val, &i](std::function<double(int)>* func)
	{
		int freq = std::pow(2, i);
		double per = std::pow(m_persistence, i);
		val += (*func)(freq * (m_seed + x)) * std::pow(m_persistence, i);
		i++;
	});

	return val;
}

// Definintion 2 Dimensional Perlin Noise Generator
// Stanardconstructor
CPerlinNoiseGenerator_2D::CPerlinNoiseGenerator_2D() :
	m_persistence(0),
	m_seed(0)
{

}

// Copyconstructor
CPerlinNoiseGenerator_2D::CPerlinNoiseGenerator_2D(const CPerlinNoiseGenerator_2D& ref) :
	m_persistence(ref.m_persistence),
	m_seed(ref.m_seed)
{
	std::for_each(ref.m_random_funcs.begin(), ref.m_random_funcs.end(), [this](std::function<double(int,int)>* fn) {
		addFunction(fn);
	});
}

// Fügt eine neue RNG-Generator Funktion hinzu
void CPerlinNoiseGenerator_2D::addFunction(std::function<double(int, int)>* func)
{
	m_random_funcs.push_back(func);
}

// Returns the specified Value
double CPerlinNoiseGenerator_2D::operator()(int x, int y) const
{
	int i = 0;
	int val = 0;

	std::for_each(m_random_funcs.begin(), m_random_funcs.end(), [=, &val, &i](std::function<double(int, int)>* func)
	{
		int freq = std::pow(2, i);
		double per = std::pow(m_persistence, i);
		val += (*func)(freq * (m_seed + x),freq * (m_seed + y)) * std::pow(m_persistence, i);
		i++;
	});

	return val;
}

// Definition 3D Perlin Noise Generator
// Stanardconstructor
CPerlinNoiseGenerator_3D::CPerlinNoiseGenerator_3D() :
	m_persistence(0),
	m_seed(0)
{

}

// Copyconstructor
CPerlinNoiseGenerator_3D::CPerlinNoiseGenerator_3D(const CPerlinNoiseGenerator_3D& ref) :
	m_persistence(ref.m_persistence),
	m_seed(ref.m_seed)
{
	std::for_each(ref.m_random_funcs.begin(), ref.m_random_funcs.end(), [this](std::function<double(int, int, int)>* fn) {
		addFunction(fn);
	});
}

// Fügt eine neue RNG-Generator Funktion hinzu
void CPerlinNoiseGenerator_3D::addFunction(std::function<double(int, int, int)>* func)
{
	m_random_funcs.push_back(func);
}

// Returns the specified Value
double CPerlinNoiseGenerator_3D::operator()(int x, int y, int z) const
{
	int i = 0;
	int val = 0;

	std::for_each(m_random_funcs.begin(), m_random_funcs.end(), [=, &val, &i](std::function<double(int, int, int)>* func)
	{
		int freq = std::pow(2, i);
		double per = std::pow(m_persistence, i);
		val += (*func)(freq * (m_seed + x), freq * (m_seed + y), freq * (m_seed + z)) * std::pow(m_persistence, i);
		i++;
	});

	return val;
}