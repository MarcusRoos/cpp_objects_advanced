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
    tmpDepartureTime = aDtime;
    arrivalTime = aAtime;
    tmpArrivalTime = aAtime;
    maxSpeed = aSpeed;
    logicalVehicles = std::move(aLogicalVehicles);
    state = NOTASSEMBLED;
    delayed = false;
}


bool Train::assembleVehicle(std::vector<std::shared_ptr<Station>> aStation) {
    bool tester=true;
    std::vector<std::shared_ptr<Vehicle>> tmpVehicle;
        for (int k = 0; k < aStation.size(); k++) {
            if (aStation[k]->getStationname() == fromStation) {
                std::cout << "logicalVehicles " << std::endl;
                for (int j=0; j<logicalVehicles.size(); j++){
                    std::cout << logicalVehicles[j] << ",";
                }
                for (int i = 0; i < logicalVehicles.size(); i++) {
                    if (((aStation[k]->testVehicle(logicalVehicles[i])))) {
                        trainVehicles.push_back(
                                aStation[k]->outgoingVehicle(
                                        logicalVehicles[i]));
                        std::cout << std::endl << "trainVehicles" << std::endl;

                        for (int d=0; d<trainVehicles.size(); d++){
                            std::cout << trainVehicles[d]->getType() << ",";
                        }
                    }
                    else
                        tester = false;
                }
            }
    }
    return tester;
}

void Train::disassembleTrain(std::vector<std::shared_ptr<Station>> aStation) {
    for (int k = 0; k < aStation.size(); k++) {
        if (aStation[k]->getStationname() == toStation && trainVehicles[k] != NULL) {
            aStation[k]->incomingVehicle(trainVehicles);
            trainVehicles.clear();
        }
    }
}

void Train::printTypes() {
    std::cout << "Train Vehicles Types: " << std::endl;
    for (int i=0; i<trainVehicles.size(); i++){
        std::cout << trainVehicles[i]->getType() << std::endl;
    }
}

void Train::emptyVehicle(std::vector<std::shared_ptr<Station>> aStation) {
    for (int i=0; i<aStation.size(); i++){
        if (aStation[i]->getStationname() == fromStation){
                aStation[i]->incomingVehicle(trainVehicles);
        }
    }
    trainVehicles.clear();
}
