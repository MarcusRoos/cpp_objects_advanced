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

bool TransactionAccount::hasCredit() const {
    return credit > 0;
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
    std::cout << "MAX SAVING " << maxWithdrawals << std::endl;
    std::cout << "WITH SAVING " << withdrawals << std::endl;
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
    maxWithdrawals = 0;
    withdrawals = 0;
}

SavingsAccount::SavingsAccount(std::string aNr1, int b1, std::string aNr,
                               int b) : Account(aNr1, b1) {
    accountNr = aNr;
    maxWithdrawals = 4;
    balance = b;
    interest = 1.02;
    withdrawals = 0;
}

std::string SavingsAccount::getAccountType() {
    return "Savings Account";
}

void SavingsAccount::setInterest(double inter) {
    interest = inter;
}

double SavingsAccount::getInterest() const {
    return interest;
}

int SavingsAccount::getDisposable() const {
    return balance;
}

int SavingsAccount::getMaxWithdrawals() const {
    return maxWithdrawals;
}

int SavingsAccount::getNrOfWithdrawals() const {
    return withdrawals;
}

bool SavingsAccount::hasInterest() const {
    return interest > 0;
}

bool SavingsAccount::hasMaxWithdrawals() const {
    return maxWithdrawals > 0;
}

/**
 * LONG SAVINGS ACCOUNT
 * **/
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

double LongSavingsAccount::getInterest() const {
    return interest;
}

void LongSavingsAccount::setInterest(double inter) {
    interest = inter;
}


int LongSavingsAccount::getMaxWithdrawals() const {
    return maxWithdrawals;
}

int LongSavingsAccount::getNrOfWithdrawals() const {
    return withdrawals;
}