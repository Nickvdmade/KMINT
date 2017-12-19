#pragma once
#include "FWApplication.h"
#include "Vertex.h"
#include "StatesEnum.h"
#include <chrono>
#include <ctime>

class Person
{
public:
	Person();
	~Person();
	void setPosition(Vertex* position);
	char getName();
	void show(FWApplication* application) const;
	void moveRandom();
	virtual void updateState();

protected:
	void initialize();
	void startState();
	virtual void wandering();

	Vertex* position_;
	Vertex* startPosition_;
	int minWater_;
	int maxWater_;
	int width_;
	int heigth_;
	char name_;
	Color colour_;

	States currentState_;
	States previousState_;

	bool inState_;
	double stepSpeed_;
	std::chrono::system_clock::time_point totalTime_;
	std::chrono::duration<double> totalTimer_;
	std::chrono::system_clock::time_point stepTime_;
	std::chrono::duration<double> stepTimer_;
};

