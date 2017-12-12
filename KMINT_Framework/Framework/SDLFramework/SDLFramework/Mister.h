#pragma once
#include "Person.h"

class Mister : public Person
{
public:
	Mister(const char name, const Color colour, const int minWater, const int maxWater);
	~Mister();
};
