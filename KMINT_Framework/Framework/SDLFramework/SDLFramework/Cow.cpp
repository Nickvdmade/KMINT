#include "Cow.h"



Cow::Cow(FWApplication* application)
{
	application_ = application;
	texture_ = application_->LoadTexture("cow-2.png");
}


Cow::~Cow()
{
	application_->RemoveTexture(texture_);
}

void Cow::Draw(int xPosition, int yPosition)
{
	application_->DrawTexture(texture_, xPosition, yPosition, 30, 30);
}
