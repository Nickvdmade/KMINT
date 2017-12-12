#pragma once
#include "FWApplication.h"
#include "Vertex.h"

class Rottweiler
{
public:
	Rottweiler();
	~Rottweiler();
	void setPosition(Vertex* position);
	void show(FWApplication* application) const;

private:
	Vertex* position_;
	int width_;
	int height_;
};

