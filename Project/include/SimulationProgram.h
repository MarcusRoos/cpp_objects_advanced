//
// Created by Marcus Roos on 2020-10-18.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_SIMULATIONPROGRAM_H
#define DT060G_SIMULATIONPROGRAM_H

#include "train.h"
#include "station.h"
#include "map.h"
#include "Management.h"
#include "constants.h"
#include "Events.h"
#include "Simulator.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <limits>
#include <memory>
#include <algorithm>
#include <iomanip>
class Simulator;

/**
 Class SimulationProgram

The bulk of the program, this will take care of the majority of function calls
 and store the relevant data. This will make the function calls both to and
 from all the other classes, it will read in the required files, store them
 in vectors, use pointers to talk to the different classes and print
 all the different kind of menus.
 */

class SimulationProgram {
private:
    // Private data members
    std::vector<std::shared_ptr<Vehicle>> testVehicle;
    std::vector<std::shared_ptr<Station>> testStation;
    std::vector<std::shared_ptr<Train>> testTrain;
    std::vector<std::shared_ptr<Map>> testMap;
    Simulator* simulation;
    int amountDelayed;
    int amountSuccess;
    int totalDelay;
    int TICK;
    bool submenuLoop = true;
    std::ofstream outFile;
public:
    // Public function members
    /**
* Default constructor of class SimulationProgram
*
* @param Pointer to Simulator.
* @return None.
*/
    explicit SimulationProgram(Simulator* simulation);
    /**
* Prints sub menu
*
* @param None.
* @return None.
*/
    void runSubMenu();
    /**
* Prints main menu
*
* @param None.
* @return None.
*/
    void run();
    /**
* Fills up station vector
*
* @param None.
* @return None.
*/
    void populateStation();
    /**
* Fills up map vector
*
* @param None.
* @return None.
*/
    void populateMap();
    /**
* Fills up train vector
*
* @param None.
* @return None.
*/
    void populateTrain();
    /**
* Prints statistics menu
*
* @param None.
* @return None.
*/
    void statisticsMenu();
    /**
* Prints statistics at start
*
* @param None.
* @return None.
*/
    void printStatistics();
    /**
* Prints info regarding specific station
*
* @param None.
* @return None.
*/
    void printSpecificStation();
    /**
* Prints info regarding specific train
*
* @param None.
* @return None.
*/
    void printSpecificTrain();
    /**
* Prints time table for all the trains
*
* @param None.
* @return None.
*/
    void printTimeTable();
    /**
* Prints statistics at the end of runtime
*
* @param None.
* @return None.
*/
    void endStats();
    /**
* Changes simulator time interval
*
* @param None.
* @return None.
*/
    void changeTick();
    /**
* Schedules tasks to be using in the priority queue
*
* @param None.
* @return None.
*/
    void scheduleEvents();
    /**
* Prints info regarding specific vehicle ID and its current position
*
* @param None.
* @return None.
*/
    void followVehicle();
    /**
* Advances simulator time by one tick
*
* @param None.
* @return None.
*/
    void advance();
    /**
* Writes relevant console output to file
*
* @param String.
* @return None.
*/
    void writeToFile(const std::string& aString);
    /**
* Tries to build together a train
*
* @param integer.
* @return Bool.
*/
    bool tryBuild(int trainId);
    /**
* Marks a train as ready to dispatch
*
* @param integer.
* @return None.
*/
    void readyTrain( int trainId );
    /**
* Dispatches a train from its station and prints relevant info
*
* @param integer.
* @return integer.
*/
    int dispatchTrain( int trainId );
    /**
* Changes state when a train has arrived at its station and prints relevant info
*
* @param integer.
* @return None.
*/
    void arriveTrain( int trainId );
    /**
* Train has finished, disassembles
*
* @param integer.
* @return None.
*/
    void EndTrain( int trainId );
    /**
* End of simulation, informs the user that the end of simulation has been reached
*
* @param None.
* @return None.
*/
    void endSimulation();
    /**
* Sorts train by dispatch time to later be used in priority queue
*
* @param Two shared pointers to the object train.
* @return Bool.
*/
    static bool sortByTime( const std::shared_ptr<Train>& d1, const std::shared_ptr<Train>& d2 );
};

#endif //DT060G_SIMULATIONPROGRAM_H
