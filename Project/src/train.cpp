//
// Created by Marcus Roos on 2020-10-18.
// Mittuniversitet
// StudentID: Maro1904
//

#include "train.h"

Train::Train() {

    trainID = 0;
    speed = 0;
    typeEngine = "testEngine";
    depStat = "testDep";
    destStat = "testDest";
    depTime = "testDepTime";
    arrTime = "testArrTime";
}

void Train::trainTester() {
    trainlist.push_back(5);
    trainlist.push_back(3);
    trainlist.push_back(3);
    trainlist.push_back(3);
    typeEngine = "Test";
    for (auto v : trainlist){
        std::cout << v << std::endl;
    }


}
