//
// Created by Marcus Roos on 2020-10-19.
// Mittuniversitet
// StudentID: Maro1904
//

#include <algorithm>
#include "station.h"

Station::Station() {
    stationName ="";
}

Station::Station(std::string aStationname, std::vector<std::shared_ptr<Vehicle>> aVehicle) {
    stationName = aStationname;
    stationVehicles = std::move(aVehicle);
}

std::shared_ptr<Vehicle> Station::outgoingVehicle(int atype) {
    std::vector<std::shared_ptr<Vehicle>> tmpVehicle;
    tmpVehicle = stationVehicles;
    for (int i=0; i<tmpVehicle.size(); i++){
        if (tmpVehicle[i] != NULL && tmpVehicle[i]->getType() == atype){
            stationVehicles.erase(stationVehicles.begin() + i);
            return tmpVehicle[i];
        }
    }
    return NULL;
}

bool Station::testVehicle(int atype) {
    std::vector<std::shared_ptr<Vehicle>> tmpVehicle;
    tmpVehicle = stationVehicles;
    for (int i=0; i<tmpVehicle.size(); i++){
        if (tmpVehicle[i] != NULL && tmpVehicle[i]->getType() == atype){
            return true;
        }
    }
    return false;
}

void Station::incomingVehicle(std::vector<std::shared_ptr<Vehicle>> aVehicle) {
    for (int i=0; i<aVehicle.size(); i++) {
        std::cout << "pushing back: " << aVehicle[i]->getType() << " to station " << stationName << std::endl;
        stationVehicles.push_back(aVehicle[i]);
    }
}

void Station::printTypes() {
    for (int i = 0; i < stationVehicles.size(); i++) {
        std::cout << "Types: " << stationVehicles[i]->getType() << std::endl;
    }
}
