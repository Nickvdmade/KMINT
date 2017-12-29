#pragma once
#include <map>
#include "Vertex.h"
#include "Edge.h"
#include <stack>

class Astar
{
public:
	Astar();
	~Astar();
	std::stack<Edge*> Search(Vertex* start, Vertex* end);
	void clearVisited();

private:
	std::map<Vertex*, int> realCosts_;
	std::map<Vertex*, float> estimateCosts_;
	int startEstimateCost_;
	std::map<Vertex*, Edge*> shortReverse_;
	std::vector<Vertex*> openSet_;
	std::vector<Vertex*> closedSet_;

	void CheckEdges(Vertex* vertex, Vertex* end);
	std::stack<Edge*> CalculateShortestPath(Vertex* start, Vertex* end);
};
