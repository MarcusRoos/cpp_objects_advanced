//
// Created by Marcus Roos on 2020-10-18.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_SIMULATIONPROGRAM_H
#define DT060G_SIMULATIONPROGRAM_H

#include "Menu.h"
#include "vehicle.h"
#include <fstream>
#include <vector>
#include <memory>
/**
 Class testApp

 The testApp will handle the menu options and allow user input, it will
 handle the communication between the user and the underlying classes.
 From here the user will be able to call different functions which will
 handle different tasks. A queue need to be created by using the first
 alternative before any of the other options open up, exit excluded.
 */
class SimulationProgram {
private:
    Menu menu;
    std::vector<std::unique_ptr<Vehicle>> testVehicle;
public:
    SimulationProgram();
    void runSubMenu();
    void run();
    void getType();
    void getID();
    void testTrain();
};

#endif //DT060G_SIMULATIONPROGRAM_H
