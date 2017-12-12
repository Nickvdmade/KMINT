#pragma once
#include <string>
#include "FWApplication.h"
#include "Vertex.h"
#include "Edge.h"
#include "Rottweiler.h"
#include "Person.h"
#include "Rabbit.h"

class Map
{
public:
	Map(const std::vector<std::string> mapText);
	~Map();
	void createMap(Rottweiler* dog, std::vector<Person*> persons);
	void addRabbits(std::vector<Rabbit*> rabbits);
	void show(FWApplication* application);

private:
	std::vector<std::string> mapText_;
	std::vector<Vertex*> vertices_;
	std::vector<Edge*> edges_;
	char waterChar_ = '~';

	void addVertex(const std::string line, const int xPos, const int yPos, const int index, Rottweiler* dog, std::vector<Person*> persons);
};

