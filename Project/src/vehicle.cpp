//
// Created by Marcus Roos on 2020-10-18.
// Mittuniversitet
// StudentID: Maro1904
//

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

int CoachCar::getInternet() {
    return internet;
}

/**
 * CLASS SLEEPINGCAR
 * **/
SleepingCar::SleepingCar(int aId, int aType, int aBeds) : Vehicle(aId, aType) {
    beds = aBeds;
}

/**
 * CLASS OPENFREIGHT
 * **/
OpenFreight::OpenFreight(int aId, int aType, int aCapacity, int aSquaremt)
        : Vehicle(aId, aType) {
    capacityTons = aCapacity;
    areaSqm = aSquaremt;
}

/**
 * CLASS COVEREDFREIGHT
 * **/
CoveredFreight::CoveredFreight(int aId, int aType, int aCapacityC) : Vehicle(aId, aType) {
    capacityCubicm = aCapacityC;
}

/**
 * CLASS DIESELENGINE
 * **/
DieselEngine::DieselEngine(int aId, int aType, int aMaxspeed, int aFuelcon)
        : Vehicle(aId, aType) {
    maxSpeed = aMaxspeed;
    fuelConsump = aFuelcon;
}

/**
 * CLASS ELECTRICALENGINE
 * **/
ElectricalEngine::ElectricalEngine(int aId, int aType, int aMaxspeed,
                                   int aPowerKW) : Vehicle(aId, aType) {
    maxSpeed = aMaxspeed;
    powerKW = aPowerKW;
}
