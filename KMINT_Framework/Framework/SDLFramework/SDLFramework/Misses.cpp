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
	inState_ = false;
	stepSpeed_ = 2;
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
		if (!inState_)
			startState();
		else
			wandering();
		break;
	case scared:
		standStill();
		break;
	case giveWater:

		break;
	default:
		break;
	}
}

void Misses::standStill()
{
	if (!canSeeRabbit())
	{
		currentState_ = previousState_;
		previousState_ = scared;
	}
}

bool Misses::canSeeRabbit()
{
	return false;
}

void Misses::wandering()
{
	if (canSeeRabbit())
	{
		previousState_ = currentState_;
		currentState_ = scared;
		inState_ = false;
	}
	else
	{
		stepTimer_ = std::chrono::system_clock::now() - stepTime_;
		if (stepTimer_.count() >= stepSpeed_)
		{
			moveRandom();
			stepTime_ = std::chrono::system_clock::now();
		}
	}
}

