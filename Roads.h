#pragma once

#include <SFML\Graphics.hpp>
#include <map>
#include <vector>

#include "Heightmap.h"
#include "Rivers.h"

class CRoads
{
private:
	CHeightMap*							m_HeightMap;
	
	std::map <int, sf::Vector2f>		m_PrimaryNodeList;
	std::map <int, std::vector<int> >	m_PrimaryRoadGraph;

	std::map <int, sf::Vector2f>		m_SecondaryNodeList;
	std::map <int, std::vector<int> >	m_SecondaryRoadGraph;

	double								m_Snap_Range;
	std::pair<double, double>			m_Node_Dist_Range;
	int									m_numNodes;
	int									m_numEdges;

	int									m_seed;
public:
	enum SAMPLE_MODE
	{

	};
										CRoads(CHeightMap* map, int seed = -1);
										CRoads(const CRoads& ref);
										
	void								generate(CRivers* river, double sea_level, SAMPLE_MODE mode, sf::RenderTarget* trgt = null );

	// Getter
	double	getSnap_Range() const			{ return m_Snap_Range; }
	double	getNode_Dist_Range_min() const	{ return m_Node_Dist_Range.first; }
	double	getNode_Dist_Range_max() const	{ return m_Node_Dist_Range.second; }
	int		getNumNodes() const				{ return m_numNodes; }
	int		getNumEdges() const				{ return m_numEdges; }

	// Setter
	void setSnap_Range(double snaprange)	{ m_Snap_Range = snaprange; }
	void setNode_Dist_Range_min(double min) { m_Node_Dist_Range.first = min; }
	void setNode_Dist_Range_max(double max) { m_Node_Dist_Range.second = max; }
	void setNumNodes(int nodes)				{ m_numNodes = nodes; }
	void setNumEdges(int edges)				{ m_numEdges = edges; }

	void setHeightMap(CHeightMap* map)		{ m_HeightMap = map; }
};
