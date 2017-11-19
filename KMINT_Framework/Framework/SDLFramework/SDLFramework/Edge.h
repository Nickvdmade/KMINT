#pragma once
#include "Vertex.h"

class Edge
{
public:
	Edge(const Vertex*, const Vertex*, const int);
	~Edge();

	int GetStartX() const;
	int GetStartY() const;
	int GetEndX() const;
	int GetEndY() const;
	int GetWeight() const;
	int From() const;
	int To() const;

private:
	const Vertex* start_;
	const Vertex* end_;
	int weight_;
};

