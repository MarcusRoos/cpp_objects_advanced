//
// Created by Marcus Roos on 2020-10-18.
// Mittuniversitet
// StudentID: Maro1904
//

#include "vehicle.h"

/**
 * CLASS VEHICLE
 * **/
Vehicle::Vehicle() {

}

/**
 * CLASS COACH
 * **/
CoachCar::CoachCar(int aID) {
    type = Coach;
    ID = aID;
}

/**
 * CLASS SLEEPINGCAR
 * **/
SleepingCar::SleepingCar(int aID) {
    type = Sleeping;
    ID = aID;
}

/**
 * CLASS OPENFREIGHT
 * **/
OpenFreight::OpenFreight(int aID) {
    type = Open;
    ID = aID;
}

/**
 * CLASS COVEREDFREIGHT
 * **/
CoveredFreight::CoveredFreight(int aID) {
    type = Covered;
    ID = aID;
}

/**
 * CLASS DIESELENGINE
 * **/
DieselEngine::DieselEngine(int aID) {
    type = Diesel;
    ID = aID;
}

/**
 * CLASS ELECTRICALENGINE
 * **/
ElectricalEngine::ElectricalEngine(int aID) {
    type = Electrical;
    ID = aID;
}
