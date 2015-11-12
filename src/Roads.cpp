#include "Roads.h"

#include <random>

// Standardconstructor
// Only sets the seed and HeightMap and initializes everything else to zero
CRoads::CRoads(CHeightMap* map,int seed):
	m_seed(seed),
	m_HeightMap(map),
	m_numEdgesDeviation(0),
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
	m_numEdgesDeviation(ref.m_numEdgesDeviation),
	m_numNodes(ref.m_numNodes),
	m_numEdges(ref.m_numEdges),
	m_Node_Dist_Range(ref.m_Node_Dist_Range)
{
} // Copyconstructor

// Draw
// Draw the RoadNetwork onto a Rendertarget
void CRoads::draw(sf::RenderTarget& trgt, sf::RenderStates states) const
{
	for (std::vector<CRoadNode>::const_iterator it = m_PrimaryNodeList.begin(); it != m_PrimaryNodeList.end(); ++it)
	{
		trgt.draw(*it);
	}
}
// Generates the Roadgraph, by first creating a Pimary Road Graph (General Road Nodes) and
// subsequently using it to create a Secondary Road Graph (Concrete Road Placement)
//
// Information like Snap Range, numNodes, etc should be set before
//
// @param Rivers: A list of Rivers (on which there can't be any Primary Nodes and which Secondary Roads will cross in a straight line)
// @param Sea_Level: Min Height of every Node (Primary and Secondary)
// @param mode: Used Mode for choosing Samples
// @param renderTarget: Pointer to Target for Rendering Process (optional)
void CRoads::generate(const CRivers& rivers, double sea_level, SAMPLE_MODE mode, sf::RenderTarget* renderTarget)
{
	std::mt19937	rand;
	CRoadNode		node;
	sf::Vector2f	pos;
	float			distance;
	int				i = 0;
	bool			flag = true;

	// Define "Map Ranges"
	sf::Vector2i					size = m_HeightMap->getSize();
	std::pair<util::range<int>, util::range<int>> map_range(util::range<int>(0, size.x - 1), util::range<int>(0, size.y - 1 ));
	
	// Define Edge Distribution
	std::uniform_int_distribution<> numEdgesDev(m_numEdges - m_numEdgesDeviation, m_numEdges + m_numEdgesDeviation);

	rand.seed(m_seed);
	
	// Remove all former Nodes
	m_PrimaryNodeList.clear();
	m_SecondaryNodeList.clear();


	// Randomly Place Nodes
	while (i < m_numNodes)
	{
		while (flag)
		{
			flag = false;

			pos = util::getRandomVector2f(map_range.first, map_range.second, rand);
			
			for (std::vector<CRoadNode>::const_iterator it = m_PrimaryNodeList.begin(); it != m_PrimaryNodeList.end(); ++it)
			{
				distance = util::getDistanceSqr<float>(pos, it->getPosition());
				if (distance < std::pow(m_Node_Dist_Range.first,2) || distance > std::pow(m_Node_Dist_Range.second,2))
				{
					flag = true;
					break;
				}
			}
		}
		flag = true;
		node.setPosition(pos);
		m_PrimaryNodeList.push_back(node);
		i++;
	}

	// Conect nearest (n +- deviation) Nodes
	for (int ix = 0; ix != m_PrimaryNodeList.size(); ix++)
	{
		int actualNum = numEdgesDev(rand);
		int t = 0;
		
		while (t < actualNum || t >= m_PrimaryNodeList.size())
		{
			distance = 400000;
			int selectedNode = -1;
			for (int iy = 0; iy != m_PrimaryNodeList.size(); iy++)
			{
				float delta = util::getDistance(m_PrimaryNodeList[ix].getPosition(), m_PrimaryNodeList[iy].getPosition());
				if (!m_PrimaryNodeList[ix].isConnected(iy) && distance > delta)
				{
					distance = delta;
					selectedNode = iy;
				}
			}

			if (selectedNode != -1)
			{
				m_PrimaryNodeList[ix].addEdge(selectedNode);
				m_PrimaryNodeList[selectedNode].addEdge(ix);
			}

			t++;
		}	
	}
	draw(*renderTarget, sf::RenderStates::Default);
}