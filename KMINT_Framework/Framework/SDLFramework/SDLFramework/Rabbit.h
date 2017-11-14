#pragma once
#include "FWApplication.h"
class Rabbit
{
public:
	Rabbit(FWApplication*);
	~Rabbit();

	void Draw();

private:
	FWApplication* application_;
	SDL_Texture* texture_;
};
