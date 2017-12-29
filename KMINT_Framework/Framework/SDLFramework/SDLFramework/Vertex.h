#pragma once

#include <vector>
#include "RandomGenerator.h"
#include "FWApplication.h"

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
	void setVisited(bool visited);
	bool visited();
	void setShortPath(bool shortPath);
	void addVisitor();
	void removeVisitor();
	int getVisitors();

private:
	std::vector<Edge*> edges_;
	int xPosition_;
	int yPosition_;
	int index_;
	char type_;
	bool visited_;
	bool shortPath_;
	int visitors_;
};

