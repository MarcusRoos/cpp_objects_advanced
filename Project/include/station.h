//
// Created by Marcus Roos on 2020-10-19.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_STATION_H
#define DT060G_STATION_H
#include "vehicle.h"
#include "constants.h"
#include <memory>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
/**
 Class Train

 */
class Station {
protected:
    std::string stationName;
    std::vector<std::shared_ptr<Vehicle>> stationVehicles;
public:
    Station();
    Station(std::string aStationname, std::vector<std::shared_ptr<Vehicle>> aVehicle);
    ~Station() = default;;
    std::string getStationname(){return stationName;}
    int getvecSize(){return stationVehicles.size();}
    std::shared_ptr<Vehicle> outgoingVehicle(int atype);
    void incomingVehicle(std::vector<std::shared_ptr<Vehicle>> aVehicle);
    void printTypes();
};

#endif //DT060G_STATION_H
