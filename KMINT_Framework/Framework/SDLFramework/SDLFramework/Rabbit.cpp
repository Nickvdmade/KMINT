#include "Rabbit.h"

Rabbit::Rabbit(const float dogAttraction, const float waterAttraction, const float cohesion, const float separation, const float alignment)
	: position_(nullptr)
	, dogAttraction_(dogAttraction)
	, waterAttraction_(waterAttraction)
	, cohesion_(cohesion)
	, separation_(separation)
	, alignment_(alignment)
{
	width_ = 5;
	heigth_ = 5;
	dead_ = false;
}

Rabbit::~Rabbit()
{

}

void Rabbit::setPosition(Vertex* position)
{
	position_ = position;
}

void Rabbit::show(FWApplication* application) const
{
	if (!dead_) 
	{
		int xPos = position_->GetX() + 7;
		int yPos = position_->GetY() + 7;
		application->SetColor(Color(255, 255, 255, 255));
		application->DrawRect(xPos, yPos, width_, heigth_, true);
	}
}

void Rabbit::update()
{
	//update
}

bool Rabbit::isDead()
{
	return dead_;
}

void Rabbit::die(std::string cause)
{
	dead_ = true;
	causeOfDeath_ = cause;
}

std::string Rabbit::causeOfDeath()
{
	return causeOfDeath_;
}
