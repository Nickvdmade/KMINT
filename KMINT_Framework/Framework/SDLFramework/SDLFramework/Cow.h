#pragma once
#include "FWApplication.h"
#include "Vertex.h"
class Cow
{
public:
	Cow(FWApplication*, Vertex*);
	~Cow();

	void Draw();
	void Mooove();
	int GetPositionID();
	Vertex* GetPosition();
	void MoveToRabbit(Vertex* vertex);

private:
	Vertex* position_;
	FWApplication* application_;
	SDL_Texture* texture_;
};

