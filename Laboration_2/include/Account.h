//
// Created by Marcus Roos on 2020-09-22.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_ACCOUNT_H
#define DT060G_ACCOUNT_H
class Account {
private:
    int accountNr;
    int currBalance;
    int allCredit;
public:
    void setAccountNr();
    void addcurrBalance();
    void deductcurrBalance();
    void changeallCredit();
    int getcurrCredit();
    int getcurrBalance();
    int gettotalBalance();
    int accountInfo();
};
#endif //DT060G_ACCOUNT_H
