#include "TownBuilding.h"
#include "Commercial.h"
#include "string"
extern int availableGoods;
Commercial::Commercial(int xIn, int yIn, int polIn, string sym, int popIn) : PopulationBuilding(xIn, yIn, polIn, sym, popIn)
{
    //by default every commercial building can grow and doesn't have a power line around it
    power= false;
    can_grow = true;
    
}

void Commercial::cangrow(int population)
{
    //maybe change this later on
    int adjacent_nodes=0;    
    for (TownBuilding* x: getNeighbors()){
        //this checks if any of it's adjacent nodes have power 
       if (!haspower() && (x->getSymbol() == "T" || x->getSymbol() == "#")) {
            setpower(true);
        }
		
		if(dynamic_cast<PopulationBuilding*>(x)){
			if (dynamic_cast<Commercial*>(x)->getPopulation()>=1)
				adjacent_nodes++;		
		}
        /* if(dynamic_cast<Commercial*>(x)){
            if (getPopulation() == 0) {
                if (dynamic_cast<Commercial*>(x)->getPopulation() > getPopulation() && !(dynamic_cast<Commercial*>(x)->Growable()))
                     adjacent_nodes++;
            }

            else {
                if (dynamic_cast<Commercial*>(x)->getPopulation() > getPopulation() - 1 && !(dynamic_cast<Commercial*>(x)->Growable()))
                 adjacent_nodes++;
            }
        } */
    }
    switch (population){
        case 0:
            if((availableGoods>=1&& availableWorkers>=1 && adjacent_nodes>=1)||(haspower()&& availableGoods>=1&& availableWorkers>=1)){
                //each cell can only grow once in each timestep reason why I set can grow to false
                //can_grow=false;
				setPopulation(getPopulation()+1);
				availableGoods--;
				availableWorkers--;
            }
			break;
			
    //check that there are available workers and available goods to support the growth
            case 1:
            if(adjacent_nodes>=2 && availableGoods>=1&& availableWorkers>=1){
                setPopulation(getPopulation()+1);
				availableGoods--;
				availableWorkers--;
            }
			break;
			
			
			default:
			break; 
    }
}
void Commercial::onTimeStep()
{
	cangrow(getPopulation());
    
/*     //run this only if the can grow function returns true
    if(cangrow(getPopulation())) 
    {
        //increment the cells population
        setPopulation(getPopulation() + 1);
        setSymbol(to_string(getPopulation() + 1));
    
        //setworker(getworker()+1);
        //setgood(getgood()+1);
      //decrease the amount of avaialble gooods aswell as the number of available workers in the system
        availableWorkers--;
        availableGoods--;
    } */
}

void Commercial::print()
{
    if (getPopulation()==0){cout<<"C ";}
    else (cout << getPopulation() << " ");
}
