//
// Created by Marcus Roos on 2020-09-24.
// Mittuniversitet
// StudentID: Maro1904
//

#include "BankKund.h"
#include <iostream>
#include <fstream>
#include <utility>
#include <sstream>

BankKund::BankKund()= default;

BankKund::BankKund(std::string tmpNamn, std::string tmpPrsn){
    namn=std::move(tmpNamn);
    personnummer=std::move(tmpPrsn);
}

std::string BankKund::returNamn() {
    return namn;
}

std::string BankKund::returPnummer() {
    return personnummer;
}

int BankKund::returAntalKonton() {
    return testAcc.size(); // NOLINT(cppcoreguidelines-narrowing-conversions)
}

std::string BankKund::returKontoNr(int input) {
    return testAcc[input]->accountInfo();
}

int BankKund::returKontoInfo(const int &index) {
        std::cout << "Account Number: "<<testAcc[index]->accountInfo() << std::endl;
        std::cout << "Credit: " << testAcc[index]->getcurrCredit() << std::endl;
        std::cout << "Saldo: " <<testAcc[index]->getcurrBalance() << std::endl;
        std::cout << "Totalt belopp: " <<testAcc[index]->gettotalBalance() << std::endl;
    return 0;
}

int BankKund::returKundTillgang() {
    int tot=0;
    for (auto & i : testAcc){
        tot += i->gettotalBalance();
    }
    return tot;
}

void BankKund::skapaKonto(const std::string& a, int b, int c) {
    int tmpInt=0;
    personnummer=a;
    std::string tmpAcc;
    tmpInt = testAcc.size();
    std::stringstream ss;
    ss << tmpInt;
    std::string tmpString = ss.str();
    tmpAcc = a + "-" + tmpString;
    testAcc.push_back(std::unique_ptr<Account>(
            new Account(tmpAcc, b, c)));
}

void BankKund::tabortKonto(int accNr) {
    testAcc.erase (testAcc.begin()+accNr);
}

void BankKund::utKonto(int tmpAcc, int input) {
    testAcc[tmpAcc]->deductcurrBalance(input);
}

void BankKund::inKonto(int tmpAcc, int input) {
    testAcc[tmpAcc]->addcurrBalance(input);
}

void BankKund::andraKredit(int tmpAcc, int input) {
    testAcc[tmpAcc]->changeallCredit(input);
}

void BankKund::skrivtillFil() {
    std::ofstream outFile(personnummer + ".knt");

    outFile << namn << std::endl << personnummer << std::endl;
    for (auto &idx : testAcc){
        outFile << idx->accountInfo() << std::endl << idx->getcurrBalance() <<
        std::endl << idx->getcurrCredit() << std::endl;
    }
    outFile.close();
}

void BankKund::lasfranFil() {
    std::string tmpANr;
    int tmpBalance, tmpCredit;

    std::ifstream inFile(personnummer +".knt");
    if (inFile.is_open()){
        getline(inFile, namn);
        getline(inFile, personnummer);
        int i=0;
        while (getline(inFile, tmpANr)){
            inFile >> tmpBalance;
            inFile >> tmpCredit;
            inFile.get();
            testAcc.push_back(std::unique_ptr<Account>(
                    new Account(tmpANr, tmpCredit, tmpBalance)));
            i++;
        }
    }
}
