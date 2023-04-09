#include "PopulationBuilding.h"
PopulationBuilding::PopulationBuilding(int xIn, int yIn, int polIn, string sym, int popIn) :
	TownBuilding(xIn, yIn, polIn, sym){
	population = popIn;
}

void PopulationBuilding::print()
{
	TownBuilding::print();
	cout << "Population: " << population << endl;
}