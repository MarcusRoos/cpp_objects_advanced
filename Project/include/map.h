//
// Created by Marcus Roos on 2020-10-20.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_MAP_H
#define DT060G_MAP_H

#include <string>
#include <vector>
#include <memory>
#include "vehicle.h"
/**
 Class Map

 */
class Map {
protected:
    int distance;
    std::string depStat, destStat;
public:
    Map();
    ~Map() = default;;
};

#endif //DT060G_MAP_H
