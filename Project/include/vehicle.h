//
// Created by Marcus Roos on 2020-10-18.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_VEHICLE_H
#define DT060G_VEHICLE_H
#include "constants.h"
#include <string>

/**
 Class Vehicle
 This class will handle all information regarding vehicles, it consists of a
 base class which contain all data members which are used for the derived
 functions as well as virtual functions. All virtual functions are later
 redefined under their respective subclass and data members unique to the
 sub class is declared and set. This class will contain all information
 regarding all vehicles in the program.
 */
class Vehicle {
protected:
    int type;
    int ID;
public:
    Vehicle();
    Vehicle(int aID, int aType);
    virtual ~Vehicle() = default;
    unsigned int getId();
    unsigned int getType();
    virtual std::string printType() {return 0;}
};

class CoachCar : public Vehicle{
protected:
    int seats, internet;
public:
    CoachCar(int aId, int aType, int aSeats, int aInternet);
    virtual std::string printType() {return "Coach car";}
};

class SleepingCar : public Vehicle{
protected:
    int beds;
public:
    SleepingCar(int aId, int aType, int aBeds);
    virtual std::string printType() {return "Sleeping car";}
};

class OpenFreight : public Vehicle{
protected:
    int capacityTons, areaSqm;
public:
    OpenFreight(int aId, int aType, int aCapacity, int aSquaremt);
    virtual std::string printType() {return "Open freight";}
};

class CoveredFreight : public Vehicle{
protected:
    int capacityCubicm;
public:
    CoveredFreight(int aId, int aType, int aCapacityC);
    virtual std::string printType() {return "Covered freight";}
};

class DieselEngine : public Vehicle{
private:
    int maxSpeed, fuelConsump;
public:
    DieselEngine(int aId, int aType, int aMaxspeed, int aFuelcon);
    virtual std::string printType() {return "Diesel engine";}
};


class ElectricalEngine : public Vehicle{
protected:
    int maxSpeed, powerKW;
public:
    ElectricalEngine(int aId, int aType, int aMaxspeed,
                     int aPowerKW);
    virtual std::string printType() {return "Electrical engine";}
};

#endif //DT060G_VEHICLE_H