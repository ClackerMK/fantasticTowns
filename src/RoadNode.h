#pragma once

#include <SFML\Graphics.hpp>
#include <set>

// Road Node Class
// 
// Represents a point of the Node Network on which several Roads can meet 
// and which is one of two points between a road can spann
class CRoadNode : public sf::Drawable
{
	// Position on the Map
	sf::Vector2f		m_Position;

	// IDs of the Nodes connected to this one
	std::set<int>		m_Edges;

	// Graphical Shape
	sf::CircleShape		m_Shape;
public:
						CRoadNode();
						CRoadNode(const CRoadNode& ref);

	void draw(sf::RenderTarget& trgt, sf::RenderStates state) const;

	void addEdge(int n) { m_Edges.insert(n); }

	// Getter
	sf::Vector2f	getPosition() const { return m_Position; }
	int				getNumEdges() const { return m_Edges.size(); }
	
	// Is
	bool			isConnected(int edge) const;


	// Setter
	void			setPosition(sf::Vector2f pos)		{ m_Position = pos; 
														  m_Shape.setPosition(pos); }
	void			setRenderRadius(float r)			{ m_Shape.setRadius(r);
														  m_Shape.setOrigin(sf::Vector2f(r, r)); }
	void			setRenderBorderThicknes(float r)	{ m_Shape.setOutlineThickness(r); }
	void			setColor(sf::Color clr)				{ m_Shape.setOutlineColor(clr); }
};
