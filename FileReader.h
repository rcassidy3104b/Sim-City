#pragma once
#include "TownBuilding.h"
#include "Residential.h"
#include "Industrial.h"
#include "Commercial.h"
#include "TransitBuilding.h"
#include <fstream>
#include <vector>

class FileReader {
private:
	string CSVFileName;
	int maxTimeStep;
	int refreshRate;
public:
	void setCSVFileName(string in) { CSVFileName = in; }
	string getCSVFileName() { return CSVFileName; }
	void setMaxTimeStep(int in) { maxTimeStep = in; }
	int getMaxTimeStep() { return maxTimeStep; }
	void setRefreshRate(int in) { refreshRate = in; }
	int getRefreshRate() { return refreshRate; }

	vector<vector<TownBuilding*>> buildMap();
};