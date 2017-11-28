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
		Vertex* vertex = openSet_.front();
		openSet_.pop_front();
		CheckEdges(vertex, end);

	}
	std::vector<Edge*> stuff;
	return stuff;
}

void Astar::CheckEdges(Vertex* vertex, Vertex* end)
{
	std::vector<Edge*> edges = vertex->GetEdges();
	for each(Edge* edge in edges)
	{
		Vertex* otherVertex = edge->GetOther(vertex);
		int cost = realCosts_[vertex] + edge->GetDistance();
		std::vector<Vertex*>::iterator it = find(closedSet_.begin(), closedSet_.end(), otherVertex);
		if (it != closedSet_.end())
		{
			if (realCosts_[otherVertex] > cost)
			{
				realCosts_[otherVertex] = cost;
				closedSet_.erase(it);
				openSet_.push_back(otherVertex);
				return;
			}
		}
		if (find(openSet_.begin(), openSet_.end(), otherVertex) != openSet_.end())
		{
			if (realCosts_[otherVertex] > cost)
				realCosts_[otherVertex] = cost;
		}
		else
		{
			realCosts_[otherVertex] = cost;
			estimateCosts_[otherVertex] = sqrt(pow(otherVertex->GetX() + end->GetX(), 2) + pow(otherVertex->GetY() + end->GetY(), 2));
			openSet_.push_back(otherVertex);
		}
	}
}
