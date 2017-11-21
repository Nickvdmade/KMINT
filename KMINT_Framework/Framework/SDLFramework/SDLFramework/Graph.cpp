#include "Graph.h"



Graph::Graph()
{
	vIndex_ = 0;
}


Graph::~Graph()
{
}

void Graph::AddVertex(Vertex* vertex)
{
	vertex->SetIndex(vIndex_++);
	vertices.push_back(vertex);
}

void Graph::AddEdge(Edge* edge)
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
		application->DrawRect(vertices[i]->GetX(), vertices[i]->GetY(), 10, 10, true);
	}
}

Vertex * Graph::GetVertex()
{
	RandomGenerator random;
	int number = random.GetRandomNumber(0, vertices.size() - 1);
	return vertices[number];
}
