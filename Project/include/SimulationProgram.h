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
#include <fstream>
#include <vector>
#include <memory>
/**
 Class SimulationProgram


 */
class SimulationProgram {
private:
    Menu menu;
    std::vector<std::unique_ptr<Vehicle>> testVehicle;
    std::vector<std::unique_ptr<Station>> testStation;
    std::vector<std::vector<Train>> testTrain;
public:
    SimulationProgram();
    void runSubMenu();
    void run();
    void getType();
    void getID();
    void trainTest();
    void getSeats();
    void getInternet();
    void assembleTrain();
    void loadFiles();
};

#endif //DT060G_SIMULATIONPROGRAM_H
