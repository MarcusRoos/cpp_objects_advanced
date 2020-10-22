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
#include <fstream>
#include <vector>
#include <memory>
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
public:
    SimulationProgram();
    void runSubMenu();
    void run();
    void populateStation();
    void populateMap();
    void populateTrain();
    void printVehicleStart();
};

#endif //DT060G_SIMULATIONPROGRAM_H
