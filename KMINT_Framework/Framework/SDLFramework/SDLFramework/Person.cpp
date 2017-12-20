#include "Person.h"

Person::Person()
{
	width_ = 10;
	heigth_ = 10;
}

Person::~Person()
{
}

void Person::setPosition(Vertex* position)
{
	position_ = position;
}

char Person::getName()
{
	return name_;
}

void Person::show(FWApplication* application) const
{
	int xPos = position_->GetX() + 5;
	int yPos = position_->GetY() + 5;
	application->SetColor(colour_);
	application->DrawRect(xPos, yPos, width_, heigth_, true);
}

void Person::moveRandom()
{
	position_ = position_->Move();
}

std::string Person::currentState()
{
	if (currentState_ == init)
		return "round start";
	if (currentState_ == wander)
		return "wandering";
	if (currentState_ == picture)
		return "taking a picture";
	if (currentState_ == scared)
		return "scared";
}

void Person::updateState()
{
}

void Person::initialize()
{
	position_ = startPosition_;
	previousState_ = currentState_;
	currentState_ = wander;
}

void Person::wandering()
{
	
}

int Person::giveWaterAmount()
{
	return random.GetRandomNumber(minWater_, maxWater_);
}

void Person::startState()
{
	totalTime_ = std::chrono::system_clock::now();
	stepTime_ = std::chrono::system_clock::now();
	inState_ = true;
}
