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
protected:
    std::string accountNr;
    int balance;
public:
    Account();
    Account(std::string aNr, int b =0);
    virtual ~Account() = default;;
    void deposit(int sum) {balance +=sum;}
    virtual void withdrawal(int sum);
    virtual void setCredit(int cr){};
    virtual void setInterest(double inter){};
    int getBalance() const {return balance;}
    virtual std::string getAccountType() const =0;
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
    SavingsAccount();
    SavingsAccount(std::string aNr, int withdrawals=0, int b=0);
    virtual void setInterest(double inter);
    virtual void withdrawal(int sum);
    virtual std::string getAccountType();
    virtual double getInterest();
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
    LongSavingsAccount();
    LongSavingsAccount(std::string aNr, int withdrawals=0, int b=0){
        maxWithdrawals = 1;
        balance = b;
        accountNr = aNr;
    }
    virtual std::string getAccountType();
    virtual void withdrawal(int sum);
    virtual double getInterest();
    virtual void setInterest(double inter);
    virtual int getDisposable() const;
    virtual int getMaxWithdrawals() const;
    virtual int getNrOfWithdrawals() const;
};
#endif //DT060G_ACCOUNT_H
