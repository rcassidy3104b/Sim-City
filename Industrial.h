#pragma once
#include "PopulationBuilding.h"
extern int Goods;

class Industrial : public PopulationBuilding {
private:

    int xLocation;
    int yLocation;
    int pollution;
    
public:
    Industrial(int, int, int, string, int);
    void onTimeStep();
    void print();
    void neighboursInfo();
    bool adjacentToPowerline();
	
};
