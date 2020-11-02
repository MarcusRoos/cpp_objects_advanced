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
    std::string fromStation, toStation, arrPrint, depPrint;
    double maxSpeed;
    bool delayed;
    std::vector<int> logicalVehicles;
    std::vector<std::shared_ptr<Vehicle>> trainVehicles;
    std::shared_ptr<Station> from, to;
public:
    Train();
    ~Train() = default;;
    Train(int aID, std::string aFrom, std::string aTo, int aDtime, int aAtime, double aSpeed, std::vector<int> aLogicalVehicles, std::string printD, std::string printA);
    bool assembleVehicle(const std::vector<std::shared_ptr<Station>>& aStation);
    void disassembleTrain(const std::vector<std::shared_ptr<Station>>& aStation);
    int getsizeVehicle()&{return trainVehicles.size();}
    int getID(){return trainId;}
    std::string getFromStation(){return fromStation;}
    std::string getToStation(){return toStation;}
    std::string getArrPrint(){return arrPrint;}
    std::string getDepPrint(){return depPrint;}
    std::string getState(State);
    int getDepTime(){return departureTime;}
    int getArrTime(){return arrivalTime;}
    int getTmpDepTime(){return tmpDepartureTime;}
    int getTmpArrTime(){return tmpArrivalTime;}
    enum State getState(){return state;}
    void setState( State aState ){state = aState;}
    void delay(int time){arrivalTime+=time;departureTime+=time;}
    void setDelayed(bool nDelayed){delayed = nDelayed;}
    double getSpeed(){return maxSpeed;}
    bool getDelayed(){return delayed;}
    void printTypes();
    void printIncomplete();
    void printAtStation(std::string tmpStat);
};

#endif //DT060G_TRAIN_H
