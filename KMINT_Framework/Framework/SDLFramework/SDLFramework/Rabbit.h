#pragma once
#include "Vertex.h"

class Rabbit
{
public:
	Rabbit(const float dogAttraction, const float waterAttraction, const float cohesion, const float separation, const float alignment);
	~Rabbit();
	void setStartPosition(Vertex* position);
	void show(FWApplication* application) const;
	void update();
	bool isDead();
	std::string causeOfDeath();
	void die(std::string cause);
private:
	void calculateOffset();

	Vertex* position_;
	int width_;
	int height_;
	float dogAttraction_;
	float waterAttraction_;
	float cohesion_;
	float separation_;
	float alignment_;
	bool dead_;
	std::string causeOfDeath_;
	int xOffset_;
	int yOffset_;
};
