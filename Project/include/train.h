//
// Created by Marcus Roos on 2020-10-18.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_TRAIN_H
#define DT060G_TRAIN_H
#include <string>
#include <memory>
#include <vector>
#include "vehicle.h"
#include "constants.h"
#include <list>
#include <iostream>
/**
 Class Train

 */
class Train {
protected:
    enum State state;
    int trainId;
    std::string fromStation, toStation, departureTime, arrivalTime;
    double maxSpeed;
    std::vector<int> logicalVehicles;
    std::vector<std::shared_ptr<Vehicle>> trainVehicles;
public:
    Train();
    ~Train() = default;;
    Train(int aID, std::string aFrom, std::string aTo, std::string aDtime, std::string aAtime, double aSpeed, std::vector<int> aLogicalVehicles);
    void assembleVehicle(std::vector<std::shared_ptr<Vehicle>> atrainVehicles);
    void trainTester();
    std::vector<int> getLogicalVehicles();
    std::string getDepname(){return fromStation;}
    void printTest();
    void MegaTest();
};

#endif //DT060G_TRAIN_H
