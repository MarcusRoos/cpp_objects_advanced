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
    ~Map() = default;
    Map(std::string aDepstat, std::string adestStat, int aDist);
    void printMap();
    std::string getDepstat(){return depStat;}
    std::string getDestStat(){return destStat;}
    int getDistance(){return distance;}
};

#endif //DT060G_MAP_H
