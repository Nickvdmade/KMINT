#include "Vertex.h"
#include "Edge.h"

Vertex::Vertex(const int xPosition, const int yPosition)
{
	xPosition_ = xPosition;
	yPosition_ = yPosition;
}

Vertex::~Vertex()
{
}

void Vertex::addEdge(Edge * edge)
{
	edges.push_back(edge);
}

int Vertex::GetX() const
{
	return xPosition_;
}

int Vertex::GetY() const
{
	return yPosition_;
}

void Vertex::SetIndex(const int index)
{
	index_ = index;
}

int Vertex::GetIndex() const
{
	return index_;
}

Vertex * Vertex::Move()
{
	RandomGenerator random;
	int number = random.GetRandomNumber(0, edges.size() - 1);
	return edges[number]->Move(this);
}
