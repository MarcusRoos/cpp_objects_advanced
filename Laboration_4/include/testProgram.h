//
// Created by Marcus Roos on 2020-10-10.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_TESTPROGRAM_H
#define DT060G_TESTPROGRAM_H
#include "DataFileReader.h"
#include "DataFilter.h"

class testProgram {
private:
    double dummy=0;
    std::string datafilename = "Values.dat";
    std::string errorfilename = "ReadErrors.dat";
public:
    testProgram();
    void run();
    void mainProgram();
};

#endif //DT060G_TESTPROGRAM_H
