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
    state = UNASSMEBLED;
    delayed = false;
}


bool Train::assembleVehicle(std::vector<std::shared_ptr<Station>> aStation) {
    bool tester=true;
        for (int k = 0; k < aStation.size(); k++) {
            if (aStation[k]->getStationname() == fromStation) {
                for (int i = 0; i < logicalVehicles.size(); i++) {
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
    // Need train builder
    return tester;
}

void Train::MegaTest(){
    for (int i=0; i<trainVehicles.size(); i++){
        std::cout << "Type: " << trainVehicles[i]->getType()<<std::endl;

    }
}
