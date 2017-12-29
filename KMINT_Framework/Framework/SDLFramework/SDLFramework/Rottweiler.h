#pragma once
#include "FWApplication.h"
#include "Vertex.h"
#include "StatesEnum.h"
#include "Person.h"
#include "Rabbit.h"
#include "Astar.h"
#include <chrono>

class RabbitPopulation;

class Rottweiler
{
public:
	Rottweiler(Vertex* start, std::vector<Person*> owners, const int stepDuration);
	~Rottweiler();
	void setPosition(Vertex* position);
	Vertex* getPosition() const;
	void show(FWApplication* application) const;
	std::string currentState() const;	
	void updateState();
	void raiseThirst();
	int thirstLevel() const;
	void setPreyPopulation(RabbitPopulation* preyPopulation);

private:
	void initialize();
	void startState();
	bool canSeePrey();
	bool canEatPrey();
	void setPrey(Vertex* position);
	void wandering();
	void drinkWater();
	void checkThirstLevel();
	void findFavouriteOwner();
	void huntPrey();
	void eatPrey();
	void findCave();
	int getWaterFromFavouriteOwner();
	void calculateFavouriteOwner();
	void takeRandomStep();
	void takeStep();
	void clearPath();

	Vertex* position_;
	Vertex* cave_;
	int width_;
	int height_;
	int thirst_;
	int timesDrunk_;
	States currentState_;
	States previousState_;

	std::vector<Person*> owners_;
	int favourite_;
	RabbitPopulation* rabbitPopulation_;
	Rabbit* prey_;
	std::stack<Edge*> path_;

	RandomGenerator random;
	Astar astar;

	bool inState_;
	double stepSpeed_;
	std::chrono::system_clock::time_point stepTime_;
	std::chrono::duration<double> stepTimer_;
};

