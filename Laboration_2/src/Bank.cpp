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
    return std::string();
}

int Bank::returKundTillgang() {
    int tmpNr=0;
    tmpNr= bankPtr->returKundTillgang();
    return tmpNr;
}

void Bank::skapaKonto(std::string tmpNamn, std::string tmpPrsn) {
    std::unique_ptr<BankKund> my_ptr(new BankKund(std::move(tmpNamn),
            std::move(tmpPrsn)));
}

void Bank::tabortKonto(int accNr) {

}

void Bank::utKonto(int tmpAcc, int input) {

}

void Bank::inKonto(int tmpAcc, int input) {

}

void Bank::andraKredit(int tmpAcc, int input) {

}

void Bank::skrivtillFil() {

}

void Bank::lasfranFil(const std::string &tmpAcc) {
    std::unique_ptr<BankKund> my_ptr(new BankKund());
    my_ptr->lasfranFil(tmpAcc);
    bankPtr = std::move(my_ptr);
}