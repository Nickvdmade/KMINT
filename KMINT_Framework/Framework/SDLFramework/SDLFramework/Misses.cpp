#include "Misses.h"

Misses::Misses(const char name, const Color colour, const int minWater, const int maxWater) : Person()
{
	name_ = name;
	colour_ = colour;
	minWater_ = minWater;
	maxWater_ = maxWater;
}

Misses::~Misses()
{
}
