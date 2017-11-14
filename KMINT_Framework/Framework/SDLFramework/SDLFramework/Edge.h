#pragma once
#include "Vertex.h"

class Edge
{
public:
	Edge(Vertex*, Vertex*, int);
	~Edge();

	const int GetStartX();
	const int GetStartY();
	const int GetEndX();
	const int GetEndY();
	const int GetWeight();

private:
	Vertex* start_;
	Vertex* end_;
	int weight_;
};

