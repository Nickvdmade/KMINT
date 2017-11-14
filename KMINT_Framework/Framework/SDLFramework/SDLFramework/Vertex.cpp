#include "Vertex.h"


Vertex::Vertex(int xPosition, int yPosition)
{
	xPosition_ = xPosition;
	yPosition_ = yPosition;
}

Vertex::~Vertex()
{
}

const int Vertex::getX()
{
	return xPosition_;
}

const int Vertex::getY()
{
	return yPosition_;
}
