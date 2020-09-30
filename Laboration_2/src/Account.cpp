//
// Created by Marcus Roos on 2020-09-22.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Account.h"
#include <utility>

Account::Account() {
    accountNr="";
    currBalance=0;
    allCredit=DEFAULTSIZE;
}

Account::Account(std::string tmpNr, int tmpBal, int tmpCred) {
    accountNr=std::move(tmpNr);
    currBalance=tmpBal;
    allCredit=tmpCred;
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

std::string Account::accountInfo() {
        return accountNr;
}
