#pragma once
#include "FWApplication.h"
#include "Vertex.h"
#include "StatesEnum.h"

class Rottweiler
{
public:
	Rottweiler(Vertex* start);
	~Rottweiler();
	void setPosition(Vertex* position);
	void show(FWApplication* application) const;
	void updateState();

private:
	void initialize();

	Vertex* position_;
	Vertex* cave_;
	int width_;
	int height_;
	States currentState_;
	States previousState_;
};

