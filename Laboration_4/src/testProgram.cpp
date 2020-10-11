//
// Created by Marcus Roos on 2020-10-10.
// Mittuniversitet
// StudentID: Maro1904
//

#include "testProgram.h"
#include <iostream>
#include <limits>

void testProgram::run() {
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
                std::cout << "Case 1 start" << std::endl;
                dataFileReader.openFiles();
                break;
            case 2:
                std::cout << "Case 2 exit" << std::endl;
                break;
        }
}

/**
The testAccount constructor, adds menu items to determine which items are enabled
 as well as disabled by default, in this case all the options are available from
 the get go as a submenu is handling this part in this case.
*/
testProgram::testProgram(DataFileReader<std::string> dataFileReader)
        : dataFileReader(dataFileReader) {
std::cout << "TITLE " << std::endl;
std::cout << "1. Run the program " << std::endl;
std::cout << "2. Exit the program " << std::endl;
}
