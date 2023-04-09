#pragma once
#include"TownBuilding.h"
class TransitBuilding : public TownBuilding {
private:
	bool isRoad;
	bool isPowerline;
	bool isPowerplant;
public:
	TransitBuilding(int, int, int, string, bool, bool, bool);
	void setIsRoad(bool road) { isRoad = road; }
	bool getIsRoad() { return isRoad; }
	void setIsPowerline(bool powerline) { isPowerline = powerline; }
	bool getIsPowerline() { return isPowerline; }
	void setIsPowerplant(bool powerpnt) { isPowerplant = powerpnt; }
	bool getIsPowerplant() { return isPowerplant; }
	void print();
	char getSymbol();
};