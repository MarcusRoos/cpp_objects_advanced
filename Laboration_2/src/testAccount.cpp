//
// Created by Marcus Roos on 2020-09-08.
// Mittuniversitet
// StudentID: Maro1904
//

#include "testAccount.h"
#include <iostream>

/**
The run function, this function will be called in the main program, from here a
 it will enter a switch which will call another function from the menu class.
 Here the user will be able to choose what they would like to do with the
 program, at first only the first "create Queue" option will be a available
 as well as the exit option,
 once a queue has been created the rest of the options will open up.
*/
void testAccount::run() {
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
testAccount::testAccount() {
    menu.setTitle("**** Pointer menu ****");
    menu.addItem("Fetch customers name", true);
    menu.addItem("Fetch customers social security", true);
    menu.addItem("Fetch amount of customer accounts", true);
    menu.addItem("Fetch customers different account numbers", true);
    menu.addItem("Fetch balance, credit and total from specific account number", true);
    menu.addItem("Fetch customers total money", true);
    menu.addItem("Create new account", true);
    menu.addItem("Delete account", true);
    menu.addItem("Withdraw from account", true);
    menu.addItem("Deposit to account", true);
    menu.addItem("Change credit", true);
    menu.addItem("Write to file", true);
    menu.addItem("Read from file", true);
    menu.addItem("Exit", true);
}

void testAccount::setAccountNr() {

}

void testAccount::addcurrBalance() {

}

void testAccount::deductcurrBalance() {

}

void testAccount::changeallCredit() {

}

void testAccount::getcurrCredit() {

}

void testAccount::getcurrBalance() {

}

void testAccount::gettotalBalance() {

}

void testAccount::accountInfo() {

}

bool testAccount::numberVerify(const std::string &input) {
    return input.find_first_not_of("9876543210") == std::string::npos;
}
