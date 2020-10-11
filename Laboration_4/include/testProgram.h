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
    DataFileReader<std::string> dataFileReader;
public:
    testProgram(DataFileReader<std::string> dataFileReader);
    void run();
};

#endif //DT060G_TESTPROGRAM_H
