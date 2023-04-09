#pragma once
#include "PopulationBuilding.h"

class Residential : public PopulationBuilding {
private:
    bool pow;
    bool growable;
public:
    Residential(int, int, int, string, int);
    void setPow(bool bo) { pow = bo; }
    bool hasPower() { return pow; }
    void setGrowable(bool gro) { growable = gro; }
    bool Growable() { return growable; }
    bool canGrow(int pop);
    void onTimeStep();
    void print();
};