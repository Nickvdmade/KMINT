#pragma once
#include "Person.h"

class Mister : public Person
{
public:
	Mister(const char name, const Color colour, const int minWater, const int maxWater);
	~Mister();
	void updateState();

private:
	void initialize();

	MisterStates currentState_;
	MisterStates previousState_;
};

enum MisterStates
{
	init,
	wander,
	picture,
	giveWater
};
