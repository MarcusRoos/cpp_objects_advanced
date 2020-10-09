//
// Created by Marcus Roos on 2020-09-08.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_TESTACCOUNT_H
#define DT060G_TESTACCOUNT_H
#include "Menu.h"
#include <fstream>
#include <vector>
#include <string>
#include "Bank.h"
//------------------------------------------------------------------------------
// Class definition
//------------------------------------------------------------------------------
/**
 Class testAccount

Handles all the input and output between bank classes and the user. As all other
 classes are silent classes and silent functions, all the input and
 output needs to be handled through a separate class, this class.
 */
class testAccount {
private:
    // Creates an object of menu, to be able to print the menu and
    // it's items.
    Menu menu;
    // Creates an object of bank, to be able to access the bank and
    // it's items.
    Bank bank;
public:
    /**
All the below functions will be documented in a single scope due to their similar
     usage. Each function has the task to handle user input and call the
     relevant functions within the previously created bank object. All the
     functions are void and take no input parameters, that will instead
     be handled in the bank class.
 */
    testAccount();
    void printName();
    void printPrsnr();
    void printAmountofAccount();
    void printAccountInfo();
    void printBalCredTot();
    void printAllCash();
    void createAccount();
    void deleteAccount();
    void withdrawAccount();
    void depositAccont();
    void changeCredit();
    void writeToFile();
    void readFromFile();
    void startAccount();
    void run();
    void runSubMenu();
    void accountSummery();
    /**
* Verifies so that input is valid
*
* @param A dereference to a string.
* @return A bool value, true/false.
*/
    static bool numberVerify(const std::string &input);
};
#endif