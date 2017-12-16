#include "Misses.h"

Misses::Misses(const char name, const Color colour, const int minWater, const int maxWater) : Person()
{
	name_ = name;
	colour_ = colour;
	minWater_ = minWater;
	maxWater_ = maxWater;
	currentState_ = init;
}

Misses::~Misses()
{
}

void Misses::updateState()
{
	switch (currentState_)
	{
	case init:

		break;
	case wander:

		break;
	case scared:

		break;
	case giveWater:

		break;
	}
}

void Misses::initialize()
{
	previousState_ = currentState_;
	currentState_ = wander;
}
