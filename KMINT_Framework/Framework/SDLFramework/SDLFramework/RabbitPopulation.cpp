#include "RabbitPopulation.h"



RabbitPopulation::RabbitPopulation(int size)
	: size_(size)
	, drowned_(0)
	, eaten_(0)
{
}


RabbitPopulation::~RabbitPopulation()
{
	for (Rabbit* rabbit : population_)
		delete rabbit;
}

void RabbitPopulation::initialize()
{
	RandomGenerator random;
	float dogAttraction; 
	float waterAttraction;
	float cohesion;
	float separation;
	float alignment;

	for (int i = 0; i < size_; i++)
	{
		dogAttraction = random.GetRandomFloat(-1.0, 1.0);
		waterAttraction = random.GetRandomFloat(-1.0, 1.0);
		cohesion = random.GetRandomFloat(0, 1.0);
		separation = random.GetRandomFloat(0, 1.0);
		alignment = random.GetRandomFloat(0, 1.0);
		population_.push_back(new Rabbit(dogAttraction, waterAttraction, cohesion, separation, alignment));
	}
}

std::vector<Rabbit*> RabbitPopulation::get()
{
	return population_;
}

void RabbitPopulation::show(FWApplication* application)
{
	for (Rabbit* rabbit : population_)
		rabbit->show(application);
}

void RabbitPopulation::update()
{
	for (Rabbit* rabbit : population_)
		rabbit->update();
}

int RabbitPopulation::getDrowned()
{
	return drowned_;
}

int RabbitPopulation::getEaten()
{
	return eaten_;
}

void RabbitPopulation::killRabbit(Rabbit * rabbit, std::string cause)
{
	if (cause == "eaten")
		eaten_++;
	else if (cause == "drowned")
		drowned_++;
	rabbit->die(cause);
}
