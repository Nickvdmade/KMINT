#include "Edge.h"



Edge::Edge(Vertex* start, Vertex* end)
{
	if (start != nullptr && end != nullptr) 
	{
		start_ = start;
		end_ = end;
	}
	start->addEdge(this);
	end->addEdge(this);
}

Edge::~Edge()
{
}

Vertex* Edge::GetOther(const Vertex* vertex) const
{
	if (vertex == start_)
		return end_;
	return start_;
}

Vertex* Edge::Move(Vertex* vertex)
{
	if (start_ == vertex)
		return end_;
	return start_;
}
