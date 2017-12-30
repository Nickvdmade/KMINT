#include "Rabbit.h"
#include "Rottweiler.h"
#include <stdlib.h>

Rabbit::Rabbit(const float dogAttraction, const float waterAttraction, const float cohesion, const float separation, const float alignment)
	: position_(nullptr)
	, dogAttraction_(dogAttraction)
	, waterAttraction_(waterAttraction)
	, cohesion_(cohesion)
	, separation_(separation)
	, alignment_(alignment)
{
	width_ = 5;
	height_ = 5;
	dead_ = false;
	xOffset_ = 0;
	yOffset_ = 0;
	hunted_ = false;
	directions_[north] = 0;
	directions_[east] = 0;
	directions_[south] = 0;
	directions_[west] = 0;
}

Rabbit::~Rabbit()
{

}

void Rabbit::setStartPosition(Vertex* position)
{   
	position_ = position;
	calculateOffset();
	position_->addVisitor();
}

void Rabbit::show(FWApplication* application) const
{
	if (!dead_) 
	{
		const int xPos = position_->GetX() + xOffset_;
		const int yPos = position_->GetY() + yOffset_;
		application->SetColor(Color(255, 255, 255, 255));
		application->DrawRect(xPos, yPos, width_, height_, true);
		if (hunted_)
			application->SetColor(Color(255, 0, 0, 255));
		else
			application->SetColor(Color(128, 128, 128, 255));
		application->DrawRect(xPos, yPos, width_, height_, false);
	}
}

bool Rabbit::isDead() const
{
	return dead_;
}

void Rabbit::die(const std::string cause, int order)
{
	dead_ = true;
	causeOfDeath_ = cause;
	dieOrder_ = order;
	position_->removeVisitor();
}

int Rabbit::getHeading() const
{
	return heading_;
}

void Rabbit::calculateOffset()
{
	const int visitors = position_->getVisitors();
	xOffset_ = (width_ * (visitors % 4));
	yOffset_ = (height_ * (visitors / 4));
}

void Rabbit::calculateDogAttraction(Rottweiler* dog)
{
	const int xDifference = dog->getPosition()->GetX() - position_->GetX();
	const int yDifference = dog->getPosition()->GetY() - position_->GetY();
	if (abs(xDifference) > abs(yDifference))
	{
		if (xDifference > 0)
		{
			if (waterAttraction_ > 0)
				directions_[east] += dogAttraction_;
			else if (waterAttraction_ < 0)
				directions_[west] -= dogAttraction_;
		}
		else if (xDifference < 0)
			if (waterAttraction_ > 0)
				directions_[west] += dogAttraction_;
			else if (waterAttraction_ < 0)
				directions_[east] -= dogAttraction_;
	}
	else if (abs(xDifference) < abs(yDifference))
	{
		if (yDifference > 0)
		{
			if (waterAttraction_ > 0)
				directions_[north] += dogAttraction_;
			else if (waterAttraction_ < 0)
				directions_[south] -= dogAttraction_;
		}
		else if (yDifference < 0)
		{
			if (waterAttraction_ > 0)
				directions_[south] += dogAttraction_;
			else if (waterAttraction_ < 0)
				directions_[north] -= dogAttraction_;
		}
	}
	else
	{
		if (xDifference > 0)
		{
			if (waterAttraction_ > 0)
				directions_[east] += dogAttraction_;
			else if (waterAttraction_ < 0)
				directions_[west] -= dogAttraction_;
		}
		else if (xDifference < 0)
		{
			if (waterAttraction_ > 0)
				directions_[west] += dogAttraction_;
			else if (waterAttraction_ < 0)
				directions_[east] -= dogAttraction_;
		}
		if (yDifference > 0)
		{
			if (waterAttraction_ > 0)
				directions_[north] += dogAttraction_;
			else if (waterAttraction_ < 0)
				directions_[south] -= dogAttraction_;
		}
		else if (yDifference < 0)
		{
			if (waterAttraction_ > 0)
				directions_[south] += dogAttraction_;
			else if (waterAttraction_ < 0)
				directions_[north] -= dogAttraction_;
		}
	}
}

