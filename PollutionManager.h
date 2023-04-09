#pragma once
#include "TownBuilding.h"
#include "Industrial.h"
#include "queue"

class PollutionManager {
    private:
        void SpreadPollution(TownBuilding* node, int polutionSpread, vector<vector<TownBuilding*>>* map);
        void PrintPollutionMap(vector<vector<TownBuilding*>>* map);
        void ResetExplored(vector<vector<TownBuilding*>>* map);
        void PrintMap(vector<vector<TownBuilding*>>* map);
    public:
        void CreatePollution(vector<vector<TownBuilding*>> *map);
};