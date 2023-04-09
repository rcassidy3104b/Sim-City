#include "TownBuilding.h"
#include "PollutionManager.h"
#include "FileReader.h"
#include "Commercial.h"
#include "Industrial.h"
#include "Residential.h"
#include "MapAnalyzer.h"

#include <iostream>
using namespace std;
int availableWorkers; // Global variable for the available workers
int availableGoods; //Global goods variable

vector<TownBuilding*> addNeighbors(int i, int j, vector<vector<TownBuilding*> >* town) { //This will populate the townbuilding adjecency list for future use
    vector<TownBuilding*> tow;

    int fac;
    if (i == 0 || i == town->size() - 1) {
        if (i == 0) fac = i + 1;
        else fac = i - 1;
        
        tow.push_back(town->at(fac).at(j));
        if (j != town->at(i).size() - 1) {
            tow.push_back(town->at(i).at(j + 1));
            tow.push_back(town->at(fac).at(j + 1));
        }
        if (j != 0) {
            tow.push_back(town->at(i).at(j - 1));
            tow.push_back(town->at(fac).at(j - 1));
        }
    }
    else if (j == 0 || j == town->at(i).size() - 1) {
        if (j == 0) fac = j + 1;
        else fac = j - 1;

        tow.push_back(town->at(i).at(fac));
        tow.push_back(town->at(i + 1).at(j));
        tow.push_back(town->at(i - 1).at(j));
        tow.push_back(town->at(i + 1).at(fac));
        tow.push_back(town->at(i - 1).at(fac));
    }

    else {
        tow.push_back(town->at(i - 1).at(j - 1));
        tow.push_back(town->at(i - 1).at(j));
        tow.push_back(town->at(i - 1).at(j + 1));
        tow.push_back(town->at(i).at(j - 1));
        tow.push_back(town->at(i).at(j + 1));
        tow.push_back(town->at(i + 1).at(j - 1));
        tow.push_back(town->at(i + 1).at(j));
        tow.push_back(town->at(i + 1).at(j + 1));
    }
    return tow;
}


void townPrint(vector<vector<TownBuilding*>>* town) { //Will print out the town but also populate the townbuilding neighboor vector
    int totPop = 0, resPop = 0, indPop = 0, comPop = 0;
    for (int i = 0; i < town->size(); i++) {
        for (int j = 0; j < town->at(i).size(); j++) {
            if (dynamic_cast<PopulationBuilding*>(town->at(i).at(j))) {//checks if the building has a population
                totPop+=dynamic_cast<PopulationBuilding*>(town->at(i).at(j))->getPopulation();//adds the population to the total population of all buildings
            }
            if (dynamic_cast<Residential*>(town->at(i).at(j))) {//checks if the building is residential
                resPop += dynamic_cast<PopulationBuilding*>(town->at(i).at(j))->getPopulation();//adds the population to the residential population
            }
            if (dynamic_cast<Industrial*>(town->at(i).at(j))) {//checks if he building is industrial
                indPop += dynamic_cast<PopulationBuilding*>(town->at(i).at(j))->getPopulation();//adds the popualtion to the industrial population
            }
            if (dynamic_cast<Commercial*>(town->at(i).at(j))) {//checks if the building is commercial
                comPop += dynamic_cast<PopulationBuilding*>(town->at(i).at(j))->getPopulation();//adds the population to the commercial population
            }
            town->at(i).at(j)->print();//prints the building symbol
            town->at(i).at(j)->setNeighbors(addNeighbors(i, j, town));//triggers adjacency list function for this node
        }
        cout << endl;
    }
    cout << "Available Workers: " << availableWorkers << endl;
    cout << "Avalable Goods: " << availableGoods << endl;
    cout << "Total population in all buildings: " << totPop << endl;
    cout << "Residential Zone Population: " << resPop << endl;
    cout << "Industrial Zone Population: " << indPop << endl;
    cout << "Commercial Zone Population: " << comPop << endl;
    cout << "\n\n";
}

void RRG(vector<vector<TownBuilding*> >* town) { //Reset Residential Growability
    for (int i = 0; i < town->size(); i++) {
        for (int j = 0; j < town->at(i).size(); j++) {
            if (dynamic_cast<Residential*>(town->at(i).at(j))) dynamic_cast<Residential*>(town->at(i).at(j))->setGrowable(true);
        }
    }
}

int main()
{
    FileReader reader;//initislizes simulation based of the files
    vector<vector<TownBuilding*>> town = reader.buildMap();
    PollutionManager pollutionManager;
    int maxTimeSteps = reader.getMaxTimeStep();
    int refreshRate = reader.getRefreshRate();
    townPrint(&town);
    cout << "\n\n";
    availableWorkers = 0;
    availableGoods = 0;
    int time = 0;
    
    while (time < maxTimeSteps) {
        for (int i = 0; i < town.size(); i++) {//Residential growth loop
            for (int j = 0; j < town.at(i).size(); j++) {
                if (dynamic_cast<PopulationBuilding*>(town.at(i).at(j))) {
                    dynamic_cast<PopulationBuilding*>(town.at(i).at(j))->onTimeStep();

                }
            }
        }
        if (time % refreshRate == 0) townPrint(&town);
        time++;
        RRG(&town);
    }

    //After Simulation is finished 
    cout<<"Final Region State:"<<endl;
    townPrint(&town);

    //After end of simulation analysis
    MapAnalyzer endAnalyzer(&town);
    endAnalyzer.analysis();
    

    cout << "Press 0 and Enter to exit program." << endl;
    string end;
    cin >> end;
    cout<<"play";
    return 0;
}