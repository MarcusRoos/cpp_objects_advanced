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

void Station::testStat() {
    int a, b, c, d;
    std::cout << "TestStat" << std::endl;
    stationName = "Grand Central";
    std::cout << stationName << std::endl;
    stationVehicles.push_back(std::unique_ptr<Vehicle>(
            new CoachCar(0,0,37,1)));
    stationVehicles.push_back(std::unique_ptr<Vehicle>(
            new CoachCar(0,0,37,1)));
    stationVehicles.push_back(std::unique_ptr<Vehicle>(
            new CoachCar(0,0,37,1)));
    std::cout << stationVehicles[0]->getType() << std::endl;
}
