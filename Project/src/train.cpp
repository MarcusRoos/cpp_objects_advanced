//
// Created by Marcus Roos on 2020-10-18.
// Mittuniversitet
// StudentID: Maro1904
//

#include "train.h"

#include <utility>

Train::Train() = default;

Train::Train(int aID, std::string aFrom, std::string aTo, int aDtime,
             int aAtime, double aSpeed, std::vector<int> aLogicalVehicles,
             std::string printD, std::string printA) {
    trainId = aID;
    fromStation = std::move(aFrom);
    toStation = std::move(aTo);
    departureTime = aDtime;
    arrivalTime = aAtime;
    tmpArrivalTime = aAtime;
    maxSpeed = aSpeed;
    logicalVehicles = std::move(aLogicalVehicles);
    state = NOTASSEMBLED;
    delayed = false;
    arrPrint = std::move(printA);
    depPrint = std::move(printD);
}

/**
 Tries to assemble the vehicles to the corresponding train once called. It
 returns a bool and accepts a vector pointer of station. It will
 check inside the passed down station if the required vehicles for the trains
 ID is at the departure station, if it is, it will push the first found
 vehicle to the trains vehicle list. This is using a simply for loop as it will
 iterate from the beginning to the end, thus ensuring that the vehicle
 with the lowest ID is chosen. If it fails it will inform the user.
*/
bool Train::assembleVehicle(const std::vector<std::shared_ptr<Station>>& aStation) {
    bool tester=true;
    std::vector<std::shared_ptr<Vehicle>> tmpVehicle;
    try {
        for (auto &k : aStation) {
            if (k->getStationname() == fromStation) {
                if (trainVehicles.empty()) {
                    for (int logicalVehicle : logicalVehicles) {
                        if (((k->testVehicle(logicalVehicle)))) {
                            trainVehicles.push_back(
                                    k->outgoingVehicle(
                                            logicalVehicle));

                        } else {
                            tester = false;
                        }
                    }
                } else {
                    tester = false;
                    break;
                }
            }
        }
    }
    catch(bool &tmpBool){
        std::cout << "Could not find assembleVehicleTrain" << std::endl;
    }

    return tester;
}

/**
 Used to disassemble a train, it works very similar to the assembleVehicle
 function but backwards, instead of attaching a vehicle to a train, we
 instead want to remove a vehicle from a train and add it to the station
 class. Hence why this and the above function is close to mirrored inside
 the station class.
*/
void Train::disassembleTrain(const std::vector<std::shared_ptr<Station>>& aStation) {
    for (auto & k : aStation) {
        if (k->getStationname() == toStation) {
            k->incomingVehicle(trainVehicles);
            trainVehicles.clear();
        }
    }
}

/**
 Used for printing current information about the trains and their current states.
*/
void Train::printTypes() {
    if (state == ARRIVED){
        std::cout << "Train " << trainId <<
        " has arrived at its destination and is waiting to be disassembled." << std::endl;
    }
    else if (state == FINISHED){
        std::cout << "Train " << trainId <<
                  " has arrived at its destination is finished." << std::endl;
    }
    else {
        if (!trainVehicles.empty()) {
            std::cout << "Train " << trainId << " " << getState(getState())
                      << " currently have these vehicles attached to it: "
                      << std::endl;
            for (auto &i : trainVehicles) {
                std::cout << "Vehicle Type: " << i->printType() << " ID: "
                          << i->getId() << std::endl;
            }
        }
        else {
            std::cout <<
            "There are currently no vehicles attached to this train" << std::endl;
        }
            std::cout << "It's departure station is " << fromStation
                      << " and arrival station is " << toStation << std::endl;
            std::cout << "Its scheduled to depart at " << getDepPrint()
                      << " and arrive at " << getArrPrint() << std::endl;

    }
}

/**
 Returns the different states in a string format instead of the usual numeric
 values as it is by default.
*/
std::string Train::getState(State) {
        switch (state) {
            case 0:
                return "NOTASSEMBLED";
            case 1:
                return "INCOMPLETE";
            case 2:
                return "ASSEMBLED";
            case 3:
                return "READY";
            case 4:
                return "RUNNING";
            case 5:
                return "ARRIVED";
            case 6:
                return "FINISHED";
            default:
                return "Null";
        }
}

