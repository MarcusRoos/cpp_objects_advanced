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
    std::ifstream inFile("TrainStations.txt");
    if (inFile.is_open()) {
        while (getline(inFile, namn, startDelim)) {
            inFile >> aID;
            inFile >> aType;
            inFile >> c;
            if (c == startDelim || c == endDelim) {
                inFile.get();
            }
            inFile >> d;
            if (d == startDelim || d == endDelim) {
                inFile.get();
            } else
                inFile.get();
            std::cout << "ID: " << aID << std::endl;
            std::cout << "aType: " << aType << std::endl;
            std::cout << "c: " << c << std::endl;
            std::cout << "d: " << d << std::endl;
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

