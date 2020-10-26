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
#include "station.h"
#include <list>
#include <iostream>
#include <algorithm>
/**
 Class Train

 */
class Train {
protected:
    enum State state;
    int trainId, departureTime, arrivalTime, tmpArrivalTime, tmpDepartureTime;
    std::string fromStation, toStation;
    double maxSpeed;
    bool delayed;
    std::vector<int> logicalVehicles;
    std::vector<std::shared_ptr<Vehicle>> trainVehicles;
    std::shared_ptr<Station> from, to;
public:
    Train();
    ~Train() = default;;
    Train(int aID, std::string aFrom, std::string aTo, int aDtime, int aAtime, double aSpeed, std::vector<int> aLogicalVehicles);
    bool assembleVehicle(std::vector<std::shared_ptr<Station>> aStation);
    void MegaTest();
    int sizeVehicle(){return trainVehicles.size();}
    int getID(){return trainId;}
    std::string getFromStation(){return fromStation;}
    std::string getToStation(){return toStation;}
    int getDepTime(){return departureTime;}
    int getArrTime(){return arrivalTime;}
    int getTmpDepTime(){return tmpDepartureTime;}
    int getTmpArrTime(){return tmpArrivalTime;}
    State getState(){return state;}
    void setState( State aState ){state = aState;}
    void delay(int time){arrivalTime+=time;departureTime+=time;}
    void setDelayed(bool nDelayed){delayed = nDelayed;}
    double getSpeed(){return maxSpeed;}
    bool getDelayed(){return delayed;}
};

#endif //DT060G_TRAIN_H