/**
 Prints if a train has arrived at a station
*/
void Train::printAtStation(const std::string& tmpStat) {
    if ((state == ARRIVED || state == FINISHED) && tmpStat == toStation){
        std::cout <<"Train " <<getID()<< " has finished at " << toStation << std::endl;
    }
}

/**
 Prints all the completed vehicles, used for end statistics
*/
void Train::printComplete() {
    if ((state == ARRIVED || state == FINISHED) && !delayed){
                  std::cout << trainId << ",";
    }
}

/**
 Prints all the incompleted vehicles which never arrived at their end
 destination, used for end statistics.
*/
void Train::printIncomplete() {
    if (state == INCOMPLETE || state == NOTASSEMBLED
    || state == ASSEMBLED || state == READY){
                std::cout << trainId << ",";
    }
}

/**
 Uses vehicle ID from the param and prints relevant information to this train.
*/
bool Train::getVehicleID(unsigned int aID) {
    bool inTrain=false;
    try {
        for (auto &i : trainVehicles) {
            if (aID == i->getId()) {
                inTrain = true;
                std::cout << "Vehicle ID " << i->getId()
                          << " is attached to train "
                          << trainId << " and on route from " << fromStation
                          << " to " <<
                          toStation << std::endl;
            }
        }
    }
    catch(bool &inTrain){
        std::cout << "Could not find getVehicleIdTrain" << std::endl;
    }
    return inTrain;
}

/**
 Returns the ID of the train
*/
int Train::getID() {
    int tmpInt=0;
    try {
        tmpInt = trainId;
    }
    catch(int &tmpInt){
        std::cout << "No train ID could be found! " << tmpInt;
    }
    return tmpInt;
}

/**
 Returns departure station
*/
std::string Train::getFromStation() {
    std::string tmpString="fromStationError";
    try {
        tmpString = fromStation;
    }
    catch(std::string &tmpString){
        std::cout << "Not found: " << tmpString;
    }
    return tmpString;
}

/**
 Returns destination station
*/
std::string Train::getToStation() {
    std::string tmpString="toStationError";
    try {
        tmpString = toStation;
    }
    catch(std::string &tmpString){
        std::cout << "Not found: " << tmpString;
    }
    return tmpString;
}

/**
 Returns destination station in a printing format
*/
std::string Train::getArrPrint() {
    std::string tmpString="arrPrintError";
    try {
        tmpString = arrPrint;
    }
    catch(std::string &tmpString){
        std::cout << "Not found: " << tmpString;
    }
    return tmpString;
}

/**
 Returns departure station in a printing format
*/
std::string Train::getDepPrint() {
    std::string tmpString="depPrintError";
    try {
        tmpString = depPrint;
    }
    catch(std::string &tmpString){
        std::cout << "Not found: " << tmpString;
    }
    return tmpString;
}

/**
 Returns departure time
*/
int Train::getDepTime() {
    int tmpInt=0;
    try {
        tmpInt = departureTime;
    }
    catch(int &tmpInt){
        std::cout << "Not found departure time " << tmpInt;
    }
    return tmpInt;
}

/**
 Returns arrival time
*/
int Train::getArrTime() {
    int tmpInt=0;
    try {
        tmpInt = arrivalTime;
    }
    catch(int &tmpInt){
        std::cout << "Not found arrival time " << tmpInt;
    }
    return tmpInt;
}

/**
 Returns tmp arrival time, used to do calculations in the main program
*/
int Train::getTmpArrTime() {
    int tmpInt=0;
    try {
        tmpInt = tmpArrivalTime;
    }
    catch(int &tmpInt){
        std::cout << "Not found temp arrival time " << tmpInt;
    }
    return tmpInt;
}

/**
 Returns the trains current state
*/
enum State Train::getState() {
    State tmpState=STATEERROR;
    try {
        tmpState = state;
    }
    catch(State &tmpState){
        std::cout << "Not found state " << tmpState;
    }
    return tmpState;
}

/**
 Returns the trains max speed
*/
double Train::getSpeed() {
    double tmpDouble=0;
    try {
        tmpDouble = maxSpeed;
    }
    catch(double &tmpDouble){
        std::cout << "Not found max speed " << tmpDouble;
    }
    return tmpDouble;
}

/**
 Returns whether the train is delayed or not
*/
bool Train::getDelayed() {
    bool tmpBool=false;
    try {
        tmpBool = delayed;
    }
    catch(bool &tmpBool){
        std::cout << "Not found delayed " << tmpBool;
    }
    return tmpBool;
}
