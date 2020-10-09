//
// Created by Marcus Roos on 2020-09-22.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Account.h"

/**
The constructor, will construct the account base class with account number
 and balance
*/
Account::Account(std::string aNr, int b) {
    accountNr = aNr;
    balance = b;
}

/**
 * TRANSACTION ACCOUNT
 * **/
/**
The constructor, will construct the account base class with account number
and balance, then construct the transaction account class with the balance and
 accountnumber, as well as credit.
*/
TransactionAccount::TransactionAccount(std::string aNr1, int b1,
                                       std::string aNr, int b, int c)
        : Account(aNr1, b1) {
    credit = c;
    balance = b;
    accountNr = aNr;
}

/**
Withdrawal function for transaction account, will make sure the
 requested withdrawal amount is less than the balance + credit for the account.
 Can do into the negatives if the user withdraw more than their balance allows,
 effectively utilizing credit to do so. Returns true if successful, otherwise false
*/
bool TransactionAccount::withdrawal(int sum) {
    if (balance+credit > sum) {
        balance -= sum;
        return true;
    }
    else
        return false;
}

/**
Returns the total disposable fund on the transaction account, will return the
 result as an integer, the maximum disposable is the sum of balance
 and credit
*/
int TransactionAccount::getDisposable() const {
    return (balance + credit);
}

/**
Returns the name of this account type as a string "Transaction Account"
*/
std::string TransactionAccount::getAccountType() {
    return "Transaction Account";
}

/**
Sets the credit on the account, also used to change the current credit to
  a new value, accepts integer as param
*/
void TransactionAccount::setCredit(int cr) {
    credit = cr;
}

/**
Returns the credit of the account as an integer
*/
int TransactionAccount::getCredit() const {
    return credit;
}

/**
 * SAVINGS ACCOUNT
 * **/
/**
The constructor, will construct the account base class with account number
and balance, then construct the savings account class with the balance and
 accountnumber, as well as interest, will also set the default values such as
 maximum allowed of withdrawals, the standard 1.02 (2%) interest rates, and make
 sure the current withdrawals for the newly made account is set to 0.
*/
SavingsAccount::SavingsAccount(std::string aNr, int b) : Account(aNr, b) {
    interest = 1.02;
    maxWithdrawals = 4;
    withdrawals = 0;
}
/**
The constructor, will construct the account base class with account number
and balance, then construct the savings account class with the balance and
 accountnumber, as well as interest, will also set the default values such as
 maximum allowed of withdrawals, the standard 1.02 (2%) interest rates, and make
 sure the current withdrawals for the newly made account is set to 0. This
 function isn't vastly different from the above constructor, but instead the
 above constructor will use pre-determined values whereas
 this one will use user-defined values.
*/
SavingsAccount::SavingsAccount(std::string aNr1, int b1, std::string aNr,
                               int b, double c) : Account(aNr1, b1) {
    accountNr = aNr;
    maxWithdrawals = 4;
    balance = b;
    interest = c;
    withdrawals = 0;
}

/**
Withdrawal function for the savings account, will accept integer as input
 and make sure the account have enough funds to support such a withdrawal, it
 will also verify whether the account has reached its maximum allowed
 withdrawals or not. The allowed withdrawal amount is composed of
 the balance multiplied by the interest. Returns true if successful, otherwise
 false
*/
bool SavingsAccount::withdrawal(int sum) {
    if (withdrawals < maxWithdrawals && (balance*interest) > sum) {
        balance *= interest;
        balance -= sum;
        withdrawals++;
        return true;
    }
    else
        return false;
}
/**
Returns the name of this account type as a string "Savings Account"
*/
std::string SavingsAccount::getAccountType() {
    return "Savings Account";
}
/**
Returns the interest of this account as a double
*/
double SavingsAccount::getInterest() const {
    return interest;
}
/**
Returns the total disposable amount of this account, the product of
 balance and interest
*/
int SavingsAccount::getDisposable() const {
    return (balance * interest);
}
/**
Returns the maximum withdrawals allowed for this account type as an integer
*/
int SavingsAccount::getMaxWithdrawals() const {
    return maxWithdrawals;
}
/**
Returns the current amount of successful withdrawals for this account type
 as an integer
*/
int SavingsAccount::getNrOfWithdrawals() const {
    return withdrawals;
}

/**
 * LONG SAVINGS ACCOUNT
 * **/
/**
The constructor, will construct the savings class with account number
and balance, then construct the long savings account class with the balance and
 accountnumber, as well as interest, will also set the default values such as
 maximum allowed of withdrawals, the standard interest rates, which is
 2% higher than that of the savings account, and make
 sure the current withdrawals for the newly made account is set to 0.
*/
LongSavingsAccount::LongSavingsAccount(std::string aNr, int b) : SavingsAccount(aNr,
                                                                         b) {
    interest = SavingsAccount::getInterest() + .02;
    withdrawals = 0;
    maxWithdrawals = 1;
}

/**
Withdrawal function for the long savings account, will accept integer as input
 and make sure the account have enough funds to support such a withdrawal, it
 will also verify whether the account has reached its maximum allowed
 withdrawals or not. The allowed withdrawal amount is composed of
 the balance multiplied by the interest. Returns true if successful, otherwise
 false, will set the withdrawals to 1 after a successful withdrawal to make sure
 no more withdrawals can be made
*/
bool LongSavingsAccount::withdrawal(int sum) {
    if (withdrawals == 0 && sum < (balance*interest)) {
        balance *= interest;
        balance -= sum;
        withdrawals = 1;
        return true; 
    }
    else
        return false;
}
/**
Returns the name of this account type as a string "Long Savings Account"
*/
std::string LongSavingsAccount::getAccountType() {
    return "Long Savings Account";
}