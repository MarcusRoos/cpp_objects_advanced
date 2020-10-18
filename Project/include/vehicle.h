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
    std::string type;
    int ID;
public:
    Vehicle();
    virtual ~Vehicle() = default;
    virtual void setId(int aID){}
    int getId(){return ID};
    std::string getType(){return type};
    virtual void setType(std::string){};
    virtual void setSeats(int aSeat){};
    virtual int getSeats(){};
};

class CoachCar : public Vehicle{
protected:
    int seats, internet;
    int const type = 0;
public:
    CoachCar();
};

class SleepingCar : public Vehicle{
protected:
    int beds;
    int const type = 1;
public:
    SleepingCar();
};

class OpenFreight : public Vehicle{
protected:
    int capacityTons, areaSqm;
    int const type = 2;
public:
    OpenFreight();
};

class CoveredFreight : public Vehicle{
protected:
    int capacityCubicm;
    const int type = 3;
public:
    CoveredFreight();
};

class DieselEngine : public Vehicle{
private:
    int maxSpeed, fuelConsump;
    int const type = 5;
public:
    DieselEngine();
};


class ElectricalEngine : public Vehicle{
protected:
    int maxSpeed, powerKW;
    int const type = 4;
public:
    ElectricalEngine();
};

#endif //DT060G_VEHICLE_H