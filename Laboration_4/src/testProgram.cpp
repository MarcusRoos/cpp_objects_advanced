//
// Created by Marcus Roos on 2020-10-10.
// Mittuniversitet
// StudentID: Maro1904
//

#include "testProgram.h"
#include <iostream>
#include <limits>


void testProgram::run() {
    DataFileReader<double> dataFileReader(datafilename,errorfilename);
    int choice = 0;
    std::cout << "Choice..." << std::endl;
    std::cin >> choice;
    while (std::cin.fail() || choice <1 || choice >14){
        std::cout << "Wrong input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> choice;
    }
    switch(choice)
    {
        case 1:
            dataFileReader.openFiles();
            while(dataFileReader.readNextValue(dummy)) {
                std::cout << "Dummy: " << dummy << std::endl;
            }
            break;
        case 2:
            break;
    }
}

/**
The testAccount constructor, adds menu items to determine which items are enabled
 as well as disabled by default, in this case all the options are available from
 the get go as a submenu is handling this part in this case.
*/
testProgram::testProgram(){
    std::cout << "TITLE " << std::endl;
    std::cout << "1. Run the program " << std::endl;
    std::cout << "2. Exit the program " << std::endl;
}

void testProgram::mainProgram() {

}
