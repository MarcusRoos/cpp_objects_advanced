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
    std::cout << std::endl << std::endl;
    std::vector<std::shared_ptr<Vehicle>> tmpVehicle;
    for (int k = 0; k < aStation.size(); k++) {
        if (aStation[k]->getStationname() == fromStation) {

            if (trainVehicles.empty()) {
                for (int i = 0; i < logicalVehicles.size(); i++) {
                    if (((aStation[k]->testVehicle(logicalVehicles[i])))) {
                        trainVehicles.push_back(
                                aStation[k]->outgoingVehicle(
                                        logicalVehicles[i]));

                    } else {
                        tester = false;
                    }
                }
            }
            else
                tester = false;

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

    if (state == INCOMPLETE) {
        std::cout << trainId << std::endl;
    }

}

void Train::emptyVehicle(std::vector<std::shared_ptr<Station>> aStation) {
    /*  for (int i=0; i<aStation.size(); i++){
          if (aStation[i]->getStationname() == fromStation){
                  aStation[i]->incomingVehicle(trainVehicles);
          }
      }
      trainVehicles.clear();
      */
}
