#pragma once
#include "Rabbit.h"
#include "RandomGenerator.h"
#include "Rottweiler.h"

class RabbitPopulation
{
public:
	RabbitPopulation(int size);
	~RabbitPopulation();
	void initialize();
	std::vector<Rabbit*> get();
	void show(FWApplication* application);
	void update();
	int getDrowned();
	int getEaten();
	void killRabbit(Rabbit* rabbit, std::string cause);
private:
	int size_;
	int drowned_;
	int eaten_;
	std::vector<Rabbit*> population_;
};

