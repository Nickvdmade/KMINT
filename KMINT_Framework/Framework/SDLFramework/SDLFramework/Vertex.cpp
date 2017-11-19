#include "Vertex.h"


Vertex::Vertex(const int xPosition, const int yPosition)
{
	xPosition_ = xPosition;
	yPosition_ = yPosition;
}

Vertex::~Vertex()
{
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
