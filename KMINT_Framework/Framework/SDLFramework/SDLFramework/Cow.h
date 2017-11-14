#pragma once
#include "FWApplication.h"
class Cow
{
public:
	Cow(FWApplication*);
	~Cow();

	void Draw();

private:
	FWApplication* application_;
	SDL_Texture* texture_;
};

