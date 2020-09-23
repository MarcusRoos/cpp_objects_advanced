//
// Created by Marcus Roos on 2020-09-08.
// Mittuniversitet
// StudentID: Maro1904
//

#include "testProgram.h"

/**
The run function, this function will be called in the main program, from here a
 it will enter a switch which will call another function from the menu class.
 Here the user will be able to choose what they would like to do with the
 program, at first only the first "create Queue" option will be a available
 as well as the exit option,
 once a queue has been created the rest of the options will open up.
*/
void testProgram::run() {
    bool again = true;
    do
    {
        menu.printMenuItems();
        switch(menu.menuChoice())
        {
            case 1:
                setAccountNr();
                break;
            case 2:
                addcurrBalance();
                break;
            case 3:
                deductcurrBalance();
                break;
            case 4:
                changeallCredit();
                break;
            case 5:
                getcurrCredit();
                break;
            case 6:
                getcurrBalance();
                break;
            case 7:
                gettotalBalance();
                break;
            case 8:
                accountInfo();
                break;
            case 9:
                again=false;
                break;
        }
    }while(again);
}



/**
The testApp constructor, adds menu items to determine which items are enabled
 as well as disabled by default.
*/
testProgram::testProgram() {
    menu.setTitle("**** Array pointer queue ****");
    menu.addItem("Set account number", true);
    menu.addItem("Add current balance", true);
    menu.addItem("Deduct current balance", true);
    menu.addItem("Change credit", true);
    menu.addItem("Get current credit", true);
    menu.addItem("Get current balance", true);
    menu.addItem("Get current TOTAL balance", true);
    menu.addItem("Show account info", true);
    menu.addItem("Exit", true);
}

void testProgram::setAccountNr() {

}

void testProgram::addcurrBalance() {

}

void testProgram::deductcurrBalance() {

}

void testProgram::changeallCredit() {

}

void testProgram::getcurrCredit() {

}

void testProgram::getcurrBalance() {

}

void testProgram::gettotalBalance() {

}

void testProgram::accountInfo() {

}
