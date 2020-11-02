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
             int aAtime, double aSpeed, std::vector<int> aLogicalVehicles) {
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
}


bool Train::assembleVehicle(const std::vector<std::shared_ptr<Station>>& aStation) {
    bool tester=true;
    std::cout << std::endl << std::endl;
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
            }  else {
                tester = false;
                    }

                }

            }
    return tester;
}

void Train::disassembleTrain(std::vector<std::shared_ptr<Station>> aStation) {
    for (size_t k = 0; k < aStation.size(); k++) {
        if (aStation[k]->getStationname() == toStation && trainVehicles[k] != nullptr) {
            aStation[k]->incomingVehicle(trainVehicles);
            trainVehicles.clear();
        }
    }
}

void Train::printTypes() {
    if (state == INCOMPLETE){
        std::cout << "incomplete: " << trainId << std::endl;
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
