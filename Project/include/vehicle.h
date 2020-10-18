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
    Vehicle();
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
    CoachCar(int aID);
};

class SleepingCar : public Vehicle{
protected:
    int beds;
public:
    SleepingCar(int aID);
};

class OpenFreight : public Vehicle{
protected:
    int capacityTons, areaSqm;
public:
    OpenFreight(int aID);
};

class CoveredFreight : public Vehicle{
protected:
    int capacityCubicm;
public:
    CoveredFreight(int aID);
};

class DieselEngine : public Vehicle{
private:
    int maxSpeed, fuelConsump;
public:
    DieselEngine(int aID);
};


class ElectricalEngine : public Vehicle{
protected:
    int maxSpeed, powerKW;
public:
    ElectricalEngine(int aID);
};

#endif //DT060G_VEHICLE_H