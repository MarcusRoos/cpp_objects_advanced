//
// Created by Marcus Roos on 2020-09-22.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Account.h"

Account::Account() {
    accountNr=0;
    currBalance=0;
    allCredit=0;
}

void Account::setAccountNr(int personNumber) {
    accountNr = personNumber;
}

void Account::addcurrBalance(int balance) {
    currBalance += balance;
}

void Account::deductcurrBalance(int balanceRemove) {
    currBalance -= balanceRemove;
}

void Account::changeallCredit(int creditChange) {
    allCredit = creditChange;
}

int Account::getcurrCredit() {
    return allCredit;
}

int Account::getcurrBalance() {
    return currBalance;
}

int Account::gettotalBalance() {
    int tot=0;
    tot = currBalance+allCredit;
    return tot;
}

int Account::accountInfo() {
    return accountNr;
}
