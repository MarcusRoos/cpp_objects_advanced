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

void Station::printStation(int aType) {
    int k=0;
    for (int i=0; i<stationVehicles.size(); i++){
        if (stationVehicles[i]->getType() == aType)
            k++;
    }
    std::cout << "K: " << k << std::endl;
}

std::shared_ptr<Vehicle> Station::outgoingVehicle(int atype) {
    for (int i=0; i<stationVehicles.size(); i++){
        if (stationVehicles[i]->getType() == atype){
            std::cout << "Found!" << std::endl;
            return stationVehicles[i];
        }
    }
    return 0;
}

void Station::manipulateVehicleTest() {
    stationName = stationName + "b";
}
