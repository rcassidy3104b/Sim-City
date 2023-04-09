#include "TownBuilding.h"
TownBuilding::TownBuilding(int xIn, int yIn, int polIn, string sym) {
	xCoord = xIn;
	yCoord = yIn;
	pollution = polIn;
	symbol = sym;
}

void TownBuilding::print() {
	cout << "  ";
}