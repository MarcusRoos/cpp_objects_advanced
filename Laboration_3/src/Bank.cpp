//
// Created by Marcus Roos on 2020-09-28.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Bank.h"
#include <utility>

Bank::Bank()= default;

Bank::Bank(std::string tmpNamn, std::string tmpPrsn) {
    std::unique_ptr<BankKund> my_ptr(new BankKund(std::move(tmpNamn),
                                                  std::move(tmpPrsn)));
    bankPtr = std::move(my_ptr);
}

std::string Bank::returNamn() {
    std::string tmpString;
    tmpString = bankPtr->returNamn();
    return tmpString;
}

std::string Bank::returPnummer() {
    std::string tmpString;
    tmpString = bankPtr->returPnummer();
    return tmpString;
}

int Bank::returAntalKonton() {
    int tmpNr;
    tmpNr = bankPtr->returAntalKonton();
    return tmpNr;
}

std::string Bank::returKontoNr(int idx) {
    std::string tmpString;
    tmpString = bankPtr->returKontoNr(idx);
    return tmpString;
}

std::string Bank::returKontoInfo(const int &index) {
    std::string tmpString;
    tmpString = bankPtr->returKontoInfo(index);
    return tmpString;
}

int Bank::returKundTillgang() {
    int tmpNr=0;
    tmpNr = bankPtr->returKundTillgang();
    return tmpNr;
}

bool Bank::skapaKonto(std::string type) {
    if(bankPtr->returAntalKonton()<3) {
        bankPtr->skapaKonto(bankPtr->returNamn(),
                            bankPtr->returPnummer(), type);
        return true;
    }
    else
        return false;
}

bool Bank::tabortKonto(int accNr) {
    if(bankPtr->returAntalKonton()>0) {
        bankPtr->tabortKonto(accNr);
        return true;
    }
    else
        return false;
}

bool Bank::utKonto(int tmpAcc, int input) {
    return bankPtr->utKonto(tmpAcc, input);
}


void Bank::inKonto(int tmpAcc, int input) {
    bankPtr->inKonto(tmpAcc, input);
}

void Bank::andraKredit(int tmpAcc, int input) {
    bankPtr->andraKredit(tmpAcc, input);
}

void Bank::skrivtillFil() {
    bankPtr->skrivtillFil();
}

bool Bank::lasfranFil(const std::string &tmpAcc) {
    std::unique_ptr<BankKund> my_ptr(new BankKund());
    bankPtr.reset();
    if (my_ptr->lasfranFil(tmpAcc)){;
        bankPtr = std::move(my_ptr);
        return true;
    }
    return false;
}
