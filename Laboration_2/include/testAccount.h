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
    void setAccountNr();
    void addcurrBalance();
    void deductcurrBalance();
    void changeallCredit();
    void getcurrCredit();
    void getcurrBalance();
    void gettotalBalance();
    void accountInfo();
    static bool numberVerify(const std::string &input);
    testAccount();
    void run();
};
#endif