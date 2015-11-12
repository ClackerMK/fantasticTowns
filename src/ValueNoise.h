#pragma once

#include <vector>
#include <functional>
#include <algorithm>
#include <math.h>

// Declaration 1 Dimensional Perlin Noise Generator
class CValueNoiseGenerator_1D
{
private:
	std::vector<std::function<double(int)>*>	m_random_funcs;
	double										m_persistence;
	unsigned int								m_seed;

public:
			CValueNoiseGenerator_1D();
			CValueNoiseGenerator_1D(const CValueNoiseGenerator_1D& ref);
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
class CValueNoiseGenerator_2D
{
private:
	std::vector<std::function<double(int,int)>*>	m_random_funcs;
	double										m_persistence;
	unsigned int								m_seed;
public:
	CValueNoiseGenerator_2D();
	CValueNoiseGenerator_2D(const CValueNoiseGenerator_2D& ref);
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
class CValueNoiseGenerator_3D
{
private:
	std::vector<std::function<double(int, int, int)>*>	m_random_funcs;
	double										m_persistence;
	unsigned int								m_seed;
public:
	CValueNoiseGenerator_3D();
	CValueNoiseGenerator_3D(const CValueNoiseGenerator_3D& ref);
	void	addFunction(std::function<double(int, int, int)>* func);
	double 	operator()(int, int, int) const;

	// Getter
	double getPersistence() const { return m_persistence; }
	unsigned int getSeed() const { return m_seed; }

	// Setter
	void setPersistence(double persistence) { m_persistence = persistence; }
	void setSeed(unsigned int seed) { m_seed = seed; }
};