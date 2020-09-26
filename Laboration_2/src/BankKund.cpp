//
// Created by Marcus Roos on 2020-09-24.
// Mittuniversitet
// StudentID: Maro1904
//

#include "BankKund.h"
#include <iostream>
#include <utility>
#include <fstream>

BankKund::BankKund() = default;

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
    return sizeof(testAcc) / sizeof(std::unique_ptr<Account>); // NOLINT(cppcoreguidelines-narrowing-conversions)
}

std::string BankKund::returKontoNr() {
    return testAcc[0]->accountInfo();
}

int BankKund::returKontoInfo(const int &index) {
    if (testAcc[index]) {
        return testAcc[index]->getcurrBalance(), testAcc[index]->getcurrCredit(),
                testAcc[index]->gettotalBalance();
    }
    else
        return 0;
}

int BankKund::returKundTillgang() {
    int tot=0;
    for (auto & i : testAcc){
        std::cout << "Account Number: "<<i->accountInfo() << std::endl;
        std::cout << "Credit: " << i->getcurrCredit() << std::endl;
        std::cout << "Saldo: " <<i->getcurrBalance() << std::endl;
        std::cout << "Totalt belopp: " <<i->gettotalBalance() << std::endl;
        tot += i->gettotalBalance();
    }
    return tot;
}

void BankKund::skapaKonto(const std::string& a, int b, int c) {
    personnummer=a;
    std::string tmpAcc;
    tmpAcc = a + "-1";
    testAcc[0] = std::unique_ptr<Account>(new Account(tmpAcc, b, c));
}

void BankKund::tabortKonto(int accNr) {
    testAcc[accNr].reset();
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
            testAcc[i] = std::unique_ptr<Account>(new Account(tmpANr, tmpCredit, tmpBalance));
            i++;
        }
    }
}
