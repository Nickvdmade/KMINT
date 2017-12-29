#pragma once
#include "Rabbit.h"
#include "RandomGenerator.h"
#include "Map.h"

class RabbitPopulation
{
public:
	RabbitPopulation(int size);
	~RabbitPopulation();
	void createFirstGeneration(Map* map);
	void show(FWApplication* application);
	void update();
	std::vector<Rabbit*> getPopulation();
	int getDrowned();
	int getEaten();
	void killRabbit(Rabbit* rabbit, std::string cause);
	void nextGeneration();
	int getGeneration();
private:
	void createRandomGeneration();
	void place();

	int size_;
	int drowned_;
	int eaten_;
	int generation_;
	//std::vector<Rabbit*> previousPopulation_; //use for selecting parents for new population
	std::vector<Rabbit*> population_;
	std::vector<Vertex*> mapVertices_;
};

