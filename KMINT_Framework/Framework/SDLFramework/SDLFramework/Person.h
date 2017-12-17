#pragma once
#include "FWApplication.h"
#include "Vertex.h"
#include "StatesEnum.h"

class Person
{
public:
	Person();
	~Person();
	void setPosition(Vertex* position);
	char getName();
	void show(FWApplication* application) const;

protected:
	Vertex* position_;
	Vertex* startPosition_;
	int minWater_;
	int maxWater_;
	int width_;
	int heigth_;
	char name_;
	Color colour_;
};

