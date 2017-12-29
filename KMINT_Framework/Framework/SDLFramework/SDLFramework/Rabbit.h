#pragma once
#include "Vertex.h"
#include <chrono>
#include <ctime>

class Rabbit
{
public:
	Rabbit(const float dogAttraction, const float waterAttraction, const float cohesion, const float separation, const float alignment);
	~Rabbit();
	void setStartPosition(Vertex* position);
	void show(FWApplication* application) const;
	bool isDead();
	std::string causeOfDeath();
	void die(std::string cause);
	int getHeading();
	void move(Vertex* position);
	Vertex* getPosition();
	void calculateHeading();
	void setHunted(bool hunted);
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
	int heading_;
	bool hunted_;
};

enum heading 
{
	north,
	east,
	south,
	west
};
