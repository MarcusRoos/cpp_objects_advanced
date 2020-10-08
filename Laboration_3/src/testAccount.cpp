//
// Created by Marcus Roos on 2020-09-08.
// Mittuniversitet
// StudentID: Maro1904
//

#include "testAccount.h"
#include <iostream>
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
                readFromFile();
                break;
            case 13:
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
        std::string tmpAcc, test;
        tmpAcc = bank.returKontoNr(i);
        std::cout << "Account number: " << tmpAcc << std::endl;
    }
}

void testAccount::printBalCredTot() {
    for (int i=0; i<bank.returAntalKonton(); i++) {
        std::string tmpAcc;
        tmpAcc = bank.returKontoNr(i);
        std::cout << "Account number: " << tmpAcc << std::endl;
    }
    std::cout << "Deposit to which account? " << std::endl;
    std::string tmpString;
    std::cin >> tmpString;
    int tmpAccnr=0;
    for (int i=0; i<bank.returAntalKonton(); i++) {
        std::string tmpAcc;
        tmpAcc = bank.returKontoNr(i);
        if (tmpAcc == tmpString){
            tmpAccnr = i;
        }
    }
    std::cout << bank.returKontoInfo(tmpAccnr);
}

void testAccount::printAllCash() {
    int tmpNr=0;
    tmpNr = bank.returKundTillgang();
    std::cout << "Total: " << tmpNr << std::endl;
}

void testAccount::createAccount() {
    if(bank.returAntalKonton() < 3) {
    std::string type;
    std::cout << "Open which type of account?" << std::endl;
    std::cout << "1. Transaction Account" << std::endl;
    std::cout << "2. Savings Account" << std::endl;
    std::cout << "3. Long Savings Account" << std::endl;
    int input=0;
    std::cin >> input;
        while (input < 1 || input > 3 || std::cin.fail()) {
            std::cin >> input;
            std::cout << "Invalid input, enter 1, 2 or 3." << std::endl;
        }
        bank.skapaKonto(input);
    }
    else
        std::cout << "Maximum accounts reached! " << std::endl;
}

void testAccount::deleteAccount() {
    if (bank.returAntalKonton() > 0) {
        for (int i = 0; i < bank.returAntalKonton(); i++) {
            std::string tmpAcc;
            tmpAcc = bank.returKontoNr(i);
            std::cout << "Account number: " << tmpAcc << std::endl;
        }
        std::cout << "Delete which account? " << std::endl;
        std::string tmpString, accNr;
        std::cin >> tmpString;
        int tmpAccnr = 0;
        std::string tmpAcc;
        for (int i = 0; i < bank.returAntalKonton(); i++) {
            tmpAcc = bank.returKontoNr(i);
            if (tmpAcc == tmpString) {
                accNr = tmpAcc;
                tmpAccnr = i;
                break;
            }
        }
        if (accNr == tmpString) {
            if (bank.tabortKonto(tmpAccnr)) {
                std::cout << "Deleted" << std::endl;
            } else
                std::cout << "Not deleted" << std::endl;
        } else
            std::cout << "No such account " << std::endl;
    }
}


void testAccount::withdrawAccount() {
    for (int i=0; i<bank.returAntalKonton(); i++) {
        std::string tmpAcc;
        tmpAcc = bank.returKontoNr(i);
        std::cout << "Account number: " << tmpAcc << std::endl;
    }
    std::cout << "Withdraw from which account? " << std::endl;
    std::string tmpString, accNr;
    std::cin >> tmpString;
    int tmpAccnr = 0;
    std::string tmpAcc;
    for (int i=0; i<bank.returAntalKonton(); i++) {
        tmpAcc = bank.returKontoNr(i);
        if (tmpAcc == tmpString){
            accNr = tmpAcc;
            tmpAccnr = i;
            break;
        }
    }
    int tmpNr=0;
    if (accNr == tmpString) {
        std::cout << "Enter amount to withdraw. " << std::endl;
        std::cin >> tmpNr;
        if (bank.utKonto(tmpAccnr, tmpNr)) {
            std::cout << "Withdrew " << tmpNr << " from account " << accNr <<
                      " successfully! " << std::endl;
        } else
            std::cout << "Withdrawal unsuccessful! Either insufficient balance "
                         "or maximum withdrawals has been reached, please check "
                         "your account summery."
                      << std::endl;
    }
    else
        std::cout << "No such account " << std::endl;

}

