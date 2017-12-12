#include "Map.h"

Map::Map(const std::vector<std::string> mapText)
	: mapText_(mapText)
{
	waterChar_ = '~';
}

Map::~Map()
{
	for (Vertex* vertex : vertices_)
		delete vertex;
	for (Edge* edge : edges_)
		delete edge;
}

void Map::createMap(Rottweiler* dog, std::vector<Person*> persons)
{
	int index = 0;
	for (int yPos = 0; yPos < mapText_.size(); yPos++)
	{
		std::string line = mapText_[yPos];
		for (int xPos = 0; xPos < line.size(); xPos++)
		{
			addVertex(line, xPos, yPos, index++, dog, persons);
		}
	}
}

void Map::addRabbits(std::vector<Rabbit*> rabbits)
{
	for (Rabbit* rabbit : rabbits)
		rabbit->setPosition(vertices_[500]);
}

void Map::show(FWApplication* application)
{
	for (Vertex* vertex : vertices_)
		vertex->show(application);
}

void Map::addVertex(const std::string line, const int xPos, const int yPos, const int index, Rottweiler* dog, std::vector<Person*> persons)
{
	Vertex* vertex = new Vertex(xPos * 20, yPos * 20, index, line[xPos], dog, persons);
	vertices_.push_back(vertex);
	if (line[xPos] != waterChar_)
	{
		if (xPos != 0)
			if (line[xPos - 1] != waterChar_)
			{
				Vertex* vertexLeft = vertices_[yPos * line.size() + xPos - 1];
				Edge* edge = new Edge(vertex, vertexLeft);
				edges_.push_back(edge);
			}
		if (yPos != 0)
		{
			Vertex* vertexAbove = vertices_[(yPos - 1) * line.size() + xPos];
			if (vertexAbove->getType() != waterChar_)
			{
				Edge* edge = new Edge(vertex, vertexAbove);
				edges_.push_back(edge);
			}
		}
	}
}
