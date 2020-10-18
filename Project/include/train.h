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
/**
 Class Train

 */
class Train {
protected:
    std::string dummy;
    std::vector<Vehicle>vehiclePtr;
public:
    Train();
    virtual ~Train() = default;;
};

#endif //DT060G_TRAIN_H
