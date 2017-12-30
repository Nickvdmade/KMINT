#include "RabbitPopulation.h"
#include <queue>

RabbitPopulation::RabbitPopulation(const int size)
	: size_(size)
	, drowned_(0)
	, eaten_(0)
	, generation_(0)
	, dieOrder_(0)
{
	stepSpeed_ = 2;
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
	stepTime_ = std::chrono::system_clock::now();
}

Rabbit* RabbitPopulation::findClosestRabbit(Vertex* position)
{
	for (Edge* edge : position->GetEdges())
	{
		Vertex* other = edge->GetOther(position);
		if (other->getVisitors() > 0)
		{
			return findRabbit(other);
		}
		for (Edge* otherEdge : other->GetEdges())
		{
			Vertex* another = otherEdge->GetOther(other);
			if (another->getVisitors() > 0)
			{
				return findRabbit(another);
			}
		}
	}
	return nullptr;
}

Vertex* RabbitPopulation::findClosestWater(Vertex* position)
{
	for (Edge* edge : position->GetEdges())
	{
		Vertex* other = edge->GetOther(position);
		if (other->getType() == '~')
		{
			return other;
		}
		for (Edge* otherEdge : other->GetEdges())
		{
			Vertex* another = otherEdge->GetOther(other);
			if (another->getType() == '~')
			{
				return another;
			}
		}
	}
	return nullptr;
}

void RabbitPopulation::update(Rottweiler* dog)
{
	stepTimer_ = std::chrono::system_clock::now() - stepTime_;
	if (stepTimer_.count() >= stepSpeed_)
	{
		Vertex* newPosition;
		Vertex* currentPosition;
		for (Rabbit* rabbit : population_)
		{
			if (!rabbit->isDead())
			{
				currentPosition = rabbit->getPosition();
				rabbit->calculateHeading(findClosestRabbit(rabbit->getPosition()), dog, findClosestWater(rabbit->getPosition()));
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
				if (newPosition->getType() == '~')
					killRabbit(rabbit, "drowned");
				else
					rabbit->move(newPosition);
			}
		}
		stepTime_ = std::chrono::system_clock::now();
	}
}

std::vector<Rabbit*> RabbitPopulation::getPopulation() const
{
	return population_;
}

int RabbitPopulation::getDrowned() const
{
	return drowned_;
}

int RabbitPopulation::getEaten() const
{
	return eaten_;
}

void RabbitPopulation::killRabbit(Rabbit * rabbit, const std::string cause)
{
	if (cause == "eaten")
		eaten_++;
	else if (cause == "drowned")
		drowned_++;
	rabbit->die(cause, ++dieOrder_);
}

void RabbitPopulation::nextGeneration()
{
	generation_++;
	//select parents
	auto parents = selectParents();
	//create the new generation from parents
	createChildren(parents);
	//every second generation mutate 5% of the population
	if (generation_ % 2 == 0)
		mutatePopulation(size_ / 20);
	//place new generation on map
	place();
	eaten_ = 0;
	drowned_ = 0;
	dieOrder_= 0;
}

int RabbitPopulation::getGeneration() const
{
	return generation_;
}

Rabbit* RabbitPopulation::findRabbit(Vertex* position)
{
	for (Rabbit* rabbit : population_)
	{
		if (rabbit->getPosition() == position)
		{
			return rabbit;
		}
	}
	return nullptr;
}

std::vector<Rabbit*> RabbitPopulation::selectParents()
{
	std::vector<Rabbit*> fitParents;
	std::vector<Rabbit*> unfitParents;
	//select half of population size as fit parents based on living rabbits, and longest living rabbits
	for (Rabbit* rabbit : population_)
	{
		if (!rabbit->isDead())
			fitParents.push_back(rabbit);
		else if (rabbit->getDieOrder() > size_ / 2)
			fitParents.push_back(rabbit);
		else
			unfitParents.push_back(rabbit);
	}
	population_.clear();
	//add 10% of population of random unfitParents to fitParents
	for (int i = 0; i < size_ / 10; i++)
	{
		int index = random.GetRandomNumber(0, unfitParents.size() - 1);
		fitParents.push_back(unfitParents[index]);
	}
	unfitParents.clear();
	return fitParents;
}

void RabbitPopulation::createChildren(std::vector<Rabbit*> parents)
{	
	for (int i = 0; i < size_; i++)
	{
		//get chromosone of 2 random different parents 
		int mother = random.GetRandomNumber(0, parents.size() - 1);
		int father = random.GetRandomNumber(0, parents.size() - 1);
		while (father == mother)
			father = random.GetRandomNumber(0, parents.size() - 1);
		std::vector<float> motherChromosone = parents[mother]->getChromosone();
		std::vector<float> fatherChromosone = parents[father]->getChromosone();

		//use crossover to create new child
		float dogAttraction = motherChromosone[0];
		float waterAttraction = motherChromosone[1];
		float cohesion = fatherChromosone[2];
		float separation = fatherChromosone[3];
		float alignment = fatherChromosone[4];
		population_.push_back(new Rabbit(dogAttraction, waterAttraction, cohesion, separation, alignment));
	}
}

void RabbitPopulation::mutatePopulation(int mutations)
{
	//mutate the dog attraction gene from rabbit
	for (int i = 0; i < mutations; i++)
	{
		int index = random.GetRandomNumber(0, size_ - 1);
		population_[index]->setDogAttraction(random.GetRandomFloat(-1.0, 1.0));
	}
}
