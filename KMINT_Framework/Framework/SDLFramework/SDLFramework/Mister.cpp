#include "Mister.h"

Mister::Mister(const char name, const Color colour, const int minWater, const int maxWater, Vertex* start) : Person()
{
	name_ = name;
	colour_ = colour;
	minWater_ = minWater;
	maxWater_ = maxWater;
	currentState_ = init;
	startPosition_ = start;
	position_ = startPosition_;
}

Mister::~Mister()
{
}

void Mister::updateState()
{
	switch (currentState_)
	{
	case init:

		break;
	case wander:

		break;
	case picture:

		break;
	case giveWater:

		break;
	default:
		break;
	}
}

void Mister::initialize()
{
	previousState_ = currentState_;
	currentState_ = wander;
}
