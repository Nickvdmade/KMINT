#pragma once
#include "Rabbit.h"
#include "RandomGenerator.h"
#include "Map.h"
#include <chrono>

class RabbitPopulation
{
public:
	RabbitPopulation(int size);
	~RabbitPopulation();
	void createFirstGeneration(Map* map);
	void show(FWApplication* application);
	void update(Rottweiler* dog);
	std::vector<Rabbit*> getPopulation() const;
	int getDrowned() const;
	int getEaten() const;
	void killRabbit(Rabbit* rabbit, std::string cause);
	void nextGeneration();
	int getGeneration() const;
	Rabbit* findRabbit(Vertex* position);

private:
	void createRandomGeneration();
	void place();
	Rabbit* findClosestRabbit(Vertex* position);
	static Vertex* findClosestWater(Vertex* position);

	int size_;
	int drowned_;
	int eaten_;
	int generation_;
	//std::vector<Rabbit*> previousPopulation_; //use for selecting parents for new population
	std::vector<Rabbit*> population_;
	std::vector<Vertex*> mapVertices_;
	double stepSpeed_;
	std::chrono::system_clock::time_point stepTime_;
	std::chrono::duration<double> stepTimer_;
};

