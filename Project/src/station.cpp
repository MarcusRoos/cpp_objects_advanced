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
    const std::string startDelim="(", endDelim = ")";

    std::vector<std::string> tmpStations;
    std::string Name;
    std::ifstream inFile("TrainStations.txt");
    if (inFile.is_open()){
        while (!inFile.eof()){
                getline(inFile, Name);
                tmpStations.push_back(Name);
            }
        }
    std::cout << "TestStat" << std::endl;
    for (int i=0; i<tmpStations.size(); i++){
        std::cout << "Vector " << i << " : "<<tmpStations[i] << std::endl;
    }
}
