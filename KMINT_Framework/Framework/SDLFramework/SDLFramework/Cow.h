#pragma once
#include "FWApplication.h"
#include "Vertex.h"
#include "Astar.h"
#include <stack>

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
	void FindRabbit(Vertex* position);

private:
	Vertex* position_;
	FWApplication* application_;
	SDL_Texture* texture_;
	std::stack<Edge*> route_;
};

