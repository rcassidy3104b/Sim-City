#pragma once
#include "PopulationBuilding.h"

class Commercial : public PopulationBuilding {
private:
    bool power;
    bool can_grow;
public:
    int goodcount;
    int workercount;
    Commercial(int, int, int, string, int);
    void onTimeStep();
    //bool cangrow(int population);
    void cangrow(int population);
   

    //functions that will allow me test for growth possibility and it's likes
    void setpower(bool my_power){ power = my_power;}
    bool haspower(){ return power;}
    void setGrowable(bool growable){ can_grow =growable;}
    bool Growable(){ return can_grow;}

    //functions to set the goods and workers assigned to each commercial building
    void setgood(int mygood){goodcount=mygood;};
    void setworker(int myworker){workercount=myworker;}
    int getgood(){return goodcount;}
    int getworker(){return workercount;}

    void print();
};
