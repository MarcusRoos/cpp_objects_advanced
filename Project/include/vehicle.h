//
// Created by Marcus Roos on 2020-10-18.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_VEHICLE_H
#define DT060G_VEHICLE_H

#include <string>
//------------------------------------------------------------------------------
// Class definition
//------------------------------------------------------------------------------
/**
 Class Vehicle

 */
class Vehicle {
protected:
    int type;
    int ID;
    int Coach=0, Sleeping=1, Open=2, Covered=3, Diesel=4, Electrical=5;
public:
    Vehicle(int aID, int aType);
    virtual ~Vehicle() = default;
    virtual void setId(int aID){}
    int getId(){return ID;}
    int getType(){return type;}
    virtual void setType(std::string){};
    virtual void setSeats(int aSeat){};
    virtual int getSeats(){return 0;}
};

class CoachCar : public Vehicle{
protected:
    int seats, internet;
public:
    CoachCar(int aId, int aType, int aSeats, int aInternet);
};

class SleepingCar : public Vehicle{
protected:
    int beds;
public:
    SleepingCar(int aId, int aType, int aBeds);
};

class OpenFreight : public Vehicle{
protected:
    int capacityTons, areaSqm;
public:
    OpenFreight(int aId, int aType, int aCapacity, int aSquaremt);
};

class CoveredFreight : public Vehicle{
protected:
    int capacityCubicm;
public:
    CoveredFreight(int aId, int aType, int aCapacityC);
};

class DieselEngine : public Vehicle{
private:
    int maxSpeed, fuelConsump;
public:
    DieselEngine(int aId, int aType, int aMaxspeed, int aFuelcon);
};


class ElectricalEngine : public Vehicle{
protected:
    int maxSpeed, powerKW;
public:
    ElectricalEngine(int aId, int aType, int aMaxspeed,
                     int aPowerKW);
};

#endif //DT060G_VEHICLE_H