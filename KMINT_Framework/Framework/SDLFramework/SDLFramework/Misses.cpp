#include "Misses.h"
#include "Edge.h"

Misses::Misses(const char name, const Color colour, const int minWater, const int maxWater, Vertex* start, const int stepDuration) : Person()
{
	name_ = name;
	colour_ = colour;
	minWater_ = minWater;
	maxWater_ = maxWater;
	currentState_ = init;
	position_ = start;
	inState_ = false;
	stepSpeed_ = stepDuration * 2;
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

bool Misses::canSeeRabbit() const
{
	if (position_->getVisitors() > 0)
		return true;
	for (Edge* edge : position_->GetEdges())
		if (edge->GetOther(position_)->getVisitors() > 0)
			return true;
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

