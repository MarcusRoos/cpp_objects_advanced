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
    std::cout << "depositing to station: " << stationName << std::endl;
    for (auto & i : aVehicle) {
        std::cout << "types: " << i->getType() << std::endl;
        stationVehicles.push_back(i);
    }
}

void Station::printTypes() {
    for (auto & stationVehicle : stationVehicles) {
        std::cout << "Types: " << stationVehicle->getType() << std::endl;
    }
}
