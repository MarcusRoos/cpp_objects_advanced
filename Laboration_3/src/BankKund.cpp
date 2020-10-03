//
// Created by Marcus Roos on 2020-09-24.
// Mittuniversitet
// StudentID: Maro1904
//

#include "BankKund.h"
#include <iostream>
#include <fstream>
#include <utility>

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
    std::string s1{"====== " + tmpString + " ========\n\n" + "Balance: " + tmpBal
    + "\n" + "Credit: " + tmpCred + "\n" + "Disposable: " + tmpTot + "\n\n"};
    return s1;
}

int BankKund::returKundTillgang() {
    int tot=0;
    for (auto & i : testAcc){
        tot += i->gettotalBalance();
    }
    return tot;
}

void BankKund::skapaKonto(std::string tmpNamn, const std::string& tmpPrsn) {
        namn = std::move(tmpNamn);
        personnummer = tmpPrsn;
        std::string tmpString, intString, tmpPush;
        std::vector<std::string>tmpVec;
        for (auto & p : testAcc){
            tmpVec.push_back(p->accountInfo());
        }
    for (int i=0; i<=2; i++){
        intString = std::to_string(i);
        tmpString = personnummer + "-" + intString;
       if (std::find(tmpVec.begin(), tmpVec.end(), tmpString) == tmpVec.end())
        {
            testAcc.push_back(std::unique_ptr<Account>(
                    new Account(tmpString, 0, 0)));
            break;
        }
    }
}

bool BankKund::lasfranFil(const std::string& tmpAcc) {
    std::string tmpANr;
    int tmpBalance=0, tmpCredit=0;

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
        return true;
    }
    else
        return false;
}

void BankKund::tabortKonto(int accNr) {
    testAcc.erase (testAcc.begin()+accNr);
}

bool BankKund::utKonto(int tmpAcc, int input) {
    if (testAcc[tmpAcc]->gettotalBalance() >= input) {
        testAcc[tmpAcc]->deductcurrBalance(input);
        return true;
    }
    else
        return false;
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


