//
// Created by Marcus Roos on 2020-09-22.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Account.h"

Account::Account(std::string aNr, int b) {
    accountNr = aNr;
    balance = b;
}

/**
 * TRANSACTION ACCOUNT
 * **/
bool TransactionAccount::withdrawal(int sum) {
    if (balance > sum) {
        balance -= sum;
        return true;
    }
    else
        return false;
}

int TransactionAccount::getDisposable() const {
    return (balance + credit);
}

std::string TransactionAccount::getAccountType() {
    return "Transaction Account";
}

void TransactionAccount::setCredit(int cr) {
    credit = cr;
}

int TransactionAccount::getCredit() const {
    return credit;
}

TransactionAccount::TransactionAccount(std::string aNr1, int b1,
                                       std::string aNr, int b, int c)
        : Account(aNr1, b1) {
    credit = c;
    balance = b;
    accountNr = aNr;
}

/**
 * SAVINGS ACCOUNT
 * **/

bool SavingsAccount::withdrawal(int sum) {
    if (withdrawals < maxWithdrawals && balance > sum) {
        balance -= sum;
        withdrawals++;
        return true;
    }
    else
        return false;
}

SavingsAccount::SavingsAccount(std::string aNr, int b) : Account(aNr, b) {
    interest = 1.02;
    maxWithdrawals = 4;
    withdrawals = 0;
}

SavingsAccount::SavingsAccount(std::string aNr1, int b1, std::string aNr,
                               int b, double c) : Account(aNr1, b1) {
    accountNr = aNr;
    maxWithdrawals = 4;
    balance = b;
    interest = c;
    withdrawals = 0;
}

std::string SavingsAccount::getAccountType() {
    return "Savings Account";
}

double SavingsAccount::getInterest() const {
    return interest;
}

int SavingsAccount::getDisposable() const {
    return (balance * interest);
}

int SavingsAccount::getMaxWithdrawals() const {
    return maxWithdrawals;
}

int SavingsAccount::getNrOfWithdrawals() const {
    return withdrawals;
}

/**
 * LONG SAVINGS ACCOUNT
 * **/

LongSavingsAccount::LongSavingsAccount(std::string aNr, int b) : SavingsAccount(aNr,
                                                                         b) {
    interest = SavingsAccount::getInterest() + .02;
    withdrawals = 0;
    maxWithdrawals = 1;
}

bool LongSavingsAccount::withdrawal(int sum) {
    if (withdrawals == 0 && sum < balance) {
        balance -= sum;
        withdrawals = 1;
        return true;
    }
    else
        return false;
}

std::string LongSavingsAccount::getAccountType() {
    return "Long Savings Account";
}