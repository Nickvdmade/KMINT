#include "Edge.h"



Edge::Edge(const Vertex* start, const Vertex* end, const int weight)
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

int Edge::GetWeight() const
{
	return weight_;
}

int Edge::From() const
{
	return start_->GetIndex();
}

int Edge::To() const
{
	return end_->GetIndex();
}
