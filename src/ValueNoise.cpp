#include "ValueNoise.h"

// Definition 1 Dimensional Value Noise Generator
// Stanardconstructor
CValueNoiseGenerator_1D::CValueNoiseGenerator_1D() :
	m_persistence(0), 
	m_seed(0)
{

}

// Copyconstructor
CValueNoiseGenerator_1D::CValueNoiseGenerator_1D(const CValueNoiseGenerator_1D& ref):
	m_persistence(ref.m_persistence),
	m_seed(ref.m_seed)
{
	std::for_each(ref.m_random_funcs.begin(), ref.m_random_funcs.end(), [this](std::function<double(int)>* fn) {
		addFunction(fn);
	});
}

// Fügt eine neue RNG-Generator Funktion hinzu
void CValueNoiseGenerator_1D::addFunction (std::function<double(int)>* func)
{
	m_random_funcs.push_back(func);
}

// Returns the specified Value
double CValueNoiseGenerator_1D::operator()(int x) const
{
	int i = 0;
	int val = 0;

	std::for_each(m_random_funcs.begin(), m_random_funcs.end(), [=, &val, &i](std::function<double(int)>* func)
	{
		int freq = std::pow(2, i);
		double per = std::pow(m_persistence, i);
		val += (*func)(freq * (m_seed + x)) * per;
		i++;
	});

	return val;
}

// Definintion 2 Dimensional Value Noise Generator
// Stanardconstructor
CValueNoiseGenerator_2D::CValueNoiseGenerator_2D() :
	m_persistence(0),
	m_seed(0)
{

}

// Copyconstructor
CValueNoiseGenerator_2D::CValueNoiseGenerator_2D(const CValueNoiseGenerator_2D& ref) :
	m_persistence(ref.m_persistence),
	m_seed(ref.m_seed)
{
	std::for_each(ref.m_random_funcs.begin(), ref.m_random_funcs.end(), [this](std::function<double(int,int)>* fn) {
		addFunction(fn);
	});
}

// Fügt eine neue RNG-Generator Funktion hinzu
void CValueNoiseGenerator_2D::addFunction(std::function<double(int, int)>* func)
{
	m_random_funcs.push_back(func);
}

// Returns the specified Value
double CValueNoiseGenerator_2D::operator()(int x, int y) const
{
	int i = 0;
	int val = 0;

	std::for_each(m_random_funcs.begin(), m_random_funcs.end(), [=, &val, &i](std::function<double(int, int)>* func)
	{
		int freq = std::pow(2, i);
		double per = std::pow(m_persistence, i);
		val += (*func)(freq * (m_seed + x),freq * (m_seed + y)) * per;
		i++;
	});

	return val;
}

// Definition 3D Value Noise Generator
// Stanardconstructor
CValueNoiseGenerator_3D::CValueNoiseGenerator_3D() :
	m_persistence(0),
	m_seed(0)
{

}

// Copyconstructor
CValueNoiseGenerator_3D::CValueNoiseGenerator_3D(const CValueNoiseGenerator_3D& ref) :
	m_persistence(ref.m_persistence),
	m_seed(ref.m_seed)
{
	std::for_each(ref.m_random_funcs.begin(), ref.m_random_funcs.end(), [this](std::function<double(int, int, int)>* fn) {
		addFunction(fn);
	});
}

// Fügt eine neue RNG-Generator Funktion hinzu
void CValueNoiseGenerator_3D::addFunction(std::function<double(int, int, int)>* func)
{
	m_random_funcs.push_back(func);
}

// Returns the specified Value
double CValueNoiseGenerator_3D::operator()(int x, int y, int z) const
{
	int i = 0;
	int val = 0;

	std::for_each(m_random_funcs.begin(), m_random_funcs.end(), [=, &val, &i](std::function<double(int, int, int)>* func)
	{
		int freq = std::pow(2, i);
		double per = std::pow(m_persistence, i);
		val += (*func)(freq * (m_seed + x), freq * (m_seed + y), freq * (m_seed + z)) * per;
		i++;
	});

	return val;
}
