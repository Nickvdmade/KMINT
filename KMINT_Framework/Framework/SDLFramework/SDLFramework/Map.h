#pragma once
#include <string>
#include "FWApplication.h"
#include "Vertex.h"
#include "Edge.h"

class Map
{
public:
	Map(const std::vector<std::string> mapText);
	~Map();
	void createMap();
	void show(FWApplication* application);
	Vertex* getStartMister();
	Vertex* getStartMisses();
	Vertex* getCave();
	std::vector<Vertex*> getVertices();

private:
	std::vector<std::string> mapText_;
	std::vector<Vertex*> vertices_;
	std::vector<Edge*> edges_;
	char waterChar_ = '~';
	Vertex* misterStart;
	Vertex* missesStart;
	Vertex* cave;

	void addVertex(const std::string line, const int xPos, const int yPos, const int index);
	void connectNeighbours(Vertex* vertex, const std::string line, const int xPos, const int yPos);
	void setStartPositions(char type, Vertex* vertex);
};

