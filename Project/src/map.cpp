//
// Created by Marcus Roos on 2020-10-20.
// Mittuniversitet
// StudentID: Maro1904
//

#include "map.h"
#include <iostream>

Map::Map() {

}

Map::Map(std::string aDepstat, std::string adestStat, int aDist) {
    distance = aDist;
    depStat = aDepstat;
    destStat = adestStat;
}

void Map::printMap(const std::string& aStat, const std::string& bStat) {
    if ((aStat == depStat && bStat == destStat) || (aStat == destStat && bStat == depStat)) {
    std::cout << distance << std::endl;
    }
}