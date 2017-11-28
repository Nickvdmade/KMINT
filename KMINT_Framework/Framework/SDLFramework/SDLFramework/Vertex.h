#pragma once

#include <vector>
#include "RandomGenerator.h"

class Edge;

class Vertex
{
public:
	Vertex(const int, const int);
	~Vertex();
	void addEdge(Edge* edge);

	int GetX() const;
	int GetY() const;
	void SetIndex(const int index);
	int GetIndex() const;
	std::vector<Edge*> GetEdges();
	Vertex* Move();

private:
	std::vector<Edge*> edges;
	int index_;
	int xPosition_;
	int yPosition_;
};

