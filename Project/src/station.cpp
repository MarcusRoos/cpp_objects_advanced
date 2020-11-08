//
// Created by Marcus Roos on 2020-10-19.
// Mittuniversitet
// StudentID: Maro1904
//

#include <algorithm>
#include <utility>
#include "station.h"

Station::Station() {
    stationName ="";
}

Station::Station(std::string aStationname, std::vector<std::shared_ptr<Vehicle>> aVehicle) {
    stationName = std::move(aStationname);
    stationVehicles = std::move(aVehicle);
}

std::shared_ptr<Vehicle> Station::outgoingVehicle(int atype) {
    std::vector<std::shared_ptr<Vehicle>> tmpVehicle;
    tmpVehicle = stationVehicles;
    try {
        for (size_t i = 0; i < tmpVehicle.size(); i++) {
            if (tmpVehicle[i] != nullptr && tmpVehicle[i]->getType() == atype) {
                stationVehicles.erase(stationVehicles.begin() + i);
                return tmpVehicle[i];
            }
        }
    }
    catch(std::vector<std::shared_ptr<Vehicle>> &tmpVehicle){
        std::cout << "Could not find outGoingVehicle" << std::endl;
    }
    return nullptr;
}

bool Station::testVehicle(int atype) {
    try {
        std::vector<std::shared_ptr<Vehicle>> tmpVehicle;
        tmpVehicle = stationVehicles;
        for (auto &i : tmpVehicle) {
            if (i != nullptr && i->getType() == atype) {
                return true;
            }
        }
    }
    catch(bool tmpBool){
        std::cout << "Not found testVehicle: " << tmpBool;
    }
    return false;
}

void Station::incomingVehicle(const std::vector<std::shared_ptr<Vehicle>>& aVehicle) {
    for (auto & i : aVehicle) {
        stationVehicles.push_back(i);
    }
}

void Station::printTypes() {
    std::cout << std::endl << "======" << stationName << "======" << std::endl;
    std::cout << "Available vehicles " << stationVehicles.size() << std::endl;
    for (auto &i : stationVehicles) {
        int tmpType = 0;
        std::cout << "Types: " << i->printType() << " ID: " <<
                  i->getId();
        tmpType = i->getType();
        switch (tmpType) {
            case 0:
            default:
                std::cout << " Seats: " <<i->getSeats() << " Internet? "<< i->getInternet() << std::endl;
                break;
            case 1:
                std::cout << " Beds: " <<i->getBeds() << std::endl;
                break;
            case 2:
                std::cout << " Capacity tons: " <<i->getTon() << " Sqm capacity: "<< i->getSqm() << std::endl;
                break;
            case 3:
                std::cout << " Cubic meter: " <<i->getCubic() << std::endl;
                break;
            case 4:
                std::cout << " Max speed: " <<i->getElectricSpeed() << " Effect KW: "<< i->getEffectKW() << std::endl;
                break;
            case 5:
                std::cout << " Max speed: " <<i->getDieselSpeed() << " Diesel consumption litre/h: "<< i->getFuelConsump() << std::endl;
                break;
        }
    }
}

bool Station::getVehicleID(unsigned int aID) {
    bool inTrain=false;
    try {
        for (auto &i : stationVehicles) {
            if (aID == i->getId()) {
                inTrain = true;
                std::cout << "Vehicle ID " << i->getId()
                          << " is currently at station "
                          << stationName
                          << " and ready to be attached to a train "
                          << std::endl;
            }
        }
    }
    catch(bool &inTrain){
        std::cout << "Not found getVehicleID: " << inTrain;
    }
    return inTrain;
}

std::string Station::getStationname() {
    std::string tmpString="stationNameError";
    try {
        tmpString = stationName;
    }
    catch(std::string &tmpString){
        std::cout << "Not found: " << tmpString;
    }
    return tmpString;
}
