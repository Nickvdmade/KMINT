#include "Graph.h"



Graph::Graph()
{
	
}


Graph::~Graph()
{
}

void Graph::addVertex(Vertex* vertex)
{
	vertices.push_back(vertex);
}

void Graph::addEdge(Edge* edge)
{
	edges.push_back(edge);
}

void Graph::DrawGraph(FWApplication* application)
{
	int i = 0;
	for (auto it = begin(edges); it != end(edges); ++it, i++)
	{
		if(edges[i]->GetWeight() == 2) //water
			application->SetColor(Color(0, 0, 255, 255));
		else if(edges[i]->GetWeight() == 3) //lane
			application->SetColor(Color(255, 0, 0, 255));
		else //normal
			application->SetColor(Color(0, 128, 0, 255));

		application->DrawLine(edges[i]->GetStartX(), edges[i]->GetStartY(), edges[i]->GetEndX(), edges[i]->GetEndY());
	}

	application->SetColor(Color(255, 0, 255, 255));
	i = 0;
	for (auto it = begin(vertices); it != end(vertices); ++it, i++)
	{
		application->DrawRect(vertices[i]->getX(), vertices[i]->getY(), 10, 10, true);
	}
}

