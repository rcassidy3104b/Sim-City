#include "TransitBuilding.h"

TransitBuilding::TransitBuilding(int xIn, int yIn, int polutionIn, string sym, bool roadIn, bool powerlineIn, bool powerplantIn):
	TownBuilding(xIn, yIn, polutionIn, sym){
	isRoad = roadIn;
	isPowerline = powerlineIn;
	isPowerplant = powerplantIn;
}

void TransitBuilding::print()
{
	if (isRoad && isPowerline) {
		cout << "# ";
	}
	else if (isRoad) {
		cout << "- ";
	}
	else if (isPowerline) {
		cout << "T ";
	}
	else if (isPowerplant) {
		cout << "P ";
	}
}

char TransitBuilding::getSymbol()
{
	if (isRoad && isPowerline) {
		return '#';
	}
	else if (isRoad) {
		return '-';
	}
	else if (isPowerline) {
		return 'T';
	}
	else if (isPowerplant) {
		return 'P';
	}
	return 0;
}

