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
    unsigned int tmpInt=0;
    try {
        tmpInt = ID;
    }
    catch(int tmpInt){
        std::cout << "No ID could be returned from vehicles at " << tmpInt;
    }
    return tmpInt;
}

unsigned int Vehicle::getType() {
    unsigned int tmpInt=0;
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
    unsigned int tmpInt=0;
    try {
        tmpInt = seats;
    }
    catch(int tmpInt){
        std::cout << "No seats could be returned from vehicles at " << tmpInt;
    }
    return tmpInt;
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
    unsigned int tmpInt=0;
    try {
        tmpInt = beds;
    }
    catch(int tmpInt){
        std::cout << "No beds could be returned from vehicles at " << tmpInt;
    }
    return tmpInt;
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
    unsigned int tmpInt=0;
    try {
        tmpInt = capacityTons;
    }
    catch(int tmpInt){
        std::cout << "No capacity tons could be returned from vehicles at " << tmpInt;
    }
    return tmpInt;
}

int OpenFreight::getSqm() {
    unsigned int tmpInt=0;
    try {
        tmpInt = areaSqm;
    }
    catch(int tmpInt){
        std::cout << "No seats could be returned from vehicles at " << tmpInt;
    }
    return tmpInt;
}

/**
 * CLASS COVEREDFREIGHT
 * **/
CoveredFreight::CoveredFreight(int aId, int aType, int aCapacityC) : Vehicle(aId, aType) {
    capacityCubicm = aCapacityC;
}

int CoveredFreight::getCubic() {
    unsigned int tmpInt=0;
    try {
        tmpInt = capacityCubicm;
    }
    catch(int tmpInt){
        std::cout << "No cubic capacity could be returned from vehicles at " << tmpInt;
    }
    return tmpInt;
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
    unsigned int tmpInt=0;
    try {
        tmpInt = maxSpeed;
    }
    catch(int tmpInt){
        std::cout << "No max speed could be returned from vehicles at " << tmpInt;
    }
    return tmpInt;
}

int DieselEngine::getFuelConsump() {
    unsigned int tmpInt=0;
    try {
        tmpInt = fuelConsump;
    }
    catch(int tmpInt){
        std::cout << "No fuel consumption could be returned from vehicles at " << tmpInt;
    }
    return tmpInt;
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
    unsigned int tmpInt=0;
    try {
        tmpInt = maxSpeed;
    }
    catch(int tmpInt){
        std::cout << "No max speed could be returned from vehicles at " << tmpInt;
    }
    return tmpInt;
}
int ElectricalEngine::getEffectKW() {
    unsigned int tmpInt=0;
    try {
        tmpInt = powerKW;
    }
    catch(int tmpInt){
        std::cout << "No power KW could be returned from vehicles at " << tmpInt;
    }
    return tmpInt;
}
