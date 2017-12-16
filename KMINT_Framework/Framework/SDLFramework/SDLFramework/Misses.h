#pragma once
#include "Person.h"

class Misses : public Person
{
public:
	Misses(const char name, const Color colour, const int minWater, const int maxWater);
	~Misses();
	void updateState();

private:
	void initialize();

	MissesStates currentState_;
	MissesStates previousState_;
};

enum MissesStates
{
	init,
	wander,
	scared,
	giveWater
};
