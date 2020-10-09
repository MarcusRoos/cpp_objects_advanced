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
 program.
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
The testAccount constructor, adds menu items to determine which items are enabled
 as well as disabled by default, in this case all the options are available from
 the get go as a submenu is handling this part in this case.
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

/**
Tests whether the string parameter only contains integers or not, if
 only integers are found it will return true, otherwise false
*/
bool testAccount::numberVerify(const std::string &input) {
    return input.find_first_not_of("9876543210") == std::string::npos;
}

/**
Prints name of the current customer
*/
void testAccount::printName() {
    std::cout << "NAME: " << bank.returNamn() << std::endl;
}

/**
Prints personnummer of the current customer
*/
void testAccount::printPrsnr() {
    std::cout << "Person Number: " << bank.returPnummer() << std::endl;

}

/**
Print the total amount of accounts the customer currently possess
*/
void testAccount::printAmountofAccount() {
    std::cout << "Amount of accounts: " << bank.returAntalKonton() <<
    std::endl;
}

/**
Prints the different account numbers for all the current accounts the customer
 has
*/
void testAccount::printAccountInfo() {
    for (int i=0; i<bank.returAntalKonton(); i++) {
        std::string tmpAcc, test;
        tmpAcc = bank.returKontoNr(i);
        std::cout << "Account number: " << tmpAcc << std::endl;
    }
}

/**
Prints the information about one specific account, specified by user account
 number input
*/
void testAccount::printBalCredTot() {
    for (int i=0; i<bank.returAntalKonton(); i++) {
        std::string tmpAcc;
        tmpAcc = bank.returKontoNr(i);
        std::cout << "Account number: " << tmpAcc << std::endl;
    }
    std::cout << "Print information for which account? " << std::endl;
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

/**
Prints the total amount of funds the customer have across all accounts
*/
void testAccount::printAllCash() {
    int tmpNr=0;
    tmpNr = bank.returKundTillgang();
    std::cout << "Total: " << tmpNr << std::endl;
}

/**
Creates an account, allows the user to specify whether its a transaction, savings
  or long savings account. Customer is free to choose freely between the three
  types as they wish. An account creation is only allowed if the size of the
  vector is less than 3, meaning 3 or less accounts exist. The newly created
  account will be void of any funds and use the default interest rates.
*/
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

/**
Deletes an account specified by the user, user will enter the
 account number they wish to delete and it will be removed.
  Will inform the user whether the operation was successful or not.
*/
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

/**
Withdraws funds from the specified account, the user will specify which account
 they wish to withdraw from, and the amount they wish to withdraw.
 Will inform the user whether the operation was successful or not.
*/
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

/**
Deposts funds to the specified account, the user will specify which account
 they wish to deposit to, and the amount they wish to deposit.
 Will inform the user whether the operation was successful or not.
*/
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

/**
Changes the credit on the specified account, the user will specify which account
 they wish to change credits for, and the amount they wish to change it to.
 Will inform the user whether the operation was successful or not.
*/
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

/**
Saves the customer to a file specified by their personnummer
*/
void testAccount::writeToFile() {
    bank.skrivtillFil();
}

/**
Loads in an already existing customer to the program, the user will be prompted
 to enter their personnummer, the function will loop until a valid personnummer
 has been entered or until the user return to the submenu by entering "0".
*/
void testAccount::readFromFile() {
    std::cout << "Enter your social security number (10 digits):" << std::endl;
    std::string tmpPrsn;
    std::cin >> tmpPrsn;
    while (!numberVerify(tmpPrsn) || tmpPrsn.length() != 10 || !bank.lasfranFil(tmpPrsn)){
        if (tmpPrsn == "0"){
            runSubMenu();
        }
        std::cout << "Wrong input or could not find file, please retry. Enter 0 "
                     "to return to the sub menu.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> tmpPrsn;
        if (bank.lasfranFil(tmpPrsn)){
            std::cout << "File read successfully! " << std::endl;
            break;
        }
    }
}

/**
Runs the submenu which will be called whenever the program has started, allows
 the user to either create a new account, load in an already existing customer
 by entering their personnummer, or exiting entirely.
*/
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

/**
Prints an account summery of the current customers accounts
*/
void testAccount::accountSummery() {
    for (int tmpIdx=0; tmpIdx<bank.returAntalKonton(); tmpIdx++) {
        std::string tmpNr;
        tmpNr = bank.returKontoInfo(tmpIdx);
        std::cout << tmpNr;
    }
    std::cout << "Withdrawals resets annually!" << std::endl;
}

/**
Will be called through the submenu when no customer has been made yet, will
 initialize the name and personnummer of the new customer.
*/
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

