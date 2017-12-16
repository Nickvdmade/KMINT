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
	void updateState();

private:
	void initialize();

	Vertex* position_;
	int width_;
	int height_;
	RottweilerStates currentState_;
	RottweilerStates previousState_;
};

enum RottweilerStates
{
	init,
	wander,
	hunt,
	eat,
	checkThirst,
	thirsty,
	findPerson,
	drink,
	sleep
};
