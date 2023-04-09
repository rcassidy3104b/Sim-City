#include "MapAnalyzer.h"

void MapAnalyzer::analysis()
{
//Prompt the user for the coordinates of some rectangular area of the region to analyze more closely
	cout << "Please enter the x coordinate of the top left cell of the region to analyze more closely." << endl;
	int xCoord1, yCoord1;
	cin >> xCoord1;
	cout << "Please enter the y coordinate of the top left cell of the region to analyze more closely." << endl;
	cin >> yCoord1;
	cout << "Please enter the x coordinate of the bottom right cell of the region to analyze more closely." << endl;
	int xCoord2, yCoord2;
	cin >> xCoord2;
	cout << "Please enter the y coordinate of the bottom right cell of the region to analyze more closely." << endl;
	cin >> yCoord2;

//You must perform bounds checking to make sure the coordinates are within the bounds of the region, and re - prompt the user if their coordinates are outside the bounds
	while (!(xCoord1 >= 0 && xCoord1 < town->size() && yCoord1 >= 0 && yCoord1 < town->at(xCoord1).size())) {
		cout << "Please enter a valid x coordinate for the top left cell." << endl;
		cin >> xCoord1;
		cout << "Please enter a valid y coordinate for the top left cell." << endl;
		cin >> yCoord1;
	}
	while (!(xCoord2 >= 0 && xCoord2 < town->size() && yCoord2 >= 0 && yCoord2 < town->at(xCoord2).size() && xCoord2>xCoord1 && yCoord2>yCoord1)) {
		cout << "Please enter a valid x coordinate for the bottom right cell." << endl;
		cin >> xCoord2;
		cout << "Please enter a valid y coordinate for the bottom right cell." << endl;
		cin >> yCoord2;
	}
//Output the total population for residential zones, industrial zones, and commercial zones within the area specified by the user
	int totPol = 0, totPop = 0, resPop = 0, indPop = 0, comPop = 0;
	for (int i = yCoord1; i <= yCoord2; i++) {
		for (int j = xCoord1; j <= xCoord2; j++) {
			if (dynamic_cast<PopulationBuilding*>(town->at(i).at(j))) {//checks if the building has a population
				totPop += dynamic_cast<PopulationBuilding*>(town->at(i).at(j))->getPopulation();//adds the population to the total population of all buildings
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
		}
		cout << "\n";
	}
	cout << "Total population in selected buildings: " << totPop << endl;
	cout << "Residential Zone Regional Population: " << resPop << endl;
	cout << "Industrial Zone Regional Population: " << indPop << endl;
	cout << "Commercial Zone Regional Population: " << comPop << endl;
	PollutionManager pollute;
	pollute.CreatePollution(town);//calculates the pollution of the town
	//Output the final regional pollution state
	char transitSym = ' ';
	int regPol = 0;
	cout << "Pollution map of the selected region. Displays the building type and level of pollution in paranthesis." << endl;
	for (int i = yCoord1; i <= yCoord2; i++) {
		for (int j = xCoord1; j <= xCoord2; j++) {
			if (dynamic_cast<Residential*>(town->at(i).at(j))) {//checks if the building is residential
				cout << "R(" << town->at(i).at(j)->getPollution() << ") ";
				regPol += town->at(i).at(j)->getPollution();
				continue;
			}
			if (dynamic_cast<Industrial*>(town->at(i).at(j))) {//checks if he building is industrial
				cout << "I(" << town->at(i).at(j)->getPollution() << ") ";
				regPol += town->at(i).at(j)->getPollution();
				continue;
			}
			if (dynamic_cast<Commercial*>(town->at(i).at(j))) {//checks if the building is commercial
				cout << "C(" << town->at(i).at(j)->getPollution() << ") ";
				regPol += town->at(i).at(j)->getPollution();
				continue;
			}
			if (dynamic_cast<TransitBuilding*>(town->at(i).at(j))) {//checks if the building is transit building
				cout << town->at(i).at(j)->getSymbol() << "(" << town->at(i).at(j)->getPollution() << ") ";
				regPol += town->at(i).at(j)->getPollution();
				continue;
			}
			cout<<" ("<< town->at(i).at(j)->getPollution() << ") ";
			regPol += town->at(i).at(j)->getPollution();
		}
		cout << "\n";
	}
	//Output the total pollution in the region
	cout << "Total pollution units in the selected area: " << regPol << endl;
}
