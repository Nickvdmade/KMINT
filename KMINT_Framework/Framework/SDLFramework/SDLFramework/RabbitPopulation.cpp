#include "RabbitPopulation.h"

RabbitPopulation::RabbitPopulation(int size)
	: size_(size)
	, drowned_(0)
	, eaten_(0)
	, generation_(0)
{
}


RabbitPopulation::~RabbitPopulation()
{
	for (Rabbit* rabbit : population_)
		delete rabbit;
}

void RabbitPopulation::createFirstGeneration(Map* map)
{
	mapVertices_ = map->getVertices();
	createRandomGeneration();
	place();
}

void RabbitPopulation::createRandomGeneration()
{
	generation_++;
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

void RabbitPopulation::show(FWApplication* application)
{
	for (Rabbit* rabbit : population_)
		rabbit->show(application);
}

void RabbitPopulation::place()
{
	RandomGenerator random;
	for (Rabbit* rabbit : population_)
	{
		Vertex* position = mapVertices_[0];
		while (position->getType() != 'X')
		{
			position = mapVertices_[random.GetRandomNumber(0, mapVertices_.size() - 1)];
			while (position->getVisitors() > 15)
				position = mapVertices_[random.GetRandomNumber(0, mapVertices_.size() - 1)];
		}
		rabbit->setStartPosition(position);
	}
}

void RabbitPopulation::update()
{
	Vertex* newPosition;
	Vertex* currentPosition;
	for (Rabbit* rabbit : population_)
	{
		if (!rabbit->isDead())
		{
			currentPosition = rabbit->getPosition();
			if (currentPosition->getType() == '~') 
				killRabbit(rabbit, "drowned");
			else
			{
				rabbit->calculateHeading();
				switch (rabbit->getHeading())
				{
				case north:
					newPosition = mapVertices_[currentPosition->GetIndex() - 64];
					break;
				case east:
					newPosition = mapVertices_[currentPosition->GetIndex() + 1];
					break;
				case south:
					newPosition = mapVertices_[currentPosition->GetIndex() + 64];
					break;
				case west:
					newPosition = mapVertices_[currentPosition->GetIndex() - 1];
					break;
				default:
					newPosition = currentPosition;
					break;
				}
				rabbit->move(newPosition);
			}
		}
	}
}

std::vector<Rabbit*> RabbitPopulation::getPopulation()
{
	return population_;
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

void RabbitPopulation::nextGeneration()
{
	//previousPopulation_ = population_;
	for (Rabbit* rabbit : population_)
		delete rabbit;
	population_.clear();
	createRandomGeneration();
	place();
	eaten_ = 0;
	drowned_ = 0;
}

int RabbitPopulation::getGeneration()
{
	return generation_;
}
