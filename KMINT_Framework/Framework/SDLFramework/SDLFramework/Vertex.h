#pragma once
class Vertex
{
public:
	Vertex(const int, const int);
	~Vertex();

	int GetX() const;
	int GetY() const;
	void SetIndex(const int index);
	int GetIndex() const;

private:
	int index_;
	int xPosition_;
	int yPosition_;
};

