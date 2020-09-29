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

std::string BankKund::returKontoNr(int idx) {
    std::string tmpStr;
    tmpStr = testAcc[idx]->accountInfo();
    return tmpStr;
}

std::string BankKund::returKontoInfo(const int &index) {
    std::string tmpString = testAcc[index]->accountInfo();
    std::string tmpCred, tmpBal, tmpTot;
    tmpCred = std::to_string(testAcc[index]->getcurrCredit());
    tmpBal = std::to_string(testAcc[index]->getcurrBalance());
    tmpTot = std::to_string(testAcc[index]->gettotalBalance());
    std::string s1{"Account Number: " + tmpString + "\n" + "Credit: " + tmpCred
    + "\n" + "Balance: " + tmpBal + "\n" + "Total: " + tmpTot + "\n"};
    return s1;
}

int BankKund::returKundTillgang() {
    int tot=0;
    for (auto & i : testAcc){
        tot += i->gettotalBalance();
    }
    return tot;
}

void BankKund::skapaKonto(std::string tmpNamn, std::string tmpPrsn) {
    int tmpInt=0;
    std::string tmpAcc;
    tmpInt = testAcc.size();
    std::stringstream ss;
    ss << tmpInt;
    std::string tmpString = ss.str();
    tmpAcc = tmpPrsn + "-" + tmpString;
    testAcc.emplace_back(new Account( tmpAcc, tmpInt, tmpInt ));
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

void BankKund::lasfranFil(const std::string& tmpAcc) {
    std::string tmpANr;
    int tmpBalance, tmpCredit;

    std::ifstream inFile(tmpAcc +".knt");
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
