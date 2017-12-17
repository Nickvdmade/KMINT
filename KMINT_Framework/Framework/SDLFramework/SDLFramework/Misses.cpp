#include "Misses.h"

Misses::Misses(const char name, const Color colour, const int minWater, const int maxWater, Vertex* start) : Person()
{
	name_ = name;
	colour_ = colour;
	minWater_ = minWater;
	maxWater_ = maxWater;
	currentState_ = init;
	startPosition_ = start;
	position_ = startPosition_;
}

Misses::~Misses()
{
}

void Misses::updateState()
{
	switch (currentState_)
	{
	case init:
		initialize();
		break;
	case wander:

		break;
	case scared:

		break;
	case giveWater:

		break;
	default:
		break;
	}
}

void Misses::initialize()
{
	previousState_ = currentState_;
	currentState_ = wander;
}
