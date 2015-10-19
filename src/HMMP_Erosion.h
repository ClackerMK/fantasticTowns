#ifndef HMMP_EROSION_H
#define HMMP_EROSION_H

#include <vector>
#include <random>

#include "HeightMapModificationProcess.h"


/* Heightmap Modification Process for simulating water erosion
 *
 *  Originaly from https://code.google.com/p/fractalterraingeneration/wiki/Erosion_Models#Hydraulic_Erosion
 */
class HMMP_Erosion : public CHeightmapModificationProcess
{
private: 
	int 	m_iterations;	// The number of Iterations the Process performs 
	int 	m_rain_amount;	// Amount of rain per Cell per Iteration 
	int 	m_solubility;	// Amount of Soil eroded per Cell per Iteration
	double 	m_evaporation;	// Percentage of Water evaporating every Iteration 
	int 	m_capacity;		// Amount of Sediment a unit of Water can hold
public:
	// Standard Con- and Destructor
	HMMP_Erosion();
	~HMMP_Erosion();

	// () operator
	// Modifies the supplied HeightMap
	virtual void operator()(CHeightMap* map, int seed);


	// Setter and Getter
	void setIterations 	(int it) {m_iterations = it;}
	void setRainAmount 	(int rain) {m_rain_amount = rain;}
	void setSolubility 	(int solubility) {m_solubility = solubility;}
	void setEvaporation (double evaporation) {m_evaporation = evaporation;}
	void setCapacity 	(int capacity) {m_capacity = capacity;}

	int getIterations() const {return m_iterations;}
	int getRainAmount() const {return m_rain_amount;}
	int getSolubility() const {return m_solubility;}
	double getEvaporation() const {return m_evaporation;}
	int getCapacity() const {return m_capacity;}

};

#endif