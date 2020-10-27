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
        for (int k = 0; k < aStation.size(); k++) {
            if (aStation[k]->getStationname() == fromStation) {
                for (int i = 0; i < logicalVehicles.size(); i++) {
                    std::cout <<"Type in train: " << logicalVehicles[i] << std::endl;
                    if ((aStation[k]->outgoingVehicle(logicalVehicles[i]) !=
                         NULL)) {
                        trainVehicles.push_back(
                                aStation[k]->outgoingVehicle(
                                        logicalVehicles[i]));
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
