#include "Rottweiler.h"

Rottweiler::Rottweiler(Vertex* start)
	: cave_(start)
	, position_(start)
{
	width_ = 10;
	height_ = 10;
	currentState_ = init;
	stepSpeed_ = 1;
}

Rottweiler::~Rottweiler()
{
}

void Rottweiler::setPosition(Vertex* position)
{
	position_ = position;
}

void Rottweiler::show(FWApplication* application) const
{
	int xPos = position_->GetX() + 5;
	int yPos = position_->GetY() + 5;
	application->SetColor(Color(139, 69, 19, 255));
	application->DrawRect(xPos, yPos, width_, height_, true);
}

void Rottweiler::updateState()
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
	case hunt:
		
		break;
	case eat:

		break;
	case checkThirst:

		break;
	case findPerson:

		break;
	case drink:

		break;
	case goToSleep:

		break;
	default:
		break;
	}
}

void Rottweiler::initialize()
{
	previousState_ = currentState_;
	currentState_ = wander;
}

void Rottweiler::startState()
{
	totalTime_ = std::chrono::system_clock::now();
	stepTime_ = std::chrono::system_clock::now();
	inState_ = true;
}

bool Rottweiler::canSeeRabbit()
{
	return false;
}

void Rottweiler::wandering()
{
	if (canSeeRabbit())
	{
		previousState_ = currentState_;
		currentState_ = hunt;
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

void Rottweiler::moveRandom()
{
	position_ = position_->Move();
}
