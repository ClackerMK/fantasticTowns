#include "Roads.h"

#include <random>

// Standardconstructor
// Only sets the seed and HeightMap and initializes everything else to zero
CRoads::CRoads(CHeightMap* map,int seed):
	m_seed(seed),
	m_HeightMap(map),
	m_Snap_Range(0),
	m_Node_Dist_Range(0,0),
	m_numNodes(0),
	m_numEdges(0)
{
	if (m_seed == -1)
	{
		std::random_device rand;
		m_seed = rand();
	}
} // Standardkonstruktor


// Copyconstructor
// Copys the referenced Roadnetwork
CRoads::CRoads(const CRoads & ref):
	m_seed(ref.m_seed),
	m_HeightMap(ref.m_HeightMap),
	m_Snap_Range(ref.m_Snap_Range),
	m_numNodes(ref.m_numNodes),
	m_numEdges(ref.m_numEdges)
{
	m_Node_Dist_Range = ref.m_Node_Dist_Range;
} // Copyconstructor


// Generates the Roadgraph, by first creating a Pimary Road Graph (General Road Nodes) and
// subsequently using it to create a Secondary Road Graph (Concrete Road Placement)
//
// @param Rivers: A list of Rivers (on which there can't be any Primary Nodes and which Secondary Roads will cross in a straight line)
// @param Sea_Level: Min Height of every Node (Primary and Secondary)
// @param mode: Used Mode for choosing Samples
// @param renderTarget: Pointer to Target for Rendering Process (optional)
void CRoads::generate(CRivers* river, double sea_level, CRoads::SAMPLE_MODE mode, sf::RenderTarget* renderTarget)
{

}