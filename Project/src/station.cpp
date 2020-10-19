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
    const char startDelim='(', endDelim = ')';
    std::string namn;
    int aID, aType, c, d;
    std::ifstream inFile("TrainStation.txt");
    if (inFile.is_open()) {
        getline(inFile, namn, startDelim);

        while (getline(inFile, tmpANr)) {
            getline(inFile, tmpType);

        }
    }

}



/*
    int a=0, b=0, c=0, d=0;
    std::string Name, GrandC, Liege, Pancras, Dunedin, Milano, Luz, Shin;
    std::ifstream inFile("TrainStations.txt");
    if (inFile.is_open()){
        while (getline(inFile, Name)){
            std::cout << "Name: " << Name << std::endl;
            inFile >> a;
            std::cout<< "A: " << a << std::endl;
            if (a == 0) {
                stationName = "Grand Central";
                inFile.get();
                stationVehicles.push_back(std::unique_ptr<Vehicle>(
                        new CoachCar (1,1,1,1)));
                GrandC = Name;
            }
        }
    }
    std::cout << "TestStat" << std::endl;
    std::cout << GrandC;
    std::cout << stationName << std::endl;
    std::cout << stationVehicles[0]->getType() << std::endl;
    */

