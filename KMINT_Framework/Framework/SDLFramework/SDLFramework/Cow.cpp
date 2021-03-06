#include "Cow.h"

Cow::Cow(FWApplication* application, Vertex* vertex)
{
	application_ = application;
	texture_ = application_->LoadTexture("cow-2.png");
	position_ = vertex;
}

Cow::~Cow()
{
	application_->RemoveTexture(texture_);
}

void Cow::Draw()
{
	application_->DrawTexture(texture_, position_->GetX(), position_->GetY(), 30, 30);
}

void Cow::Mooove()
{
	//position_ = position_->Move();
	if (!route_.empty())
	{
		Edge* direction = route_.top();
		route_.pop();
		position_ = direction->GetOther(position_);
	}
}

int Cow::GetPositionID()
{
	return position_->GetIndex();
}

Vertex * Cow::GetPosition()
{
	return position_;
}

void Cow::MoveToRabbit(Vertex* vertex)
{
	position_ = vertex;
}

void Cow::FindRabbit(Vertex* position)
{
	Astar astar;
	route_ = astar.Search(position_, position);
}
