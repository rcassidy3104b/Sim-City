#pragma once
#include "TownBuilding.h"

class PopulationBuilding : public TownBuilding{
private:
	int population;
public:
	PopulationBuilding(int, int, int, string, int);
	void setPopulation(int pop) { population = pop; }
	int getPopulation() { return population; }
	virtual void onTimeStep() = 0;
	virtual void print();
};