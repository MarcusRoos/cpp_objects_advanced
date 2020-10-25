//
// Created by Marcus Roos on 2020-10-18.
// Mittuniversitet
// StudentID: Maro1904
//

#include "train.h"

Train::Train() {


}

void Train::trainTester() {
    std::cout << std::endl;
    std::cout << "ID: " << trainId << std::endl;
    std::cout << "From: " << fromStation << std::endl;
    std::cout << "To: " << toStation << std::endl;
    std::cout << "Dep Time: " << departureTime << std::endl;
    std::cout << "Arr Time: " << arrivalTime << std::endl;
    std::cout << "Speed: " << maxSpeed << std::endl;
    for (int i=0; i<logicalVehicles.size(); i++){
        std::cout << "Vehicle: " << logicalVehicles[i] << std::endl;
    }
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
}

void
Train::assembleVehicle(std::vector<std::shared_ptr<Vehicle>> atrainVehicles) {
    trainVehicles = std::move(atrainVehicles);
}

void Train::printTest() {
    std::cout  << "Train Vehicles: " << trainVehicles.size() << std::endl;
}

std::vector<int> Train::getLogicalVehicles() {
    std::vector<int> tmpVec;

    for (int i=0; i<logicalVehicles.size(); i++){
         tmpVec.push_back(logicalVehicles[i]);
    }
    return tmpVec;
}

void Train::MegaTest(){
    std::cout << "From Station: " <<fromStation << std::endl;
    std::cout << "To Station: " << toStation << std::endl;
    for (int i=0; i<trainVehicles.size(); i++){
        std::cout << "Type: " << trainVehicles[i]->getType()<<std::endl;

    }
}

bool Train::assembleTrain() {
    return false;
}
