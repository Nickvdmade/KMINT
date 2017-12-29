#pragma once
#include "Person.h"

class Misses : public Person
{
public:
	Misses(const char name, const Color colour, const int minWater, const int maxWater, Vertex* start, const int stepDuration);
	~Misses();
	void updateState() override;

private:
	void standStill();
	bool canSeeRabbit() const;
	void wandering() override;
};
