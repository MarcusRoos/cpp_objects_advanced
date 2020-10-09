//
// Created by Marcus Roos on 2020-09-24.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_BANKKUND_H
#define DT060G_BANKKUND_H

#include <string>
#include <memory>
#include "Account.h"
#include <vector>
#include <algorithm>
//------------------------------------------------------------------------------
// Class definition
//------------------------------------------------------------------------------
/**
 Class BankKund

Handles the customers within the bank, will use another class "Account"
 where it will store the information regarding the actual account, while
 this customer class will instead handle the information regarding
 the customer and not the actual accounts. This is a silent class.
 */
class BankKund {
private:
    std::string namn;
    std::string personnummer;
    // Declares a pointer object to the account class, stores it in a vector
    std::vector<std::unique_ptr<Account>> testAcc;
public:
    /**
* Default constructor of class BankKund
*
* @param None.
* @return None.
*/
    BankKund();
    /**
* Initializing constructor of class BankKund
*
* @param String, String.
* @return None.
*/
    BankKund(std::string tmpNamn, std::string tmpPrsn);
    /**
* Returns namn
*
* @param None.
* @return string namn.
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
* @param string tmpNamn, string tmpPrsn, int type.
* @return None.
*/
    void skapaKonto(std::string tmpNamn, const std::string& tmpPrsn, int type);
    /**
* Removes specified account for the current user
*
* @param int accNr
* @return None.
*/
    void tabortKonto(int accNr);
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

#endif //const DT060G_BANK&KUND_H
