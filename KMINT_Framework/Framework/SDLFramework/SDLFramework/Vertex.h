#pragma once

#include <vector>
#include "RandomGenerator.h"
#include "FWApplication.h"

class Rottweiler;
class Person;
class Edge;

class Vertex
{
public:
	Vertex(const int xPosition, const int yPosition, const int index, const char type);
	~Vertex();
	void addEdge(Edge* edge);

	int GetX() const;
	int GetY() const;
	int GetIndex() const;
	char getType() const;
	std::vector<Edge*> GetEdges() const;
	Vertex* Move();

	void show(FWApplication* application) const;

private:
	std::vector<Edge*> edges_;
	int xPosition_;
	int yPosition_;
	int index_;
	char type_;
};

