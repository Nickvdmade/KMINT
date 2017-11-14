#include "Edge.h"



Edge::Edge(Vertex* start, Vertex* end, int weight)
{
	if (start != nullptr && end != nullptr) 
	{
		start_ = start;
		end_ = end;
	}
	weight_ = weight;
}


Edge::~Edge()
{
}

const int Edge::GetStartX()
{
	return start_->getX() + 5;
}

const int Edge::GetStartY()
{
	return start_->getY() + 5;
}

const int Edge::GetEndX()
{
	return end_->getX() + 5;
}

const int Edge::GetEndY()
{
	return end_->getY() + 5;
}

const int Edge::GetWeight()
{
	return weight_;
}
