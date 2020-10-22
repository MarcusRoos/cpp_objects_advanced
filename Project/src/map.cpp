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

void Map::printMap() {
    std::cout << depStat;
    std::cout << " -> " << destStat << std::endl;
    std::cout << "With a distance of: " << distance << std::endl;
}