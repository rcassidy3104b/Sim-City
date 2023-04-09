#include "FileReader.h"
#include "PopulationBuilding.h"
#include "TransitBuilding.h"
#include "Residential.h"
#include "Industrial.h"
#include "Commercial.h"
#include <string>

vector<vector<TownBuilding*>> FileReader::buildMap()
{
	string sIn;//input string storage
	cout << "Please input the name of the file containing the simulation configuration." << endl;
	cin >> sIn;
	ifstream myFile;
	myFile.open(sIn);//open config file
	getline(myFile, CSVFileName);
	CSVFileName = CSVFileName.erase(0,14);//remove data label
	getline(myFile, sIn);
	sIn = sIn.erase(0, 11);//remove data label
	maxTimeStep = stoi(sIn);//store data as an int
	getline(myFile, sIn);
	sIn = sIn.erase(0, 13);//remove data label
	refreshRate = stoi(sIn);//store data as an int

	vector<vector<TownBuilding*>> town;
	vector<TownBuilding*> row;//placeholder row
	int numRow = 0;
	string line;                                        
	myFile.close();
	myFile.open(CSVFileName);//open the csv file
	while (getline(myFile, line)) {//for each line in the csv file
		for (int i = 0; i < line.size(); i++) {//for each character in the line
			switch (line[i]) {//add a building to the town 2d vector. the type depends on the character
			case ' ':
				row.push_back(new TownBuilding(i, numRow, 0, " "));
				break;
			case 'R':
				row.push_back(new Residential(i, numRow, 0, "R", 0));
				break;
			case 'I':
				row.push_back(new Industrial(i, numRow, 0, "I", 0));
				break;
			case 'C':
				row.push_back(new Commercial(i, numRow, 0, "C", 0));
				break;
			case '-':
				row.push_back(new TransitBuilding(i, numRow, 0, "-", true, false, false));
				break;
			case 'T':
				row.push_back(new TransitBuilding(i, numRow, 0, "T", false, true, false));
				break;
			case '#':
				row.push_back(new TransitBuilding(i, numRow, 0, "#", true, true, false));
				break;
			case 'P':
				row.push_back(new TransitBuilding(i, numRow, 0, "P", false, false, true));
				break;
			}
		}
		numRow++;
		town.push_back(row);//add row to the 2d vector
		row.clear();
	}
	numRow = town.size();
	myFile.close();
	return town;
}