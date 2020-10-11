#include "DataFilter.h"
#include "DataFileReader.h"
#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <fstream>
//#include "memstat.hpp"

int main() {

    double dummy=0;
    std::string datafilename = "Values.dat";
    std::string errorfilename = "ReadErrors.dat";

    DataFileReader<double> dataFileReader(datafilename, errorfilename);
    dataFileReader.openFiles();

    DataFilter<double> dataFilter(&dataFileReader, 0.0, 10.0);
    dataFilter.getNextValue(dummy);

    return 0;
}
