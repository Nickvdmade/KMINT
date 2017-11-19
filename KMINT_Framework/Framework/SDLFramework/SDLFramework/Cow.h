#pragma once
#include "FWApplication.h"
class Cow
{
public:
	Cow(FWApplication*);
	~Cow();

	void Draw(int xPosition, int yPosition);

private:
	FWApplication* application_;
	SDL_Texture* texture_;
};

