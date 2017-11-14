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

void Cow::Draw()
{
	application_->DrawTexture(texture_, 0, 0);
}
