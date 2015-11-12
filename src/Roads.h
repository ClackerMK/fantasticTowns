#ifndef ROADS_H
#define ROADS_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>

#include "RoadNode.h"
#include "Heightmap.h"
#include "Rivers.h"
#include "utils.h"
#include "NodeSampleAlgs.h"

class CRoads : public sf::Drawable
{
private:
	CHeightMap*							m_HeightMap;
	
	std::vector<CRoadNode>				m_PrimaryNodeList;

	std::vector<CRoadNode>				m_SecondaryNodeList;

	std::pair<double, double>			m_Node_Dist_Range;
	int									m_numNodes;
	int									m_numEdgesDeviation;
	int									m_numEdges;

	int									m_seed;
public:
	
										CRoads(CHeightMap* map, int seed = -1);
										CRoads(const CRoads& ref);
										
	void								generate(double sea_level, SAMPLE_MODE mode, sf::RenderTarget* trgt = NULL);

	void								draw(sf::RenderTarget& trgt, sf::RenderStates states) const;
	
	// Getter
	double	getDeviation() const			{ return m_numEdgesDeviation; }
	double	getNode_Dist_Range_min() const	{ return m_Node_Dist_Range.first; }
	double	getNode_Dist_Range_max() const	{ return m_Node_Dist_Range.second; }
	int		getNumNodes() const				{ return m_numNodes; }
	int		getNumEdges() const				{ return m_numEdges; }

	// Setter
	void setDeviation(int dev)				{ m_numEdgesDeviation = dev; }
	void setNode_Dist_Range_min(double min) { m_Node_Dist_Range.first = min; }
	void setNode_Dist_Range_max(double max) { m_Node_Dist_Range.second = max; }
	void setNumNodes(int nodes)				{ m_numNodes = nodes; }
	void setNumEdges(int edges)				{ m_numEdges = edges; }
	void setSeed(int seed)					{ m_seed = seed; }

	void setHeightMap(CHeightMap* map)		{ m_HeightMap = map; }
};

#endif