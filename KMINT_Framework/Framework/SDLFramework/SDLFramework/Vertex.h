#pragma once
class Vertex
{
public:
	Vertex(int, int);
	~Vertex();

	const int getX();
	const int getY();

private:
	int xPosition_;
	int yPosition_;
};

