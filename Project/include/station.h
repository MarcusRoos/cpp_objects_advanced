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
 Class Station
 This class will handle all information regarding stations, it will store the
 stations name as well as the vehicles currently at that station. It contains
 different functions to return, initialize or print different values.
 It's partially used to store vehicles at a specific station so they can
 later be used and attached to trains.
 */
class Station {
protected:
    // private data members
    std::string stationName;
    std::vector<std::shared_ptr<Vehicle>> stationVehicles;
public:
    /**
* Default constructor
*
* @param None
* @return None.
*/
    Station();
    /**
* Initialized constructor, will initialize the two private data members with
* param values
*
* @param String and vector och shared pointers to vehicle
* @return None.
*/
    Station(std::string aStationname, std::vector<std::shared_ptr<Vehicle>> aVehicle);
    /**
* Default destructor
*
* @param None.
* @return None.
*/
    ~Station() = default;
    /**
* Returns stationname
*
* @param None.
* @return string.
*/
    std::string getStationname();
    /**
* Will return a shared pointer to vehicle, used for vehicles leaving the station
     * and being attached to trains
*
* @param Integer.
* @return Shared pointer to vehicle.
*/
    std::shared_ptr<Vehicle> outgoingVehicle(int atype);
    /**
* Will make sure arriving trains will arrive and disassemble properly at the
* station
*
* @param A vector of shared pointers to vehicle.
* @return None.
*/
    void incomingVehicle(const std::vector<std::shared_ptr<Vehicle>>& aVehicle);
    /**
* Prints information relevant to station
*
* @param None.
* @return None.
*/
    void printTypes();
    /**
* Tests if a vehicle exists
*
* @param Integer.
* @return Bool.
*/
    bool testVehicle(int atype);
    /**
* Returns a specific vehicle ID and its information, used to track a vehicles
* progress
*
* @param Integer.
* @return Bool.
*/
    bool getVehicleID(unsigned int aID);
};

#endif //DT060G_STATION_H
