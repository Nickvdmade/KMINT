#pragma once
#include <vector>
#include "Edge.h"
#include "Vertex.h"
#include "FWApplication.h"

class Graph
{
public:
	Graph();
	~Graph();

	void addVertex(Vertex*);
	void addEdge(Edge*);
	void DrawGraph(FWApplication*);

private:
	std::vector<Vertex*> vertices;
	std::vector<Edge*> edges;
};

