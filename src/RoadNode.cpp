#include "RoadNode.h"

#define STANDARD_COLOR sf::Color::Green
#define STANDARD_RADIUS 5.f
#define STANDARD_THICKNESS 1.f

// Standardconstructor
CRoadNode::CRoadNode() :
	m_Position(0,0)
{
	m_Shape.setFillColor(sf::Color::Transparent);
	
	m_Shape.setRadius(STANDARD_RADIUS);
	m_Shape.setOrigin(sf::Vector2f(STANDARD_RADIUS, STANDARD_RADIUS));

	m_Shape.setOutlineColor(STANDARD_COLOR);
	m_Shape.setOutlineThickness(STANDARD_THICKNESS);

	m_Shape.setPosition(m_Position);
}

CRoadNode::CRoadNode(const CRoadNode & ref) :
	m_Position(ref.m_Position),
	m_Edges(ref.m_Edges),
	m_Shape(ref.m_Shape)
{
}

void CRoadNode::draw(sf::RenderTarget & trgt, sf::RenderStates state) const
{
	trgt.draw(m_Shape);
}

bool CRoadNode::isConnected(int edge) const
{
	for (std::set<int>::iterator it = m_Edges.begin(); it != m_Edges.end(); it++)
	{
		if (*it == edge)
			return true;
	}

	return false;
}
