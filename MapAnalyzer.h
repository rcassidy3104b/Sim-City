#pragma once
#include "TownBuilding.h"
#include "Residential.h"
#include "Industrial.h"
#include "Commercial.h"
#include "TransitBuilding.h"
#include "PollutionManager.h"

class MapAnalyzer
{
private:
	vector<vector<TownBuilding*>>* town;
public:
	MapAnalyzer(vector<vector<TownBuilding*>>* in) { town = in; }
	void analysis();
};

