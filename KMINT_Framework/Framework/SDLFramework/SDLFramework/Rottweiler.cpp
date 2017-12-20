#include "Rottweiler.h"

Rottweiler::Rottweiler(Vertex* start, std::vector<Person*> owners, const int stepDuration)
	: cave_(start)
	, position_(start)
	, owners_(owners)
{
	width_ = 10;
	height_ = 10;
	thirst_ = 0;
	currentState_ = init;
	stepSpeed_ = stepDuration;
	timesDrunk_ = 0;
	preyEaten_ = 0;
	favourite_ = random.GetRandomNumber(0, owners_.size() - 1);
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

std::string Rottweiler::currentState()
{
	if (currentState_ == checkThirst)
	{
		if (previousState_ == init)
			return "round start";
		if (previousState_ == wander)
			return "wandering";
		if (previousState_ == hunt)
			return "huntig wabbits";
		if (previousState_ == eat)
			return "eating";
		if (previousState_ == findPerson)
			return "looking for favourite owner";
		if (previousState_ == drink)
			return "drinking";
		if (previousState_ == goToSleep)
			return "going to sleep";
	}
	if (currentState_ == init)
		return "round start";
	if (currentState_ == wander)
		return "wandering";
	if (currentState_ == hunt)
		return "huntig wabbits";
	if (currentState_ == eat)
		return "eating";
	if (currentState_ == findPerson)
		return "looking for favourite owner";
	if (currentState_ == drink)
		return "drinking";
	if (currentState_ == goToSleep)
		return "going to sleep";
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
		huntPrey();
		break;
	case eat:
		eatPrey();
		break;
	case checkThirst:
		checkThirstLevel();
		break;
	case findPerson:
		findFavouriteOwner();
		break;
	case drink:
		drinkWater();
		break;
	case goToSleep:
		findCave();
		break;
	default:
		break;
	}
}

void Rottweiler::raiseThirst()
{
	if(thirst_ < 100)
		thirst_++;
}

int Rottweiler::thirstLevel()
{
	return thirst_;
}

int Rottweiler::preyEaten()
{
	return preyEaten_;
}

void Rottweiler::initialize()
{
	previousState_ = currentState_;
	currentState_ = wander;
	thirst_ = 0;
	timesDrunk_ = 0;
	preyEaten_ = 0;
}

void Rottweiler::startState()
{
	stepTime_ = std::chrono::system_clock::now();
	inState_ = true;
}

bool Rottweiler::canSeePrey()
{
	return false;
}

bool Rottweiler::canEatPrey()
{
	return false;
}

void Rottweiler::wandering()
{
	if (canSeePrey())
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
			position_ = position_->Move();
			stepTime_ = std::chrono::system_clock::now();
		}
	}
	previousState_ = currentState_;
	currentState_ = checkThirst;
}

void Rottweiler::drinkWater()
{
	thirst_ -= getWaterFromFavouriteOwner();

	previousState_ = currentState_;
	if (++timesDrunk_ == 2)
		currentState_ = goToSleep;
	else if (canEatPrey())
		currentState_ = eat;
	else if (canSeePrey())
		currentState_ = hunt;
	else
		currentState_ = wander;
}

void Rottweiler::checkThirstLevel()
{
	if (thirst_ == 100)
		currentState_ = findPerson;
	else
		currentState_ = previousState_;
	previousState_ = checkThirst;
}

void Rottweiler::findFavouriteOwner()
{

}

void Rottweiler::huntPrey()
{
}

void Rottweiler::eatPrey()
{
	preyEaten_++;
}

void Rottweiler::findCave()
{
}

int Rottweiler::getWaterFromFavouriteOwner()
{	
	int water = owners_[favourite_]->giveWaterAmount();
	calculateFavouriteOwner();

	return water;
}

void Rottweiler::calculateFavouriteOwner()
{
	favourite_ = random.GetRandomNumber(0, owners_.size() - 1);
}

