#include "Astar.h"

Astar::Astar()
{

}

Astar::~Astar()
{

}

std::vector<Edge*> Astar::Search(Vertex* start, Vertex* end)
{
	openSet_.push_back(start);
	realCosts_[start] = 0;
	estimateCosts_[start] = sqrt(pow(start->GetX() + end->GetX(), 2) + pow(start->GetY() + end->GetY(), 2));
	while(!openSet_.empty())
	{
		auto itvector = openSet_.begin();
		Vertex* vertex = *itvector;
		int cost = realCosts_[vertex];
		for (auto it = itvector + 1; it != openSet_.end(); it++)
		{
			if (realCosts_[*it] < cost)
			{
				itvector = it;
				vertex = *itvector;
				cost = realCosts_[vertex];
			}
		}
		openSet_.erase(itvector);
		CheckEdges(vertex, end);
		closedSet_.push_back(vertex);
		if (vertex == end)
			break;
	}
	return CalculateShortestPath(start, end);
}

void Astar::CheckEdges(Vertex* vertex, Vertex* end)
{
	std::vector<Edge*> edges = vertex->GetEdges();
	for each(Edge* edge in edges)
	{
		Vertex* otherVertex = edge->GetOther(vertex);
		int cost = realCosts_[vertex] + edge->GetDistance();
		if (find(closedSet_.begin(), closedSet_.end(), otherVertex) == closedSet_.end())
		{
			if (find(openSet_.begin(), openSet_.end(), otherVertex) != openSet_.end())
			{
				if (realCosts_[otherVertex] > cost)
				{
					realCosts_[otherVertex] = cost;
					shortReverse_[otherVertex] = edge;
				}
			}
			else
			{
				realCosts_[otherVertex] = cost;
				shortReverse_[otherVertex] = edge;
				estimateCosts_[otherVertex] = sqrt(pow(otherVertex->GetX() + end->GetX(), 2) + pow(otherVertex->GetY() + end->GetY(), 2));
				openSet_.push_back(otherVertex);
			}
		}
	}
}

std::vector<Edge*> Astar::CalculateShortestPath(Vertex* start, Vertex* end)
{
	std::vector<Edge*> shortPath;

	return shortPath;
}
