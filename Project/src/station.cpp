//
// Created by Marcus Roos on 2020-10-19.
// Mittuniversitet
// StudentID: Maro1904
//

#include "station.h"

Station::Station() {
    stationName ="";
}

Station::Station(std::string aStationname, std::vector<std::unique_ptr<Vehicle>> aVehicle) {
    stationName = aStationname;
    stationVehicles = std::move(aVehicle);
}

void Station::testStat(std::string aName) {
    stationName = aName;
}

void Station::printStation() {
    for (int i=0; i<stationVehicles.size(); i++){
        if (stationVehicles[i]->getType() == 5) {
            std::cout << "ID: " << stationVehicles[i]->getId() << std::endl;
            std::cout << "Type:" << stationVehicles[i]->getType() << std::endl;
        }
    }
}
