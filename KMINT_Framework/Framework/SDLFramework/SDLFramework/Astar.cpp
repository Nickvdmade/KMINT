#include "Astar.h"

Astar::Astar()
{

}

Astar::~Astar()
{

}

std::stack<Edge*> Astar::Search(Vertex* start, Vertex* end)
{
	clearVisited();
	openSet_.clear();
	closedSet_.clear();
	shortReverse_.clear();
	openSet_.push_back(start);
	realCosts_[start] = 0;
	estimateCosts_[start] = sqrt(pow(end->GetX() - start->GetX(), 2) + pow(end->GetY() - start->GetY(), 2));
	startEstimateCost_ = estimateCosts_[start];
	while(!openSet_.empty())
	{
		auto itvector = openSet_.begin();
		Vertex* vertex = *itvector;
		if (vertex == end)
		{
			closedSet_.push_back(vertex);
			break;
		}
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
	}
	//set visited vertices
	for(Vertex* v : closedSet_) 
		v->setVisited(true);
	return CalculateShortestPath(start, end);
}

void Astar::clearVisited()
{
	for (Vertex* v : closedSet_)
	{
		v->setVisited(false);
		v->setShortPath(false);
	}
		
}

void Astar::CheckEdges(Vertex* vertex, Vertex* end)
{
	std::vector<Edge*> edges = vertex->GetEdges();
	bool found = false;
	for each(Edge* edge in edges)
	{
		Vertex* otherVertex = edge->GetOther(vertex);
		int cost = realCosts_[vertex] + 20;
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
				estimateCosts_[otherVertex] = sqrt(pow(end->GetX() - otherVertex->GetX(), 2) + pow(end->GetY() - otherVertex->GetY(), 2));
				if (estimateCosts_[otherVertex] <= estimateCosts_[vertex] + 10)
				{
					openSet_.push_back(otherVertex);
					found = true;
				}
			}
		}
	}
	if (!found)
	{
		for each (Edge* edge in edges)
		{
			Vertex* otherVertex = edge->GetOther(vertex);
			if (find(closedSet_.begin(), closedSet_.end(), otherVertex) == closedSet_.end())
			{
				if (find(openSet_.begin(), openSet_.end(), otherVertex) == openSet_.end())
				{
					if (estimateCosts_[otherVertex] < startEstimateCost_ + 40)
						openSet_.push_back(otherVertex);
				}
			}
		}
	}
}

std::stack<Edge*> Astar::CalculateShortestPath(Vertex* start, Vertex* end)
{
	std::stack<Edge*> shortPath;
	Vertex* findVertex = end;
	while (findVertex != start)
	{
		findVertex->setShortPath(true);
		Edge* edge = shortReverse_[findVertex];
		if (edge == nullptr)
			return shortPath;
		shortPath.push(edge);
		findVertex = edge->GetOther(findVertex);
	}
	return shortPath;
}
