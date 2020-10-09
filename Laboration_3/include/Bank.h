//
// Created by Marcus Roos on 2020-09-28.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_BANK_H
#define DT060G_BANK_H
#include <string>
#include "BankKund.h"
//------------------------------------------------------------------------------
// Class definition
//------------------------------------------------------------------------------
/**
 Class Bank

Works as an intermediate between the input/output class testAccount, and the
 silent classes, more specifically the BankKund class. Will contain a unique
 pointer to the BankKund class to be able to talk to the
 class and call the relevant functions.
 */
class Bank {
private:
    // Unique ptr to the BankKund class
    std::unique_ptr<BankKund>bankPtr;
public:
    /**
* Default constructor of class Bank
*
* @param None.
* @return None.
*/
    Bank();
    /**
* Initializing constructor of class Bank
*
* @param string tmpNamn, string tmpPrsn.
* @return None.
*/
    Bank(std::string tmpNamn, std::string tmpPrsn);
    /**
* Returns namn
*
* @param None
* @return string Namn.
*/
    std::string returNamn();
    /**
* Returns personnummer
*
* @param None.
* @return string personnummer.
*/
    std::string returPnummer();
    /**
* Returns amount of accounts, defined by the size of the vector
*
* @param None.
* @return integer.
*/
    int returAntalKonton();
    /**
* Returns account number at index position in vector
*
* @param integer idx.
* @return String accountnumber.
*/
    std::string returKontoNr(int idx);
    /**
* Returns account information at index position in vector
*
* @param integer idx.
* @return String account information.
*/
    std::string returKontoInfo(const int &index);
    /**
* Returns the current customers total available money
*
* @param None.
* @return Integer total money.
*/
    int returKundTillgang();
    /**
* Creates a new account for the current customer
*
* @param int type
* @return True/False.
*/
    bool skapaKonto(int type);
    /**
* Removes specified account for the current user
*
* @param int accNr
* @return True/False.
*/
    bool tabortKonto(int accNr);
    /**
* Withdraws money from the specified account for the current user
*
* @param int accNr, int input
* @return True/False.
*/
    bool utKonto(int tmpAcc, int input);
    /**
* Deposits money to the specified account for the current user
*
* @param int accNr, int input
* @return None.
*/
    void inKonto(int tmpAcc, int input);
    /**
* Changes credit for the specified account for the current user
*
* @param int accNr, int input
* @return True/False.
*/
    bool andraKredit(int tmpAcc, int input);
    /**
* Saves current relevant information to a file, file name is determined by
 * the customers personnummer.
*
* @param None.
* @return None.
*/
    void skrivtillFil();
    /**
* Loads a file into the program, will take a personnummer as input to find the
 * correct file, then load the contents into the aforementioned vector
*
* @param String tmpAcc.
* @return True/False.
*/
    bool lasfranFil(const std::string& tmpAcc);
    /**
* Fetches account type for the account at the specified index in the vector
*
* @param int idx.
* @return String type.
*/
    std::string getAccountType(int idx);
};
#endif //DT060G_BANK_H
