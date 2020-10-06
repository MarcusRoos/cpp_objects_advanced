//
// Created by Marcus Roos on 2020-09-22.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_ACCOUNT_H
#define DT060G_ACCOUNT_H
#include <iostream>
#include <string>

const int DEFAULTSIZE = 0;
class Account {
protected:
    std::string accountNr;
    int balance;
public:
    Account(std::string aNr, int b =0);
    virtual ~Account() = default;;
    void deposit(int sum) {balance +=sum;}
    virtual void withdrawal(int sum)=0;
    virtual void setCredit(int cr){};
    virtual void setInterest(double inter){};
    int getBalance() const {return balance;}
    virtual std::string getAccountType() {return 0;}
    virtual int getDisposable() const {return balance;}
    std::string accountInfo() const {return accountNr;}
    virtual int getMaxWithdrawals() const {return 0;}
    virtual int getNrOfWithdrawals() const {return 0;}
    virtual double getInterest() const {return 0;}
    virtual int getCredit() const {return 0;}
    virtual bool hasCredit() const {return false;}
    virtual bool hasInterest() const {return false;}
    virtual bool hasMaxWithdrawals() const {return false;}
};

/**
 * TRANSACTION ACCOUNT
 * **/
class TransactionAccount : public Account{
private:
    int credit;
public:
    TransactionAccount(std::string aNr1, int b1,
                       std::string aNr, int b, int c);
    virtual std::string getAccountType();
    virtual void setCredit(int cr);
    virtual int getCredit() const;
    virtual void withdrawal(int sum);
    virtual int getDisposable() const;
    virtual bool hasCredit() const;
};


/**
 * SAVINGS ACCOUNT
 * **/
class SavingsAccount : public Account{
protected:
    int withdrawals;
    int maxWithdrawals;
    double interest;
public:
    SavingsAccount(std::string aNr, int b);
    SavingsAccount(std::string aNr1, int b1, std::string aNr,
                   int b);
    virtual void setInterest(double inter);
    virtual void withdrawal(int sum);
    virtual std::string getAccountType();
    virtual double getInterest() const;
    virtual int getDisposable() const;
    virtual int getMaxWithdrawals() const;
    virtual int getNrOfWithdrawals() const;
    virtual bool hasInterest() const;
    virtual bool hasMaxWithdrawals() const;
};


/**
 * LONG SAVINGS ACCOUNT
 * **/
class LongSavingsAccount : public SavingsAccount{
public:
    LongSavingsAccount(std::string aNr1, int b1, std::string aNr,
                       int withdrawals = 0, int b = 0) : SavingsAccount(aNr1, b1) {
        maxWithdrawals = 1;
        balance = b;
        accountNr = aNr;
        interest = SavingsAccount::getInterest() + .02;
        withdrawals = 0;
    }
    virtual std::string getAccountType();
    virtual void withdrawal(int sum);
    virtual double getInterest() const;
    virtual void setInterest(double inter);
    virtual int getMaxWithdrawals() const;
    virtual int getNrOfWithdrawals() const;
};
#endif //DT060G_ACCOUNT_H
