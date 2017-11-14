#include "Rabbit.h"



Rabbit::Rabbit(FWApplication* application)
{
	application_ = application;
	texture_ = application_->LoadTexture("rabbit-3.png");
}


Rabbit::~Rabbit()
{
	application_->RemoveTexture(texture_);
}

void Rabbit::Draw()
{
	application_->DrawTexture(texture_, 0, 0);
}
