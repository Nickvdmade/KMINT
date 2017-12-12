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
