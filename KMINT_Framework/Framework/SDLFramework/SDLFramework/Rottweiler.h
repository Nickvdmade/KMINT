#pragma once
#include "FWApplication.h"
#include "Vertex.h"
#include "StatesEnum.h"
#include <chrono>
#include <ctime>

class Rottweiler
{
public:
	Rottweiler(Vertex* start);
	~Rottweiler();
	void setPosition(Vertex* position);
	void show(FWApplication* application) const;
	void updateState();

private:
	void initialize();
	void startState();
	bool canSeeRabbit();
	void wandering();
	void moveRandom();

	Vertex* position_;
	Vertex* cave_;
	int width_;
	int height_;
	States currentState_;
	States previousState_;

	bool inState_;
	double stepSpeed_;
	std::chrono::system_clock::time_point totalTime_;
	std::chrono::duration<double> totalTimer_;
	std::chrono::system_clock::time_point stepTime_;
	std::chrono::duration<double> stepTimer_;
};

