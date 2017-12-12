#pragma once
#include "Vertex.h"

class Rabbit
{
public:
	Rabbit(const float dogAttraction, const float waterAttraction, const float cohesion, const float separation, const float alignment);
	~Rabbit();
	void setPosition(Vertex* position);
	void show(FWApplication* application) const;

private:
	Vertex* position_;
	int width_;
	int heigth_;
	float dogAttraction_;
	float waterAttraction_;
	float cohesion_;
	float separation_;
	float alignment_;
};
