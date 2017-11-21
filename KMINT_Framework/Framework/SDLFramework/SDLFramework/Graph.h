#pragma once
#include <vector>
#include "Edge.h"
#include "Vertex.h"
#include "FWApplication.h"
#include "RandomGenerator.h"

class Graph
{
public:
	Graph();
	~Graph();

	void AddVertex(Vertex*);
	void AddEdge(Edge*);
	void DrawGraph(FWApplication*);
	Vertex* GetVertex();

private:
	std::vector<Vertex*> vertices;
	std::vector<Edge*> edges;
	int vIndex_;
};

