//
// Created by Marcus Roos on 2020-10-18.
// Mittuniversitet
// StudentID: Maro1904
//

#include "train.h"

#include <utility>

Train::Train() {


}

Train::Train(int aID, std::string aFrom, std::string aTo, int aDtime,
             int aAtime, double aSpeed, std::vector<int> aLogicalVehicles,
             std::string printD, std::string printA) {
    trainId = aID;
    fromStation = std::move(aFrom);
    toStation = std::move(aTo);
    departureTime = aDtime;
    tmpDepartureTime = aDtime;
    arrivalTime = aAtime;
    tmpArrivalTime = aAtime;
    maxSpeed = aSpeed;
    logicalVehicles = std::move(aLogicalVehicles);
    state = NOTASSEMBLED;
    delayed = false;
    arrPrint = std::move(printA);
    depPrint = std::move(printD);
}


bool Train::assembleVehicle(const std::vector<std::shared_ptr<Station>>& aStation) {
    bool tester=true;
    std::vector<std::shared_ptr<Vehicle>> tmpVehicle;
    for (auto & k : aStation) {
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

    return tester;
}

void Train::disassembleTrain(const std::vector<std::shared_ptr<Station>>& aStation) {
    for (auto & k : aStation) {
        if (k->getStationname() == toStation) {
            k->incomingVehicle(trainVehicles);
            trainVehicles.clear();
        }
    }
}

void Train::printTypes() {
    std::cout << "Train " << trainId << " " << getState(getState())
    << " currently have these vehicles attached to it: " << std::endl;
    for (auto & i : trainVehicles){
        std::cout << "Vehicle Type: " << i->printType() << " ID: "
        << i->getId() << std::endl;
    }
    std::cout << "It's leaving from station " << fromStation
    << " and heading for " << toStation << std::endl;
    std::cout << "It will depart at " << getDepPrint() << " and arrive at "
    << getArrPrint() << std::endl;
}

std::string Train::getState(State) {
    switch(state)
    {
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

void Train::printIncomplete() {
    if (state == INCOMPLETE){
        std::cout << "Incomplete: " <<trainId << std::endl;
    }
}
