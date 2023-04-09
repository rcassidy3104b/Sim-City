#include "PollutionManager.h"

//This function creates the pollution spread through the whole city to be called at the end of the simulation
//Takes in the town map as a parameter
void PollutionManager::CreatePollution(vector<vector<TownBuilding*>>* map)
{
    //Loop through every node in map
    for (int i = 0; i < map->size(); i++) {
        for (int j = 0; j < map->at(i).size(); j++) {
            //See if the node can be cast to industrial
            TownBuilding *node = map->at(i).at(j);
            if (dynamic_cast<Industrial*>(node)) {
                //Set the explored value of all nodes to false
                ResetExplored(map);

                //If so, call spread pollution using the node as paremeter 1 and base population as base pollution spread
                //and as the final parameter it takes in the town map
                SpreadPollution(node, dynamic_cast<PopulationBuilding*>(node)->getPopulation(), map);
            }
        }
    }
}

//This is a recursive function that uses a BFS on the node called. Base case is if pollution spread is 0
void PollutionManager::SpreadPollution(TownBuilding* node, int pollutionSpread, vector<vector<TownBuilding*>>* map)
{
    int spread = pollutionSpread;
    
    //Create a queue to add all adj nodes to
    queue<TownBuilding*> adjQueue;
    adjQueue.push(node);

    //Base case if polutionSpread is 0 or if the queue is empty
    if(pollutionSpread <= 0 || adjQueue.size() <= 0)
    {
        return;
    }

    //Record first node and pop from queue
    adjQueue.pop();

    //Increase pollution
    node->incrementPollution(pollutionSpread);

    //Set the first node to being explored
    if (node->getExplored() == false)
    {
        node->setExplored(true);
    }

    //Loop through adjacency list
    for(TownBuilding* adjNode : node->getNeighbors())
    {
        //see if node has been discovered
        if(adjNode->getExplored() == false)
        {
            //if not, explore it and enqueue it
            adjNode->setExplored(true);
            adjQueue.push(adjNode);
        }
    }

    //Loop through the queue and call spread polution on all of them
    while (!adjQueue.empty())
    {
        spread = pollutionSpread;
        SpreadPollution(adjQueue.front(), --spread, map);
        adjQueue.pop();
    }
    
}


//Sets every value in a 2d vector to false
//Takes in a 2d vector of bool as a parameter
void PollutionManager::ResetExplored(vector<vector<TownBuilding*>>* map)
{
    for (vector<TownBuilding*> townmap : *map)
    {
        for (TownBuilding* tb : townmap)
        {
            tb->setExplored(false);
        }
    }
}

void PollutionManager::PrintMap(vector<vector<TownBuilding*>>* map)
{
    for (vector<TownBuilding*> townmap : *map)
    {
        for (TownBuilding* tb : townmap)
        {
            cout << tb->getExplored() << " ";
        }
        cout << endl;
    }
}
void PollutionManager::PrintPollutionMap(vector<vector<TownBuilding*>>* map)
{
    for (vector<TownBuilding*> townmap : *map)
    {
        for (TownBuilding* tb : townmap)
        {
            cout << tb->getPollution() << " ";
        }
        cout << endl;
    }
}