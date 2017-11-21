#include "Rabbit.h"



Rabbit::Rabbit(FWApplication* application, Vertex* vertex)
{
	application_ = application;
	texture_ = application_->LoadTexture("rabbit-3.png");
	position_ = vertex;
}


Rabbit::~Rabbit()
{
	application_->RemoveTexture(texture_);
}

void Rabbit::Draw()
{
	application_->DrawTexture(texture_, position_->GetX(), position_->GetY(), 30, 30);
}

void Rabbit::Move(Vertex* vertex)
{
	position_ = vertex;
}

int Rabbit::GetPositionID()
{
	return position_->GetIndex();
}

Vertex * Rabbit::GetPosition()
{
	return position_;
}