void testAccount::depositAccont() {
    for (int i=0; i<bank.returAntalKonton(); i++) {
        std::string tmpAcc;
        tmpAcc = bank.returKontoNr(i);
        std::cout << "Account number: " << tmpAcc << std::endl;
    }
    std::cout << "Deposit to which account? " << std::endl;
    std::string tmpString, accNr;
    std::cin >> tmpString;
    int tmpAccnr=0;
    std::string tmpAcc;
    for (int i=0; i<bank.returAntalKonton(); i++) {
        tmpAcc = bank.returKontoNr(i);
            if (tmpAcc == tmpString){
                accNr = tmpAcc;
                tmpAccnr = i;
                break;
            }
    }
    if (accNr == tmpString){
        int tmpNr=0;
        std::cout << "Enter amount to deposit. " << std::endl;
        std::cin >> tmpNr;
        bank.inKonto(tmpAccnr, tmpNr);
        std::cout << "Successfully deposited " << tmpNr << " into account " <<
        accNr << "!"<<std::endl;
    }
    else
        std::cout << "No such account. " << std::endl;

}

void testAccount::changeCredit() {
    for (int i=0; i<bank.returAntalKonton(); i++) {
        std::string tmpAcc, type;
        tmpAcc = bank.returKontoNr(i);
        std::cout << "Account number: " << tmpAcc << std::endl;
    }
    std::cout << "Change credit of which account? " << std::endl;
    std::string tmpString, accNr;
    std::cin >> tmpString;
    std::string tmpAcc;
    int tmpAccnr=0;
    for (int i=0; i<bank.returAntalKonton(); i++) {
        tmpAcc = bank.returKontoNr(i);
        if (tmpAcc == tmpString){
            accNr = tmpAcc;
            tmpAccnr = i;
            break;
        }
    }
    if (accNr == tmpString && bank.getAccountType(tmpAccnr) == "Transaction Account"){
        int tmpNr=0;
        std::cout << "Enter amount to change credit to" << std::endl;
        std::cin >> tmpNr;
        if (bank.andraKredit(tmpAccnr, tmpNr)) {
            std::cout << "Successfully changed credit of account " << accNr <<
                      " to " << tmpNr << "!" << std::endl;
        }
        else
            std::cout << "Failed to change credit. " << std::endl;
    }
    if (accNr == tmpString && bank.getAccountType(tmpAccnr) != "Transaction Account"){
        std::cout << "Saving accounts are ineligible for credit! " << std::endl;
    }
    else if (accNr != tmpString)
        std::cout << "No such account. " << std::endl;
}

void testAccount::writeToFile() {
    bank.skrivtillFil();
}

void testAccount::readFromFile() {
    std::cout << "Enter your social security number (10 digits):" << std::endl;
    std::string tmpPrsn;
    std::cin >> tmpPrsn;
    while (!numberVerify(tmpPrsn) || tmpPrsn.length() != 10 || !bank.lasfranFil(tmpPrsn)){
        std::cout << "Wrong input or could not find file, please retry.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> tmpPrsn;
        if (bank.lasfranFil(tmpPrsn)){
            std::cout << "File read successfully! " << std::endl;
            break;
        }
    }
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
            startAccount();
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
    for (int tmpIdx=0; tmpIdx<bank.returAntalKonton(); tmpIdx++) {
        std::string tmpNr;
        tmpNr = bank.returKontoInfo(tmpIdx);
        std::cout << tmpNr;
    }
    std::cout << "Withdrawals resets annually!" << std::endl;
}

void testAccount::startAccount() {
    std::cout << "Enter your firstname and lastname: " << std::endl;
    std::string tmpNamn;
    std::getline(std::cin >> std::ws, tmpNamn);
    std::cout << "Enter your social security number (10 digits):" << std::endl;
    std::string tmpPrsn;
    std::cin >> tmpPrsn;
    while (!numberVerify(tmpPrsn) || tmpPrsn.length() != 10){
        std::cout << "Wrong input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> tmpPrsn;
    }
    bank = Bank(tmpNamn, tmpPrsn);
}

