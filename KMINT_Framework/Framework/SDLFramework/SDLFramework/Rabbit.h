#pragma once
#include "Vertex.h"
#include <map>

class Rottweiler;

class Rabbit
{
public:
	Rabbit(const float dogAttraction, const float waterAttraction, const float cohesion, const float separation, const float alignment);
	~Rabbit();
	void setStartPosition(Vertex* position);
	void show(FWApplication* application) const;
	bool isDead() const;
	std::string causeOfDeath() const;
	void die(std::string cause);
	int getHeading() const;
	void move(Vertex* position);
	Vertex* getPosition() const;
	void calculateHeading(Rabbit* closestRabbit, Rottweiler* dog, Vertex* closestWater);
	void setHunted(bool hunted);
private:
	void calculateOffset();
	void calculateDogAttraction(Rottweiler* dog);
	void calculateWaterAttraction(Vertex* waterPosition);
	void calculateCohesion(Vertex* rabbit);
	void calculateSeperation(Vertex* rabbit);
	void calculateAlignment(Rabbit* rabbit);

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
	std::map<int, float> directions_;
};

enum heading 
{
	north,
	east,
	south,
	west
};
