//
// Created by Marcus Roos on 2020-10-18.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_SIMULATIONPROGRAM_H
#define DT060G_SIMULATIONPROGRAM_H

#include "Menu.h"
#include "train.h"
#include "station.h"
#include "map.h"
#include "Management.h"
#include "constants.h"
#include "Events.h"
#include "Simulator.h"
#include <unordered_map>
#include <fstream>
#include <vector>
#include <memory>
#include <set>
#include <map>
#include <algorithm>

class Simulator;

/**
 Class SimulationProgram
 */

class SimulationProgram {
private:
    Menu menu;
    std::vector<std::shared_ptr<Vehicle>> testVehicle;
    std::vector<std::shared_ptr<Station>> testStation;
    std::vector<std::shared_ptr<Train>> testTrain;
    std::vector<std::shared_ptr<Map>> testMap;
    Simulator* simulation;
    int amountDelayed;
    int amountSuccess;
    int totalLate;
public:
    SimulationProgram(Simulator* simulation);
    void runSubMenu();
    void run();
    void runLogmenu();
    void populateStation();
    void populateMap();
    void populateTrain();
    void statisticsMenu();
    void printStatistics();
    void vehicleMenu();
    void stationMenu();
    void trainMenu();
    void testMenu();
    void scheduleEvents();
    bool tryBuild(int trainId);
    void readyTrain( int trainId );
    int dispatchTrain( int trainId );
    void arriveTrain( int trainId );
    void stripTrain( int trainId );
    void disassembleTrain();
    static bool sortByName( const std::shared_ptr<Train>& d1, const std::shared_ptr<Train>& d2 );
};

#endif //DT060G_SIMULATIONPROGRAM_H
