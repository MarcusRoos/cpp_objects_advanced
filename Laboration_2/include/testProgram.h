//
// Created by Marcus Roos on 2020-09-08.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_TESTPROGRAM_H
#define DT060G_TESTPROGRAM_H
#include "Menu.h"
#include <fstream>
#include <vector>
#include "Account.h"

class testProgram {
private:
    Menu menu;
    Account account;
public:
    void setAccountNr();
    void addcurrBalance();
    void deductcurrBalance();
    void changeallCredit();
    void getcurrCredit();
    void getcurrBalance();
    void gettotalBalance();
    void accountInfo();
    static bool numberVerify(const std::string &input);
    testProgram();
    void run();
};
#endif