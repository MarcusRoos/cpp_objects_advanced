//
// Created by Marcus Roos on 2020-10-18.
// Mittuniversitet
// StudentID: Maro1904
//

#include <iostream>
#include "vehicle.h"

/**
 * CLASS VEHICLE
 * **/
Vehicle::Vehicle(int aID, int aType) {
    ID = aID;
    type = aType;
}

Vehicle::Vehicle() {

}

unsigned int Vehicle::getId() {
    unsigned int tmpInt=-1;
    try {
        tmpInt = ID;
    }
    catch(int tmpInt){
        std::cout << "No ID could be returned from vehicles at " << tmpInt;
    }
    return tmpInt;
}

unsigned int Vehicle::getType() {
    unsigned int tmpInt=-1;
    try {
        tmpInt = type;
    }
    catch(int tmpInt){
        std::cout << "No type could be returned from vehicles at " << tmpInt;
    }
    return tmpInt;
}

/**
 * CLASS COACH
 * **/
CoachCar::CoachCar(int aId, int aType, int aSeats, int aInternet) : Vehicle(aId, aType) {
    seats = aSeats;
    internet = aInternet;
}

int CoachCar::getSeats() {
    return seats;
}

std::string CoachCar::getInternet() {
    if (internet == 1){
        return "Yes";
    }
    else
        return "No";
}


/**
 * CLASS SLEEPINGCAR
 * **/
SleepingCar::SleepingCar(int aId, int aType, int aBeds) : Vehicle(aId, aType) {
    beds = aBeds;
}

int SleepingCar::getBeds() {
    return beds;
}

/**
 * CLASS OPENFREIGHT
 * **/
OpenFreight::OpenFreight(int aId, int aType, int aCapacity, int aSquaremt)
        : Vehicle(aId, aType) {
    capacityTons = aCapacity;
    areaSqm = aSquaremt;
}

int OpenFreight::getTon() {
    return capacityTons;
}

int OpenFreight::getSqm() {
    return areaSqm;
}

/**
 * CLASS COVEREDFREIGHT
 * **/
CoveredFreight::CoveredFreight(int aId, int aType, int aCapacityC) : Vehicle(aId, aType) {
    capacityCubicm = aCapacityC;
}

int CoveredFreight::getCubic() {
    return capacityCubicm;
}

/**
 * CLASS DIESELENGINE
 * **/
DieselEngine::DieselEngine(int aId, int aType, int aMaxspeed, int aFuelcon)
        : Vehicle(aId, aType) {
    maxSpeed = aMaxspeed;
    fuelConsump = aFuelcon;
}

int DieselEngine::getDieselSpeed() {
    return maxSpeed;
}

int DieselEngine::getFuelConsump() {
    return fuelConsump;
}

/**
 * CLASS ELECTRICALENGINE
 * **/
ElectricalEngine::ElectricalEngine(int aId, int aType, int aMaxspeed,
                                   int aPowerKW) : Vehicle(aId, aType) {
    maxSpeed = aMaxspeed;
    powerKW = aPowerKW;
}

int ElectricalEngine::getElectricSpeed(){
    return maxSpeed;
}
int ElectricalEngine::getEffectKW() {
    return powerKW;
}
