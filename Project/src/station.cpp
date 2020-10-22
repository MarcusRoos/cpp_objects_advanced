//
// Created by Marcus Roos on 2020-10-19.
// Mittuniversitet
// StudentID: Maro1904
//

#include "station.h"

Station::Station() {
    stationName ="";
}

Station::Station(std::string aStationname, std::vector<std::shared_ptr<Vehicle>> aVehicle) {
    stationName = aStationname;
    stationVehicles = std::move(aVehicle);
}

void Station::printStation() {
    for (int i=0; i<stationVehicles.size(); i++){
    }
}
