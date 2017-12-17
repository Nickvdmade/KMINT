#pragma once
#include "Person.h"

class Misses : public Person
{
public:
	Misses(const char name, const Color colour, const int minWater, const int maxWater, Vertex* start);
	~Misses();
	void updateState();

private:
	void initialize();

	States currentState_;
	States previousState_;
};
