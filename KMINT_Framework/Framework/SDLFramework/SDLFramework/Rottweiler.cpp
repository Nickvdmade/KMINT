#include "Rottweiler.h"
#include "RabbitPopulation.h"

Rottweiler::Rottweiler(Vertex* start, const std::vector<Person*> owners, const int stepDuration)
	: position_(start)
	, cave_(start)
	, owners_(owners)
{
	width_ = 10;
	height_ = 10;
	thirst_ = 0;
	currentState_ = init;
	stepSpeed_ = stepDuration;
	timesDrunk_ = 0;
	calculateFavouriteOwner();
}

Rottweiler::~Rottweiler()
{
}

void Rottweiler::setPosition(Vertex* position)
{
	position_ = position;
}

Vertex* Rottweiler::getPosition() const
{
	return position_;
}

void Rottweiler::show(FWApplication* application) const
{
	const int xPos = position_->GetX() + 5;
	const int yPos = position_->GetY() + 5;
	application->SetColor(Color(139, 69, 19, 255));
	application->DrawRect(xPos, yPos, width_, height_, true);
}

std::string Rottweiler::currentState() const
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
		{
			if (favourite_ == 0)
				return "looking for meneer Janssen";
			else
				return "looking for mevrouw Janssen";
		}
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
	{
		if (favourite_ == 0)
			return "looking for meneer Janssen";
		else
			return "looking for mevrouw Janssen";
	}
	if (currentState_ == drink)
		return "drinking";
	if (currentState_ == goToSleep)
		return "going to sleep";
	return "";
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
		if (!inState_)
			startState();
		else
			huntPrey();
		break;
	case eat:
		eatPrey();
		break;
	case checkThirst:
		checkThirstLevel();
		break;
	case findPerson:
		if (!inState_)
			startState();
		else
			findFavouriteOwner();
		break;
	case drink:
		drinkWater();
		break;
	case goToSleep:
		if (!inState_)
			startState();
		else
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

int Rottweiler::thirstLevel() const
{
	return thirst_;
}

void Rottweiler::setPreyPopulation(RabbitPopulation* preyPopulation)
{
	rabbitPopulation_ = preyPopulation;
}

void Rottweiler::initialize()
{
	astar.clearVisited();
	previousState_ = currentState_;
	currentState_ = wander;
	thirst_ = 99;
	timesDrunk_ = 1;
}

void Rottweiler::startState()
{
	stepTime_ = std::chrono::system_clock::now();
	inState_ = true;
}

bool Rottweiler::canSeePrey()
{
	for (Edge* edge : position_->GetEdges())
	{
		Vertex* other = edge->GetOther(position_);
		if (other->getVisitors() > 0)
		{
			setPrey(other);
			return true;
		}
		for (Edge* otherEdge : other->GetEdges())
		{
			Vertex* another = otherEdge->GetOther(other);
			if (another->getVisitors() > 0)
			{
				setPrey(another);
				return true;
			}
		}
	}
	return false;
}

bool Rottweiler::canEatPrey()
{
	if (position_->getVisitors() > 0)
	{
		setPrey(position_);
		return true;
	}
	/*for (Edge* edge : position_->GetEdges())
	{
		Vertex* other = edge->GetOther(position_);
		if (other->getVisitors() > 0)
		{
			setPrey(other);
			return true;
		}
	}*/
	return false;
}

void Rottweiler::setPrey(Vertex * position)
{
	if (prey_ != nullptr)
		prey_->setHunted(false);
	prey_ = rabbitPopulation_->findRabbit(position);
	if (prey_ != nullptr)
		prey_->setHunted(true);
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
		takeRandomStep();
	}
	previousState_ = currentState_;
	currentState_ = checkThirst;
}

void Rottweiler::drinkWater()
{
	if (canEatPrey())
	{
		previousState_ = currentState_;
		currentState_ = eat;
	}

	thirst_ -= getWaterFromFavouriteOwner();
	for (int i = 0; i < path_.size(); i++)
		path_.pop();

	previousState_ = currentState_;
	if (++timesDrunk_ == 2)
		currentState_ = goToSleep;
	else if (canSeePrey())
		currentState_ = hunt;
	else
		currentState_ = wander;
}

void Rottweiler::checkThirstLevel()
{
	if (thirst_ == 100)
	{
		if (prey_ != nullptr)
			prey_->setHunted(false);
		currentState_ = findPerson;
	}
	else
		currentState_ = previousState_;
	previousState_ = checkThirst;
}

void Rottweiler::findFavouriteOwner()
{
	if (canEatPrey())
	{
		previousState_ = currentState_;
		currentState_ = eat;
	}
	if (position_ == owners_[favourite_]->getPosition())
	{
		clearPath();
		previousState_ = currentState_;
		currentState_ = drink;
		inState_ = false;
	}
	else
	{
		if (path_.empty())
				path_ = astar.Search(position_, owners_[favourite_]->getPosition());
		else
			takeStep();
	}
}

void Rottweiler::huntPrey()
{
	if (!prey_->isDead())
	{
		if (position_ == prey_->getPosition())
		{
			clearPath();
			previousState_ = currentState_;
			currentState_ = eat;
			inState_ = false;
		}
		else if (canEatPrey())
		{
			clearPath();
			previousState_ = currentState_;
			currentState_ = eat;
			inState_ = false;
		}
		else
		{
			if (path_.empty())
				path_ = astar.Search(position_, prey_->getPosition());
			else
				takeStep();
		}
	}
	else
	{
		clearPath();
		previousState_ = currentState_;
		currentState_ = wander;
		inState_ = false;
	}
	previousState_ = currentState_;
	currentState_ = checkThirst;
}

void Rottweiler::eatPrey()
{
	rabbitPopulation_->killRabbit(prey_, "eaten");
	if (previousState_ == checkThirst)
	{
		previousState_ = currentState_;
		if (canSeePrey())
			currentState_ = hunt;
		else
			currentState_ = wander;
	}
	else
	{
		currentState_ = previousState_;
		previousState_ = eat;
	}
}

void Rottweiler::findCave()
{
	if (canEatPrey())
	{
		previousState_ = currentState_;
		currentState_ = eat;
	}
	if (position_ == cave_)
	{
		previousState_ = currentState_;
		currentState_ = init;
		inState_ = false;
	}
	else
	{
		if (path_.empty())
			path_ = astar.Search(position_, cave_);
		else
			takeStep();
	}
}

int Rottweiler::getWaterFromFavouriteOwner()
{
	const int water = owners_[favourite_]->giveWaterAmount();
	calculateFavouriteOwner();
	return water;
}

void Rottweiler::calculateFavouriteOwner()
{
	favourite_ = random.GetRandomNumber(0, owners_.size() - 1);
}

void Rottweiler::takeRandomStep()
{
	stepTimer_ = std::chrono::system_clock::now() - stepTime_;
	if (stepTimer_.count() >= stepSpeed_)
	{
		position_ = position_->Move();
		stepTime_ = std::chrono::system_clock::now();
	}
}

void Rottweiler::takeStep()
{
	stepTimer_ = std::chrono::system_clock::now() - stepTime_;
	if (stepTimer_.count() >= stepSpeed_)
	{
		Edge* edge = path_.top();
		path_.pop();
		position_ = edge->GetOther(position_);
		stepTime_ = std::chrono::system_clock::now();
	}
}

void Rottweiler::clearPath()
{
	astar.clearVisited();
	while (!path_.empty())
		path_.pop();
}
