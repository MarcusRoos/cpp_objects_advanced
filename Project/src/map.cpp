//
// Created by Marcus Roos on 2020-10-20.
// Mittuniversitet
// StudentID: Maro1904
//

#include "map.h"
#include <iostream>
#include <utility>

Map::Map() {

}

Map::Map(std::string aDepstat, std::string adestStat, int aDist) {
    distance = aDist;
    depStat = std::move(aDepstat);
    destStat = std::move(adestStat);
}

void Map::printMap(const std::string& aStat, const std::string& bStat) {
    if ((aStat == depStat && bStat == destStat) || (aStat == destStat && bStat == depStat)) {
    std::cout << distance << "km"<<std::endl;
    }
}