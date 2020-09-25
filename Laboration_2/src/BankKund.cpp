//
// Created by Marcus Roos on 2020-09-24.
// Mittuniversitet
// StudentID: Maro1904
//

#include "BankKund.h"
#include <iostream>

BankKund::BankKund() = default;

std::string BankKund::returNamn() {
    return fornamn + " " + efternamn;
}

std::string BankKund::returPnummer() {
    return personnummer;
}

int BankKund::returAntalKonton() {
    return sizeof(testAcc) / sizeof(std::unique_ptr<Account>);
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

void BankKund::skapaKonto(const std::string& a, const std::string& b, const std::string& c) {
    fornamn=a;
    efternamn=b;
    personnummer=c;
}

void BankKund::tabortKonto() {

}

void BankKund::utKonto(int input) {

}

void BankKund::inKonto(int input) {

}

void BankKund::andraKredit(int input) {

}

void BankKund::skrivtillFil() {

}

void BankKund::lasfranFil() {

}
