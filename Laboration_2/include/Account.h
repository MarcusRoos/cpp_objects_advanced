//
// Created by Marcus Roos on 2020-09-22.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_ACCOUNT_H
#define DT060G_ACCOUNT_H
const int DEFAULTSIZE = 0;
class Account {
private:
    int accountNr;
    int currBalance;
    int allCredit;
public:
    Account();
    void setAccountNr(int personNumber);
    void addcurrBalance(int balance);
    void deductcurrBalance(int balanceRemove);
    void changeallCredit(int creditChange);
    int getcurrCredit();
    int getcurrBalance();
    int gettotalBalance();
    int accountInfo();
};
#endif //DT060G_ACCOUNT_H
