//
// Created by Marcus Roos on 2020-09-22.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_ACCOUNT_H
#define DT060G_ACCOUNT_H

#include <string>

const int DEFAULTSIZE = 0;
class Account {
private:
    std::string accountNr;
    int currBalance;
    int allCredit;
public:
    Account();
    void addcurrBalance(int balance);
    void deductcurrBalance(int balanceRemove);
    void changeallCredit(int creditChange);
    int getcurrCredit();
    int getcurrBalance();
    int gettotalBalance();
    std::string accountInfo();
};
#endif //DT060G_ACCOUNT_H
