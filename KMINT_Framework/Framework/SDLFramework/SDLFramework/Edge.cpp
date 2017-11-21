#include "Edge.h"



Edge::Edge(Vertex* start, Vertex* end, const int weight)
{
	if (start != nullptr && end != nullptr) 
	{
		start_ = start;
		end_ = end;
	}
	distance_ = sqrt(pow(end_->GetX() - start_->GetX(), 2) + pow(end_->GetY() - start_->GetY(), 2)) * weight;
	start->addEdge(this);
	end->addEdge(this);
}


Edge::~Edge()
{
}

int Edge::GetStartX() const
{
	return start_->GetX() + 5;
}

int Edge::GetStartY() const
{
	return start_->GetY() + 5;
}

int Edge::GetEndX() const
{
	return end_->GetX() + 5;
}

int Edge::GetEndY() const
{
	return end_->GetY() + 5;
}

int Edge::GetDistance() const
{
	return distance_;
}

int Edge::From() const
{
	return start_->GetIndex();
}

int Edge::To() const
{
	return end_->GetIndex();
}

Vertex* Edge::Move(Vertex* vertex)
{
	if (start_ == vertex)
		return end_;
	return start_;
}
