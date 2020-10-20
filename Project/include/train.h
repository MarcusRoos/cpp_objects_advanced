//
// Created by Marcus Roos on 2020-10-18.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_TRAIN_H
#define DT060G_TRAIN_H
#include <string>
#include <memory>
#include <vector>
#include "vehicle.h"
#include <list>
#include <iostream>
/**
 Class Train

 */
class Train {
protected:
    std::list<int> trainlist;
    int trainID, speed;
    std::string typeEngine, depStat, destStat, depTime, arrTime;
    std::vector<std::unique_ptr<Vehicle>> assembleVehicles;
public:
    Train();
    ~Train() = default;;
    void trainTester();
};

#endif //DT060G_TRAIN_H
