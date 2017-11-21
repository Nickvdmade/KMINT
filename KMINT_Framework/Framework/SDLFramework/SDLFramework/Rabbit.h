#pragma once
#include "FWApplication.h"
#include "Vertex.h"
class Rabbit
{
public:
	Rabbit(FWApplication*, Vertex*);
	~Rabbit();

	void Draw();
	void Move(Vertex*);
	int GetPositionID();
	Vertex* GetPosition();

private:
	Vertex* position_;
	FWApplication* application_;
	SDL_Texture* texture_;
};
