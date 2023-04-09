#include "Industrial.h"
extern int availableGoods;

Industrial::Industrial(int xIn, int yIn, int polIn, string sym, int popIn) : PopulationBuilding(xIn, yIn, polIn, sym, popIn)
{
    xLocation=xIn;
    yLocation=yIn;
    pollution=polIn;
}
//integer variables that count how many adjacent cells meet the criteria of having population of 1 or 2
int adjacentToPopulationOf1 = 0;
int adjacentToPopulationOf2 = 0;

//a function that iterates through the getNeighbors vector of adjacent cells and checks if their populations match the requirements and updates the value of adjacentToPopulationOf2 and adjacentToPopulationOf1
void Industrial::neighboursInfo(){

adjacentToPopulationOf1=0;
adjacentToPopulationOf2=0;
    for(TownBuilding* x : getNeighbors()){
        if (dynamic_cast<PopulationBuilding*>(x)){
			
            if (dynamic_cast<PopulationBuilding*>(x)->getPopulation() >= 1){
                adjacentToPopulationOf1++;            }

            if (dynamic_cast<PopulationBuilding*>(x)->getPopulation() >= 2){
                adjacentToPopulationOf2++;
            }
        }
    }
}

//-----------------------------------------------
//function that checks if a cell is adjacent to a powerline and return true if it is.
bool Industrial::adjacentToPowerline(){
vector<TownBuilding*> adjacencyList = getNeighbors();

    for(TownBuilding* x : adjacencyList){

            if (x->getSymbol() == "T" || x->getSymbol() == "#"){return true;}


    }
    return false;
}

//-----------------------------------------------


void Industrial::onTimeStep()
{
    neighboursInfo();

//checking if the first Industrial requirement (from the Project description) meets to increase the popualtion 
    if (getPopulation()==0 && adjacentToPowerline() && availableWorkers>=2){
		
		availableGoods++;
		setPopulation(getPopulation()+1);
		availableWorkers--;
    }
//checking if the second Industrial requirement (from the Project description) meets to increase the popualtion.

     if (getPopulation()==0 && adjacentToPopulationOf1>=1 && availableWorkers>=2){
		availableGoods++;
		setPopulation(getPopulation()+1);
		availableWorkers--;		
    }

//checking if the third Industrial requirement meets (from the Project description) to increase the popualtion 
    if (getPopulation()==1 && adjacentToPopulationOf1>=2 && availableWorkers>=2){
		availableGoods++;
		setPopulation(getPopulation()+1);
		availableWorkers--;
    }

//checking if the fourth Industrial requirement meets (from the Project description) to increase the popualtion 
    if (getPopulation()==2 && adjacentToPopulationOf2>=4 && availableWorkers>=2){
		availableGoods++;
		setPopulation(getPopulation()+1);
		availableWorkers--;
	}    

}

void Industrial::print()
{
    if (getPopulation()==0){cout<<"I ";}
    else (cout << getPopulation() << " ");
}
