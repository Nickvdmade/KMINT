#pragma once
#include "Vertex.h"

class Edge
{
public:
	Edge(Vertex*, Vertex*);
	~Edge();

	Vertex* GetOther(const Vertex* vertex) const;
	Vertex* Move(Vertex*);

private:
	Vertex* start_;
	Vertex* end_;
};

