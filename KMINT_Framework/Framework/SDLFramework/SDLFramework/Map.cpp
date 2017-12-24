#include "Map.h"

Map::Map(const std::vector<std::string> mapText)
	: mapText_(mapText)
{
	waterChar_ = '~';
	misterStart = nullptr;
	missesStart = nullptr;
	cave = nullptr;
}

Map::~Map()
{
	for (Vertex* vertex : vertices_)
		delete vertex;
	for (Edge* edge : edges_)
		delete edge;
}

void Map::createMap()
{
	int index = 0;
	for (int yPos = 0; yPos < mapText_.size(); yPos++)
	{
		std::string line = mapText_[yPos];
		for (int xPos = 0; xPos < line.size(); xPos++)
		{
			addVertex(line, xPos, yPos, index++);
		}
	}
}

void Map::addRabbits(std::vector<Rabbit*> rabbits)
{
	RandomGenerator random;
	for (Rabbit* rabbit : rabbits)
	{
		Vertex* position = vertices_[0];
		while (position->getType() != 'X')
		{
			position = vertices_[random.GetRandomNumber(0, vertices_.size() - 1)];
			while (position->getVisitors() > 15)
				position = vertices_[random.GetRandomNumber(0, vertices_.size() - 1)];
		}
		rabbit->setStartPosition(position);
	}
}

void Map::show(FWApplication* application)
{
	for (Vertex* vertex : vertices_)
		vertex->show(application);
}

Vertex * Map::getStartMister()
{
	return misterStart;
}

Vertex * Map::getStartMisses()
{
	return missesStart;
}

Vertex * Map::getCave()
{
	return cave;
}

void Map::addVertex(const std::string line, const int xPos, const int yPos, const int index)
{
	char type = line[xPos];
	Vertex* vertex = new Vertex(xPos * 20, yPos * 20, index, type);
	vertices_.push_back(vertex);
	connectNeighbours(vertex, line, xPos, yPos);
	setStartPositions(type, vertex);
}

void Map::connectNeighbours(Vertex * vertex, const std::string line, const int xPos, const int yPos)
{
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

void Map::setStartPositions(char type, Vertex * vertex)
{
	if (type == 'M')
		misterStart = vertex;
	else if (type == 'V')
		missesStart = vertex;
	else if (type == 'O')
		cave = vertex;
}
