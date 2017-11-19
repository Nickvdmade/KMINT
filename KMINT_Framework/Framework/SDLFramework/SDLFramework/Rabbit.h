#pragma once
#include "FWApplication.h"
class Rabbit
{
public:
	Rabbit(FWApplication*);
	~Rabbit();

	void Draw(int xPosition, int yPosition);

private:
	FWApplication* application_;
	SDL_Texture* texture_;
};
