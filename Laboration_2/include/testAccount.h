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
#include "BankKund.h"

class testAccount {
private:
    Menu menu;
    BankKund bankkund;
public:
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
    static bool numberVerify(const std::string &input);
    testAccount();
    void run();
};
#endif