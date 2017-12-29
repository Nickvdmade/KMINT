#include "Vertex.h"
#include "Edge.h"

Vertex::Vertex(const int xPosition, const int yPosition, const int index, const char type)
	: xPosition_(xPosition)
	, yPosition_(yPosition)
	, index_(index)
	, type_(type)
	, visited_(false)
	, shortPath_(false)
	, visitors_(0)
{
	
}

Vertex::~Vertex()
{
}

void Vertex::addEdge(Edge * edge)
{
	edges_.push_back(edge);
}

int Vertex::GetX() const
{
	return xPosition_;
}

int Vertex::GetY() const
{
	return yPosition_;
}

int Vertex::GetIndex() const
{
	return index_;
}

char Vertex::getType() const
{
	return type_;
}

std::vector<Edge*> Vertex::GetEdges() const
{
	return edges_;
}

Vertex * Vertex::Move()
{
	RandomGenerator random;
	int number = random.GetRandomNumber(0, edges_.size() - 1);
	return edges_[number]->Move(this);
}

void Vertex::show(FWApplication* application) const
{
	switch (type_)
	{
		case '~':
			application->SetColor(Color(0, 0, 255, 255));
			break;
		case 'M':
		case 'V':
		case 'X':
			application->SetColor(Color(0, 255, 0, 255));
			break;
		case 'O':
			application->SetColor(Color(128, 128, 128, 255));
			break;
		default:
			break;
	}
	if (visited_)
		application->SetColor(Color(0, 100, 0, 255));
	if(shortPath_)
		application->SetColor(Color(255, 255, 0, 255));
	application->DrawRect(xPosition_, yPosition_, 20, 20, true);
}

void Vertex::setVisited(bool visited)
{
	visited_ = visited;
}

bool Vertex::visited()
{
	return visited_;
}

void Vertex::setShortPath(bool shortPath)
{
	shortPath_ = shortPath;
}

void Vertex::addVisitor()
{
	visitors_++;
}

void Vertex::removeVisitor()
{
	visitors_--;
}

int Vertex::getVisitors()
{
	return visitors_;
}