void Rabbit::calculateWaterAttraction(Vertex* waterPosition)
{
	const int xDifference = waterPosition->GetX() - position_->GetX();
	const int yDifference = waterPosition->GetY() - position_->GetY();
	if (abs(xDifference) > abs(yDifference))
	{
		if (xDifference > 0)
		{
			if (waterAttraction_ > 0)
				directions_[east] += waterAttraction_;
			else if (waterAttraction_ < 0)
				directions_[west] -= waterAttraction_;
		}
		else if (xDifference < 0)
			if (waterAttraction_ > 0)
				directions_[west] += waterAttraction_;
			else if (waterAttraction_ < 0)
				directions_[east] -= waterAttraction_;
	}
	else if (abs(xDifference) < abs(yDifference))
	{
		if (yDifference > 0)
		{
			if (waterAttraction_ > 0)
				directions_[north] += waterAttraction_;
			else if (waterAttraction_ < 0)
				directions_[south] -= waterAttraction_;
		}
		else if (yDifference < 0)
		{
			if (waterAttraction_ > 0)
				directions_[south] += waterAttraction_;
			else if (waterAttraction_ < 0)
				directions_[north] -= waterAttraction_;
		}
	}
	else
	{
		if (xDifference > 0)
		{
			if (waterAttraction_ > 0)
				directions_[east] += waterAttraction_;
			else if (waterAttraction_ < 0)
				directions_[west] -= waterAttraction_;
		}
		else if (xDifference < 0)
		{
			if (waterAttraction_ > 0)
				directions_[west] += waterAttraction_;
			else if (waterAttraction_ < 0)
				directions_[east] -= waterAttraction_;
		}
		if (yDifference > 0)
		{
			if (waterAttraction_ > 0)
				directions_[north] += waterAttraction_;
			else if (waterAttraction_ < 0)
				directions_[south] -= waterAttraction_;
		}
		else if (yDifference < 0)
		{
			if (waterAttraction_ > 0)
				directions_[south] += waterAttraction_;
			else if (waterAttraction_ < 0)
				directions_[north] -= waterAttraction_;
		}
	}
}

void Rabbit::calculateCohesion(Vertex* rabbit)
{
	const int xDifference = rabbit->GetX() - position_->GetX();
	const int yDifference = rabbit->GetY() - position_->GetY();
	if (abs(xDifference) > abs(yDifference))
	{
		if (xDifference > 0)
			directions_[east] += cohesion_;
		else if (xDifference < 0)
			directions_[west] += cohesion_;
	}
	else if (abs(xDifference) < abs(yDifference))
	{
		if (yDifference > 0)
			directions_[north] += cohesion_;
		else if (yDifference < 0)
			directions_[south] += cohesion_;
	}
	else
	{
		if (xDifference > 0)
			directions_[east] += cohesion_;
		else if (xDifference < 0)
			directions_[west] += cohesion_;
		if (yDifference > 0)
			directions_[north] += cohesion_;
		else if (yDifference < 0)
			directions_[south] += cohesion_;
	}
}

void Rabbit::calculateSeperation(Vertex* rabbit)
{
	const int xDifference = rabbit->GetX() - position_->GetX();
	const int yDifference = rabbit->GetY() - position_->GetY();
	if (abs(xDifference) > abs(yDifference))
	{
		if (xDifference > 0)
			directions_[west] += separation_;
		else if (xDifference < 0)
			directions_[east] += separation_;
	}
	else if (abs(xDifference) < abs(yDifference))
	{
		if (yDifference > 0)
			directions_[south] += separation_;
		else if (yDifference < 0)
			directions_[north] += separation_;
	}
	else
	{
		if (xDifference > 0)
			directions_[west] += separation_;
		else if (xDifference < 0)
			directions_[east] += separation_;
		if (yDifference > 0)
			directions_[south] += separation_;
		else if (yDifference < 0)
			directions_[north] += separation_;
	}
}

void Rabbit::calculateAlignment(Rabbit* rabbit)
{
	directions_[rabbit->getHeading()] += alignment_;
}

void Rabbit::calculateHeading(Rabbit* closestRabbit, Rottweiler* dog, Vertex* closestWater)
{
	directions_[north] = 0;
	directions_[east] = 0;
	directions_[south] = 0;
	directions_[west] = 0;
	calculateDogAttraction(dog);
	if (closestWater != nullptr)
		calculateWaterAttraction(closestWater);
	if (closestRabbit != nullptr)
	{
		calculateCohesion(closestRabbit->getPosition());
		calculateSeperation(closestRabbit->getPosition());
		calculateAlignment(closestRabbit);
	}

	float weight = 0;
	for (auto it = directions_.begin(); it != directions_.end(); it++)
	{
		if (it->second > weight)
		{
			weight = it->second;
			heading_ = it->first;
		}
	}
}

void Rabbit::setHunted(const bool hunted)
{
	hunted_ = hunted;
}

std::vector<float> Rabbit::getChromosone()
{
	std::vector<float> chromosone;
	chromosone.push_back(dogAttraction_);
	chromosone.push_back(waterAttraction_);
	chromosone.push_back(cohesion_);
	chromosone.push_back(separation_);
	chromosone.push_back(alignment_);
	return chromosone;
}

int Rabbit::getDieOrder()
{
	return dieOrder_;
}

void Rabbit::setDogAttraction(float dogAttraction)
{
	dogAttraction_ = dogAttraction;
}

void Rabbit::move(Vertex* position)
{
	if (position->getVisitors() < 16)
	{
		position_->removeVisitor();
		position_ = position;
		calculateOffset();
		position_->addVisitor();
	}
}

Vertex * Rabbit::getPosition() const
{
	return position_;
}

std::string Rabbit::causeOfDeath() const
{
	return causeOfDeath_;
}
