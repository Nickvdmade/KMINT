#include "Mister.h"

Mister::Mister(const char name, const Color colour, const int minWater, const int maxWater) : Person()
{
	name_ = name;
	colour_ = colour;
	minWater_ = minWater;
	maxWater_ = maxWater;
	currentState_ = init;
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
	}
}

void Mister::initialize()
{
	previousState_ = currentState_;
	currentState_ = wander;
}
