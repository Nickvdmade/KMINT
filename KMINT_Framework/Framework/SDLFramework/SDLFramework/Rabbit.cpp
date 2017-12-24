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
	height_ = 5;
	dead_ = false;
	xOffset_ = 0;
	yOffset_ = 0;
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
		int xPos = position_->GetX() + xOffset_;
		int yPos = position_->GetY() + yOffset_;
		application->SetColor(Color(255, 255, 255, 255));
		application->DrawRect(xPos, yPos, width_, height_, true);
		application->SetColor(Color(128, 128, 128, 255));
		application->DrawRect(xPos, yPos, width_, height_, false);
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

void Rabbit::calculateOffset()
{
	int visitors = position_->getVisitors();
	xOffset_ = (width_ * (visitors % 4));
	yOffset_ = (height_ * (visitors / 4));
}

std::string Rabbit::causeOfDeath()
{
	return causeOfDeath_;
}
