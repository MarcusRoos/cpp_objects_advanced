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
#include <unordered_map>
#include <fstream>
#include <vector>
#include <memory>
#include <algorithm>
#include <iomanip>
//34 stycken incomplete utan disassemble
class Simulator;

/**
 Class SimulationProgram
 */

class SimulationProgram {
private:
    std::vector<std::shared_ptr<Vehicle>> testVehicle;
    std::vector<std::shared_ptr<Station>> testStation;
    std::vector<std::shared_ptr<Train>> testTrain;
    std::vector<std::shared_ptr<Map>> testMap;
    Simulator* simulation;
    int amountDelayed;
    int amountSuccess;
    int totalDelay;
    int TICK;
    std::ofstream outFile;
public:
    explicit SimulationProgram(Simulator* simulation);
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
    void printTimeTable();
    void testMenu();
    void changeTick();
    void scheduleEvents();
    void advance();
    void writeToFile(const std::string& aString);
    bool tryBuild(int trainId);
    void readyTrain( int trainId );
    int dispatchTrain( int trainId );
    void arriveTrain( int trainId );
    void EndTrain( int trainId );
    void endSimulation();
    static bool sortByName( const std::shared_ptr<Train>& d1, const std::shared_ptr<Train>& d2 );
};

#endif //DT060G_SIMULATIONPROGRAM_H
