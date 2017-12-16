#include "Rottweiler.h"

Rottweiler::Rottweiler()
	: position_(nullptr)
{
	width_ = 10;
	height_ = 10;
	currentState_ = init;
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

		break;
	case hunt:
		
		break;
	case eat:

		break;
	case checkThirst:

		break;
	case thirsty:
		
		break;
	case findPerson:

		break;
	case drink:

		break;
	case sleep:

		break;
	}
}

void Rottweiler::initialize()
{
	previousState_ = currentState_;
	currentState_ = wander;
}
