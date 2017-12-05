#pragma once
#include <map>
#include "Vertex.h"
#include "Edge.h"
#include <deque>

class Astar
{
public:
	Astar();
	~Astar();
	std::vector<Edge*> Search(Vertex* start, Vertex* end);

private:
	std::map<Vertex*, int> realCosts_;
	std::map<Vertex*, int> estimateCosts_;
	std::map<Vertex*, Edge*> shortReverse_;
	std::vector<Vertex*> openSet_;
	std::vector<Vertex*> closedSet_;

	void CheckEdges(Vertex* vertex, Vertex* end);
	std::vector<Edge*> CalculateShortestPath(Vertex* start, Vertex* end);
};
