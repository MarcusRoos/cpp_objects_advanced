//
// Created by Marcus Roos on 2020-09-22.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_ACCOUNT_H
#define DT060G_ACCOUNT_H
#include <string>
//------------------------------------------------------------------------------
// Class definition
//------------------------------------------------------------------------------
/**
 Class Account

Handles the different accounts for one customer, one base class to take care
 of all the other subclasses, non-virtual functions have been inline
 defined here, and the virtual functions are being redefined in the subclasses,
 while the pure virtual functions will only be defined in the subclasses.
 */
class Account {
protected:
    std::string accountNr;
    int balance;
public:
    /**
* Defaults account constructor, initializes accountNr and balance
*
* @param string aNr, int b=0.
* @return None.
*/
    Account(std::string aNr, int b =0);
    /**
* Virtual function to deconstruct, makes sure all the accounts get deconstructed
     * properly
*
* @param None.
* @return None.
*/
    virtual ~Account() = default;;
    /**
* Deposits balance into an account, same for all classes
*
* @param int sum
* @return None.
*/
    void deposit(int sum) {balance +=sum;}
    /**
* Withdraws money from an account, pure virtual function
*
* @param int sum
* @return True/False.
*/
    virtual bool withdrawal(int sum)=0;
    /**
* Sets credit for an account, virtual
*
* @param int cr
* @return None.
*/
    virtual void setCredit(int cr){};
    /**
* Returns balance for an account, same for all account types
*
* @param None
* @return int balance.
*/
    int getBalance() const {return balance;}
    /**
* Returns name of the account type, pure virtual, different for all the
     * account types, pure virtual.
*
* @param None
* @return string
*/
    virtual std::string getAccountType() {return 0;}
    /**
* Returns the disposable money of an account, returns balance if
     * it isn't redefined, virtual.
* @param None
* @return int
*/
    virtual int getDisposable() const {return balance;}
    /**
* Returns account info, the account number for an account, same for all
     * account types
* @param None
* @return string accountNr
*/
    std::string accountInfo() const {return accountNr;}
    /**
* Returns maximum withdrawals allowed for the account type, pure virtual
* @param None
* @return int
*/
    virtual int getMaxWithdrawals() const {return 0;}
    /**
* Returns current amount of withdrawals for the specified account, pure
     * virtual
* @param None
* @return int
*/
    virtual int getNrOfWithdrawals() const {return 0;}
    /**
* Returns the interest for the specified account, pure virtual
* @param None
* @return double
*/
    virtual double getInterest() const {return 0;}
    /**
* Returns the credit for the specified account, pure virtual
* @param None
* @return int
*/
    virtual int getCredit() const {return 0;}
};

/**
 * TRANSACTION ACCOUNT
 * Transaction account is being defined and the relevant functions redefined
 * below
 * **/
class TransactionAccount : public Account{
private:
    int credit;
public:
    /**
* Constructor for transaction account, constructs the base class "Account" before
     * constructing the subclass "Transaction Account".
* @param string aNr1, int b1, string aNr, int b, int c
* @return None.
*/
    TransactionAccount(std::string aNr1, int b1,
                       std::string aNr, int b, int c);
    /**
* Returns the account type for this account type as a string
* @param None
* @return string "Transaction Account"
*/
    virtual std::string getAccountType();
    /**
* Sets the credit for this account
* @param int cr
* @return None
*/
    virtual void setCredit(int cr);
    /**
* Returns the credit for this account
* @param None
* @return int credit
*/
    virtual int getCredit() const;
    /**
* Withdraws money from this account
* @param int sum
* @return True/False
*/
    virtual bool withdrawal(int sum);
    /**
* Returns the total disposable funds of this account
* @param None
* @return int
*/
    virtual int getDisposable() const;
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
    /**
* Constructor for Savings account
* @param string aNr, int b
* @return None.
*/
    SavingsAccount(std::string aNr, int b);
    /**
* Constructor for Savings account, constructs the base class "Account" before
 * constructing the subclass "Savings Account".
* @param string aNr1, int b1, string aNr, int b, double c
* @return None.
*/
    SavingsAccount(std::string aNr1, int b1, std::string aNr,
                   int b, double c);
    /**
* Withdraws money from this account
* @param int sum
* @return True/False
*/
    virtual bool withdrawal(int sum);
    /**
* Returns the account type for this account type as a string
* @param None
* @return string "Savings Account"
*/
    virtual std::string getAccountType();
    /**
* Returns interest for this account
* @param None
* @return double
*/
    virtual double getInterest() const;
    /**
* Returns total disposable funds of this account
* @param None
* @return int
*/
    virtual int getDisposable() const;
    /**
* Returns the maximum amount of available withdrawals for this account
* @param None
* @return int
*/
    virtual int getMaxWithdrawals() const;
    /**
* Returns the current amount of withdrawals made for this account
* @param None
* @return int
*/
    virtual int getNrOfWithdrawals() const;
};


/**
 * LONG SAVINGS ACCOUNT
 * **/
class LongSavingsAccount : public SavingsAccount{
public:
    /**
* Constructor for Long savings account
* @param string aNr, int b
* @return None.
*/
    LongSavingsAccount(std::string aNr, int b);
    /**
* Constructor for long savings account, constructs the sub class "Savings" before
 * constructing the subclass "long savings Account".
* @param string aNr1, int b1, string aNr, int b, double c
* @return None.
*/
    LongSavingsAccount(std::string aNr1, int b1, std::string aNr,
                       int b = 0, double c = 0) : SavingsAccount(aNr1, b1) {
        maxWithdrawals = 1;
        balance = b;
        accountNr = aNr;
        interest = c;
    }
    /**
* Returns the account type for this account type as a string
* @param None
* @return string "Long Savings Account"
*/
    virtual std::string getAccountType();
    /**
* Withdraws money from this account
* @param int sum
* @return True/False
*/
    virtual bool withdrawal(int sum);
};
#endif //DT060G_ACCOUNT_H
