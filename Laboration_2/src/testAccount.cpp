//
// Created by Marcus Roos on 2020-09-08.
// Mittuniversitet
// StudentID: Maro1904
//

#include "testAccount.h"
#include <iostream>
#include <tuple>
#include <sstream>
#include "Management.h"

/**
The run function, this function will be called in the main program, from here a
 it will enter a switch which will call another function from the menu class.
 Here the user will be able to choose what they would like to do with the
 program, at first only the first "create Queue" option will be a available
 as well as the exit option,
 once a queue has been created the rest of the options will open up.
*/
void testAccount::run() {
    bool again = true;
    do
    {
        menu.printMenuItems();
        switch(menu.menuChoice())
        {
            case 1:
                printName();
                break;
            case 2:
                printPrsnr();
                break;
            case 3:
                printAmountofAccount();
                break;
            case 4:
                printAccountInfo();
                break;
            case 5:
                printBalCredTot();
                break;
            case 6:
                printAllCash();
                break;
            case 7:
                createAccount();
                break;
            case 8:
                deleteAccount();
                break;
            case 9:
                withdrawAccount();
                break;
            case 10:
                depositAccont();
                break;
            case 11:
                changeCredit();
                break;
            case 12:
                writeToFile();
                break;
            case 13:
                readFromFile();
                break;
            case 14:
                writeToFile();
                again=false;
                break;
        }
    }while(again);
}



/**
The testApp constructor, adds menu items to determine which items are enabled
 as well as disabled by default.
*/
testAccount::testAccount() {
    menu.setTitle("**** Pointer menu ****");
    menu.addItem("Fetch customers name", true);
    menu.addItem("Fetch customers social security", true);
    menu.addItem("Fetch amount of customer accounts", true);
    menu.addItem("Fetch customers different account numbers", true);
    menu.addItem("Fetch balance, credit and total from specific account number", true);
    menu.addItem("Fetch customers total money", true);
    menu.addItem("Create new account", true);
    menu.addItem("Delete account", true);
    menu.addItem("Withdraw from account", true);
    menu.addItem("Deposit to account", true);
    menu.addItem("Change credit", true);
    menu.addItem("Write to file", true);
    menu.addItem("Read from file", true);
    menu.addItem("Exit", true);
}

bool testAccount::numberVerify(const std::string &input) {
    return input.find_first_not_of("9876543210") == std::string::npos;
}

void testAccount::printName() {
    std::cout << "NAME: " << bankkund.returNamn() << std::endl;
}

void testAccount::printPrsnr() {
    std::cout << "Person Number: " << bankkund.returPnummer() << std::endl;
}

void testAccount::printAmountofAccount() {
    std::cout << "Amount of accounts: " << bankkund.returAntalKonton() <<
    std::endl;
}

void testAccount::printAccountInfo() {
    for (int i=0; i<bankkund.returAntalKonton(); i++) {
        std::string tmpAcc;
        tmpAcc = bankkund.returKontoNr(i);
        std::cout << "Account number: " << tmpAcc << std::endl;
    }
}

void testAccount::printBalCredTot() {
    std::cout << "Enter 1, 2 or 3. " << std::endl;
    int tmpIdx=0;
    std::cin >> tmpIdx;
    std::string tmpNr;
    tmpNr = bankkund.returKontoInfo(tmpIdx);
    std::cout << tmpNr;
}

void testAccount::printAllCash() {
    int tmpNr=0;
    tmpNr = bankkund.returKundTillgang();
    std::cout << "Total: " << tmpNr << std::endl;
}

bool testAccount::createAccount() {
    if (bankkund.returAntalKonton() <= 2){
    std::string tmpPrsn, tmpNamn;
    int tmpBal=0, tmpCred=0;
    if (bankkund.returAntalKonton() == 0){
        std::cout << "Enter your firstname + last name " << std::endl;
        std::getline(std::cin >> std::ws, tmpNamn);
        std::cout << "Enter your social security number, 10 digits: " << std::endl;
        std::cin >> tmpPrsn;
        bankkund = BankKund(tmpNamn, tmpPrsn);
    }
    tmpPrsn = bankkund.returPnummer();
    bankkund.skapaKonto(tmpPrsn, tmpBal, tmpCred);
    return true;
    }
    else {
        std::cout << "Tmp text, max 3 accounts" << std::endl;
        return false;
    }
}

void testAccount::deleteAccount() {
    std::cout << "Enter 1, 2 or 3. " << std::endl;
    int tmpNr=0;
    std::cin >> tmpNr;
    tmpNr -= -1;
    bankkund.tabortKonto(tmpNr);
}

void testAccount::withdrawAccount() {
    std::cout << "Enter which account to withdraw from: " << std::endl;
    int tmpNr=0, tmpAcc=0;
    std::cin >> tmpAcc;
    std::cout << "Enter amount to withdraw. " << std::endl;
    std::cin >> tmpNr;
    bankkund.utKonto(tmpAcc, tmpNr);
}

void testAccount::depositAccont() {
    std::cout << "Enter which account to deposit to: " << std::endl;
    int tmpNr=0, tmpAcc=0;
    std::cin >> tmpAcc;
    std::cout << "Enter amount to deposit. " << std::endl;
    std::cin >> tmpNr;
    bankkund.inKonto(tmpAcc, tmpNr);
}

void testAccount::changeCredit() {
    std::cout << "Enter which account to credit for: " << std::endl;
    int tmpNr=0, tmpAcc=0;
    std::cin >> tmpAcc;
    std::cout << "Change credit to which amount?. " << std::endl;
    std::cin >> tmpNr;
    bankkund.andraKredit(tmpAcc, tmpNr);
}

void testAccount::writeToFile() {
    bankkund.skrivtillFil();
}

void testAccount::readFromFile() {
    std::cout << "Enter social security number: " << std::endl;
    std::string tmpAcc;
    std::getline(std::cin >> std::ws, tmpAcc);
    bankkund.lasfranFil(tmpAcc);
}
