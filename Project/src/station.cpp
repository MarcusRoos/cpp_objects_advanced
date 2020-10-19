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


    int a=0, b=0, c=0, d=0;
    std::string Name;
    std::ifstream inFile("TrainStations.txt");
    if (inFile.is_open()){
        getline(inFile, Name);
        std::cout << "Name: " << Name << std::endl;
            inFile >> a;
            std::cout<< "A: " << a << std::endl;
                stationName = "Grand Central";
                inFile >> b;
                inFile >> c;
                inFile >> d;
                inFile.get();
                std::cout<< "B: " << b << std::endl;
                std::cout<< "C: " << c << std::endl;
                std::cout<< "D: " << d << std::endl;
                stationVehicles.push_back(std::unique_ptr<Vehicle>(
                        new CoachCar(a,b,c,d)));


    }
    std::cout << "TestStat" << std::endl;
    std::cout << stationName << std::endl;
    std::cout << stationVehicles[0]->getType() << std::endl;
}
