#include "Residential.h"
#include "string"
using namespace std;
Residential::Residential(int xIn, int yIn, int polIn, string sym, int popIn) : PopulationBuilding(xIn, yIn, polIn, sym, popIn)
{
    pow = false;
    growable = true;
}

bool Residential::canGrow(int pop) { //Sees if cell can grow based on population
    int helpful = 0;
    vector<TownBuilding*> to = getNeighbors();
    for (TownBuilding* x : to) {
        if (!hasPower() && (x->getSymbol() == "T" || x->getSymbol() == "#")) {
            setPow(true);
        }
        if (dynamic_cast<Residential*>(x)) {
            if (getPopulation() == 0) {
                if (dynamic_cast<Residential*>(x)->getPopulation() > pop + !(dynamic_cast<Residential*>(x)->Growable())) helpful++;
            }
            else {
                if (dynamic_cast<Residential*>(x)->getPopulation() > pop - 1 + !(dynamic_cast<Residential*>(x)->Growable())) helpful++;
            }
        }
    }
    switch (pop) {
    case 0:
        if (hasPower() || helpful >= 1) {
            growable = false;
            return true;
        }
        break;
    case 1:
        if(helpful >= 2) {
            growable = false;
            return true;
        }
        break;
    case 2:
        if (helpful >= 4) {
            growable = false;
            return true;
        }
        break;
    case 3:
        if (helpful >= 6) {
            growable = false;
            return true;
        }
        break;
    case 4:
        if (helpful == 8) {
            growable = false;
            return true;
        }
        break;
    }
    return false;
}

void Residential::onTimeStep() {
    //Run Switch statement first based on pop, then check surrounding nodes to see if the cell can grow when applicable
    int pop = getPopulation();
    if (canGrow(pop)) {
        setPopulation(pop + 1);
        setSymbol(to_string(pop + 1));
        availableWorkers++;
    }

}

void Residential::print()
{
    cout << getSymbol() << " ";
}
