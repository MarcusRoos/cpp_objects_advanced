//
// Created by Marcus Roos on 2020-09-24.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_BANKKUND_H
#define DT060G_BANKKUND_H

#include <string>
#include <memory>
#include "Account.h"

class BankKund {
private:
    std::string namn;
    std::string personnummer;
    std::unique_ptr<Account> testAcc[3];
public:
    BankKund();
    BankKund(std::string tmpNamn, std::string tmpPrsn);
    std::string returNamn();
    std::string returPnummer();
    int returAntalKonton();
    std::string returKontoNr();
    int returKontoInfo(const int &index);
    int returKundTillgang();
    void skapaKonto(const std::string& a, int b, int c);
    void tabortKonto(int accNr);
    void utKonto(int tmpAcc, int input);
    void inKonto(int tmpAcc, int input);
    void andraKredit(int tmpAcc, int input);
    void skrivtillFil();
    void lasfranFil();
};

#endif //DT060G_BANKKUND_H
