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
    std::vector<std::shared_ptr<Vehicle>> tmpVehicle;
    tmpVehicle = stationVehicles;
    for (int i=0; i<tmpVehicle.size(); i++){
        if (tmpVehicle[i]->getType() == atype && tmpVehicle[i] != NULL){
            std::cout << "Found! Type " << tmpVehicle[i]->getType() <<std::endl;
            std::cout << "Found! Seats " << tmpVehicle[i]->getSeats() <<std::endl;
            std::cout << "Found! ID " << tmpVehicle[i]->getId() <<std::endl;
            stationVehicles.erase(stationVehicles.begin() + i);
            return tmpVehicle[i];
        }
    }
    return NULL;
}

void Station::delVehicle() {

}
