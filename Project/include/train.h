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
#include <algorithm>
/**
 Class Train

 */
class Train {
protected:
    enum State state;
    int trainId, departureTime, arrivalTime;
    std::string fromStation, toStation;
    double maxSpeed;
    std::vector<int> logicalVehicles;
    std::vector<std::shared_ptr<Vehicle>> trainVehicles;
public:
    Train();
    ~Train() = default;;
    Train(int aID, std::string aFrom, std::string aTo, int aDtime, int aAtime, double aSpeed, std::vector<int> aLogicalVehicles);
    void assembleVehicle(std::vector<std::shared_ptr<Vehicle>> atrainVehicles);
    void trainTester();
    std::vector<int> getLogicalVehicles();
    void printTest();
    void MegaTest();
    int sizeVehicle(){return trainVehicles.size();}
    int getID(){return trainId;}
    bool assembleTrain();
    std::string getFromStation(){return fromStation;}
    std::string getToStation(){return toStation;}
    int getDepTime(){return departureTime;}
    int getArrTime(){return arrivalTime;}
};

#endif //DT060G_TRAIN_H
