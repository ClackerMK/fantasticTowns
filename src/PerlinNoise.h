#pragma once

#include <vector>
#include <functional>
#include <algorithm>
#include <math.h>

// Declaration 1 Dimensional Perlin Noise Generator
class CPerlinNoiseGenerator_1D
{
private:
	std::vector<std::function<double(int)>*>	m_random_funcs;
	double										m_persistence;
	unsigned int								m_seed;

public:
			CPerlinNoiseGenerator_1D();
			CPerlinNoiseGenerator_1D(const CPerlinNoiseGenerator_1D& ref);
	void	addFunction(std::function<double(int)>* func);
	double	operator()(int) const;

	// Getter
	double getPersistence() const	{ return m_persistence; }
	unsigned int getSeed() const	{ return m_seed; }

	// Setter
	void setPersistence(double persistence)	{ m_persistence = persistence; }
	void setSeed(unsigned int seed) { m_seed = seed; }
};

// Declaration 2 Dimensional Perlin Noise Generator
class CPerlinNoiseGenerator_2D
{
private:
	std::vector<std::function<double(int,int)>*>	m_random_funcs;
	double										m_persistence;
	unsigned int								m_seed;
public:
	CPerlinNoiseGenerator_2D();
	CPerlinNoiseGenerator_2D(const CPerlinNoiseGenerator_2D& ref);
	void	addFunction(std::function<double(int,int)>* func);
	double	operator()(int, int) const;

	// Getter
	double getPersistence() const { return m_persistence; }
	unsigned int getSeed() const  { return m_seed; }

	// Setter
	void setPersistence(double persistence) { m_persistence = persistence; }
	void setSeed(unsigned int seed) { m_seed = seed; }
};

// Declaration 3 Dimensional Perlin Noise Generator
class CPerlinNoiseGenerator_3D
{
private:
	std::vector<std::function<double(int, int, int)>*>	m_random_funcs;
	double										m_persistence;
	unsigned int								m_seed;
public:
	CPerlinNoiseGenerator_3D();
	CPerlinNoiseGenerator_3D(const CPerlinNoiseGenerator_3D& ref);
	void	addFunction(std::function<double(int, int, int)>* func);
	double 	operator()(int, int, int) const;

	// Getter
	double getPersistence() const { return m_persistence; }
	unsigned int getSeed() const { return m_seed; }

	// Setter
	void setPersistence(double persistence) { m_persistence = persistence; }
	void setSeed(unsigned int seed) { m_seed = seed; }
};