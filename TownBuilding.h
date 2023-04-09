#pragma once
#include<iostream>
#include <vector>
using namespace std;
extern int availableWorkers; // Global variable for the available workers

class TownBuilding {
private:
	int xCoord;
	int yCoord;
	int pollution;
	bool explored;
	string symbol;
	vector<TownBuilding*> surrTown;
public:
	TownBuilding(int, int, int, string);
	void setXCoord(int in) { xCoord = in; }
	int getXCoord() { return xCoord; }
	void setYCoord(int in) { yCoord = in; }
	int getYCoord() { return yCoord; }
	void setPollution(int in) { pollution = in; }
	int getPollution() { return pollution; }
	void incrementPollution(int in) {pollution += in; }
	void setExplored(bool in) { explored = in; }
	bool getExplored() { return explored; }
	void setSymbol(string s) { symbol = s; }
	string getSymbol() { return symbol; }
	void setNeighbors(vector<TownBuilding*> t) { surrTown = t; }
	vector<TownBuilding*> getNeighbors() { return surrTown; }//A function that returns all of the neighbors around a node, returns a vector that contains at minimum 3 nodes, and at max 8 nodes
	virtual void print();
};