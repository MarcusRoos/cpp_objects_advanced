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
#include "Bank.h"

class testAccount {
private:
    Menu menu;
    Bank bank;
public:
    void printName();
    void printPrsnr();
    void printAmountofAccount();
    void printAccountInfo();
    void printBalCredTot();
    void printAllCash();
    bool createAccount();
    void deleteAccount();
    void withdrawAccount();
    void depositAccont();
    void changeCredit();
    void writeToFile();
    void readFromFile();
    void startAccount();
    static bool numberVerify(const std::string &input);
    testAccount();
    void run();
    void runSubMenu();
    void accountSummery();
};
#endif