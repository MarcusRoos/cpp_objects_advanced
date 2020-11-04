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
    for (size_t i=0; i<tmpVehicle.size(); i++){
        if (tmpVehicle[i] != nullptr && tmpVehicle[i]->getType() == atype){
            stationVehicles.erase(stationVehicles.begin() + i);
            return tmpVehicle[i];
        }
    }
    return nullptr;
}

bool Station::testVehicle(int atype) {
    std::vector<std::shared_ptr<Vehicle>> tmpVehicle;
    tmpVehicle = stationVehicles;
    for (auto & i : tmpVehicle){
        if (i != nullptr && i->getType() == atype){
            return true;
        }
    }
    return false;
}

void Station::incomingVehicle(const std::vector<std::shared_ptr<Vehicle>>& aVehicle) {
    for (auto & i : aVehicle) {
        stationVehicles.push_back(i);
    }
}

void Station::printTypes() {
    std::cout << "======" <<stationName << "======" << std::endl;
    std::cout << "Available vehicles" << std::endl;
    for (auto & stationVehicle : stationVehicles) {
        std::cout << "Types: " << stationVehicle->printType() << " -- " <<
        stationVehicle->getId() << std::endl;
    }
}

bool Station::getVehicleID(unsigned int aID) {
    bool inTrain=false;
    for (auto & i : stationVehicles){
        if (aID == i->getId()) {
            inTrain = true;
            std::cout << "Vehicle ID " << i->getId()
                      << " is currently at station "
                      << stationName << std::endl;
        }
    }
    return inTrain;
}