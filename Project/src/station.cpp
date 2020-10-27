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
    std::cout <<"We are at station: " <<stationName << std::endl;
    for (int i=0; i<tmpVehicle.size(); i++){
        if (tmpVehicle[i] != NULL && tmpVehicle[i]->getType() == atype){
            std::cout << "stationvehicleSIZE: " << stationVehicles.size();
            std::cout << "Type in Station (TmpVehicle[i]: "  << tmpVehicle[i]->getType() << std::endl;
            std::cout << "Type in Station (aType:) "  << atype << std::endl;
            stationVehicles.erase(stationVehicles.begin() + i);
            return tmpVehicle[i];
        }
    }
    return NULL;
}

void Station::incomingVehicle(std::vector<std::shared_ptr<Vehicle>> aVehicle) {
    std::cout << "stationname: " << stationName << std::endl;
    for (int i=0; i<aVehicle.size(); i++) {
        stationVehicles.push_back(aVehicle[i]);
    }
}
