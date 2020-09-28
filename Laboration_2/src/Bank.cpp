//
// Created by Marcus Roos on 2020-09-28.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Bank.h"

Bank::Bank() {

}

std::string Bank::returNamn() {
    return bankPtr->returNamn();
}

std::string Bank::returPnummer() {
    return std::string();
}

int Bank::returAntalKonton() {
    return 0;
}

std::string Bank::returKontoNr(int idx) {
    return std::string();
}

std::string Bank::returKontoInfo(const int &index) {
    return std::string();
}

int Bank::returKundTillgang() {
    return 0;
}

void Bank::skapaKonto(const std::string &a, int b, int c) {
    std::string tmpNamn, tmpPrsn;
    tmpNamn = "TEST";
    tmpPrsn = "TEST2";
    std::unique_ptr<BankKund> my_ptr(new BankKund(tmpNamn, tmpPrsn));

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

}