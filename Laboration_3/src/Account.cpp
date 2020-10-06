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
void TransactionAccount::withdrawal(int sum) {
    balance -= sum;
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

void SavingsAccount::withdrawal(int sum) {
    if (maxWithdrawals < withdrawals) {
        balance -= sum;
        withdrawals++;
    }
    else
        balance = balance;
}

/**
 * SAVINGS ACCOUNT
 * **/
SavingsAccount::SavingsAccount(std::string aNr, int b) : Account(aNr, b) {
    interest = 1.02;
    maxWithdrawals = 4;
}

SavingsAccount::SavingsAccount(std::string aNr1, int b1, std::string aNr,
                               int withdrawals, int b) : Account(aNr1, b1) {
    accountNr = aNr;
    maxWithdrawals = withdrawals;
    balance = b;
}

std::string SavingsAccount::getAccountType() {
    return "Savings Account";
}

void SavingsAccount::setInterest(double inter) {
    interest = inter;
}

double SavingsAccount::getInterest() {
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

bool SavingsAccount::hasInterest() const {
    return interest > 0;
}

bool SavingsAccount::hasMaxWithdrawals() const {
    return maxWithdrawals > 0;
}

/**
 * LONG SAVINGS ACCOUNT
 * **/
void LongSavingsAccount::withdrawal(int sum) {
    if (maxWithdrawals > 0) {
        balance -= sum;
        withdrawals = 0;
    }
    else
        balance = balance;
}

std::string LongSavingsAccount::getAccountType() {
    return "Long Savings Account";
}

double LongSavingsAccount::getInterest() {
    return interest;
}

void LongSavingsAccount::setInterest(double inter) {
    interest = inter;
}

int LongSavingsAccount::getDisposable() const {
    return (balance * interest);
}

int LongSavingsAccount::getMaxWithdrawals() const {
    return maxWithdrawals;
}

int LongSavingsAccount::getNrOfWithdrawals() const {
    return withdrawals;
}

LongSavingsAccount::LongSavingsAccount(std::string aNr, int b)
        : SavingsAccount(aNr, b) {

}
