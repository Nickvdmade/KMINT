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
	inState_ = false;
	stepSpeed_ = 2;
}

Mister::~Mister()
{
}

void Mister::updateState()
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
	case picture:
		if (!inState_)
			startState();
		else
			takePicture();
		break;
	case giveWater:

		break;
	default:
		break;
	}
}

void Mister::takePicture()
{
	totalTimer_ = std::chrono::system_clock::now() - totalTime_;
	if (totalTimer_.count() >= 10)
	{
		inState_ = false;
		previousState_ = currentState_;
		currentState_ = wander;
	}
}

void Mister::wandering()
{
	totalTimer_ = std::chrono::system_clock::now() - totalTime_;
	if (totalTimer_.count() >= 20)
	{
		inState_ = false;
		previousState_ = currentState_;
		currentState_ = picture;
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
