//
// Created by Marcus Roos on 2020-10-10.
// Mittuniversitet
// StudentID: Maro1904
//

#include "testProgram.h"
#include <iostream>

void testProgram::run() {
    bool again = true;
    do
    {
        menu.printMenuItems();
        switch(menu.menuChoice())
        {
            case 1:
                std::cout << "Case 1 start" << std::endl
                break;
            case 2:
                std::cout << "Case 2 exit" << std::endl
                again=false;
                break;
        }
    }while(again);
}

/**
The testAccount constructor, adds menu items to determine which items are enabled
 as well as disabled by default, in this case all the options are available from
 the get go as a submenu is handling this part in this case.
*/
testProgram::testProgram() {
    menu.setTitle("**** Pointer menu ****");
    menu.addItem("Run", true);
    menu.addItem("Exit", true);
}
