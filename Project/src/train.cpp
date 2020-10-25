//
// Created by Marcus Roos on 2020-10-18.
// Mittuniversitet
// StudentID: Maro1904
//

#include "train.h"

Train::Train() {


}

Train::Train(int aID, std::string aFrom, std::string aTo, int aDtime,
        int aAtime, double aSpeed, std::vector<int> aLogicalVehicles) {
    trainId = aID;
    fromStation = aFrom;
    toStation = aTo;
    departureTime = aDtime;
    arrivalTime = aAtime;
    maxSpeed = aSpeed;
    logicalVehicles = std::move(aLogicalVehicles);
    state = UNASSMEBLED;
    delayed = true;
}


bool Train::assembleVehicle() {
    return true;
}

void Train::MegaTest(){
    std::cout << "From Station: " <<fromStation << std::endl;
    std::cout << "To Station: " << toStation << std::endl;
    std::cout << "ID: " << trainId << std::endl;
    for (int i=0; i<trainVehicles.size(); i++){
        std::cout << "Type: " << trainVehicles[i]->getType()<<std::endl;

    }
}