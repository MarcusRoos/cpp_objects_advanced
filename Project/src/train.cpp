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

Train::Train(int aID, std::string aFrom, std::string aTo, std::string aDtime,
        std::string aAtime, double aSpeed, std::vector<int> aLogicalVehicles) {
    trainId = aID;
    fromStation = aFrom;
    toStation = aTo;
    departureTime = aDtime;
    arrivalTime = aAtime;
    maxSpeed = aSpeed;
    logicalVehicles = std::move(aLogicalVehicles);
}

void
Train::assembleVehicle(std::vector<std::shared_ptr<Vehicle>> atrainVehicles) {
    trainVehicles = std::move(atrainVehicles);
    int k=0;
    for (int i=0; i<trainVehicles.size(); i++){
        k++;
    }
    std::cout << "Loaded train: " <<k << std::endl;
    std::cout << "Name: " << getDepname() << std::endl;
}
