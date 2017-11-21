#pragma once
#include "Vertex.h"

class Edge
{
public:
	Edge(Vertex*, Vertex*, const int);
	~Edge();

	int GetStartX() const;
	int GetStartY() const;
	int GetEndX() const;
	int GetEndY() const;
	int GetDistance() const;
	int From() const;
	int To() const;
	Vertex* Move(Vertex*);

private:
	Vertex* start_;
	Vertex* end_;
	int distance_;
};

