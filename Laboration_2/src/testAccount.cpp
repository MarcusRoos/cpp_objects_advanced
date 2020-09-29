//
// Created by Marcus Roos on 2020-09-08.
// Mittuniversitet
// StudentID: Maro1904
//

#include "testAccount.h"
#include <iostream>
#include <tuple>
#include <limits>

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
                std::cout << "Change Customer" << std::endl;
                readFromFile();
                break;
            case 13:
                std::cout << "Account Overview" << std::endl;
                accountSummery();
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
    menu.addItem("Change customer", true);
    menu.addItem("Account overview", true);
    menu.addItem("Exit", true);
}

bool testAccount::numberVerify(const std::string &input) {
    return input.find_first_not_of("9876543210") == std::string::npos;
}

void testAccount::printName() {
    std::cout << "NAME: " << bank.returNamn() << std::endl;
}

void testAccount::printPrsnr() {
    std::cout << "Person Number: " << bank.returPnummer() << std::endl;

}

void testAccount::printAmountofAccount() {
    std::cout << "Amount of accounts: " << bank.returAntalKonton() <<
    std::endl;
}

void testAccount::printAccountInfo() {
    for (int i=0; i<bank.returAntalKonton(); i++) {
        std::string tmpAcc;
        tmpAcc = bank.returKontoNr(i);
        std::cout << "Account number: " << tmpAcc << std::endl;
    }
}

void testAccount::printBalCredTot() {
    std::cout << "Enter 1, 2 or 3. " << std::endl;
    int tmpIdx=0;
    std::cin >> tmpIdx;
    std::string tmpNr;
    tmpNr = bank.returKontoInfo(tmpIdx);
    std::cout << tmpNr;
}

void testAccount::printAllCash() {
    int tmpNr=0;
    tmpNr = bank.returKundTillgang();
    std::cout << "Total: " << tmpNr << std::endl;
}

bool testAccount::createAccount() {
    std::string tmpPrsn, tmpNamn;
        std::cout << "Enter your firstname + last name " << std::endl;
        std::getline(std::cin >> std::ws, tmpNamn);
        std::cout << "Enter your social security number, 10 digits: " << std::endl;
        std::cin >> tmpPrsn;
        bank.skapaKonto(tmpNamn, tmpPrsn);
    return true;
}

void testAccount::deleteAccount() {
    std::cout << "Enter 1, 2 or 3. " << std::endl;
    int tmpNr=0;
    std::cin >> tmpNr;
    tmpNr -= -1;
    bank.tabortKonto(tmpNr);
}

void testAccount::withdrawAccount() {
    std::cout << "Enter which account to withdraw from: " << std::endl;
    int tmpNr=0, tmpAcc=0;
    std::cin >> tmpAcc;
    std::cout << "Enter amount to withdraw. " << std::endl;
    std::cin >> tmpNr;
    bank.utKonto(tmpAcc, tmpNr);
}

void testAccount::depositAccont() {
    std::cout << "Enter which account to deposit to: " << std::endl;
    int tmpNr=0, tmpAcc=0;
    std::cin >> tmpAcc;
    std::cout << "Enter amount to deposit. " << std::endl;
    std::cin >> tmpNr;
    bank.inKonto(tmpAcc, tmpNr);
}

void testAccount::changeCredit() {
    std::cout << "Enter which account to credit for: " << std::endl;
    int tmpNr=0, tmpAcc=0;
    std::cin >> tmpAcc;
    std::cout << "Change credit to which amount?. " << std::endl;
    std::cin >> tmpNr;
    bank.andraKredit(tmpAcc, tmpNr);
}

void testAccount::writeToFile() {
    bank.skrivtillFil();
}

void testAccount::readFromFile() {
    std::cout << "Enter social security number: " << std::endl;
    std::string tmpAcc;
    std::cin >> tmpAcc;
    bank.lasfranFil(tmpAcc);
}

void testAccount::runSubMenu() {
    std::cout << "1. Create account" << std::endl;
    std::cout << "2. Read from file" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Enter choice" << std::endl;
    int choice = 0;
    std::cin >> choice;
    while (std::cin.fail() || choice < 1 || choice > 3) {
        std::cout << "Wrong input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> choice;
    }
    switch (choice) {
        case 1:
            createAccount();
            run();
            break;
        case 2:
            readFromFile();
            run();
            break;
        case 3:
        default:
            break;
    }
}

void testAccount::accountSummery() {
    for (int tmpIdx=0; tmpIdx<3; tmpIdx++) {
        std::string tmpNr;
        tmpNr = bank.returKontoInfo(tmpIdx);
        std::cout << tmpNr;
    }
}
