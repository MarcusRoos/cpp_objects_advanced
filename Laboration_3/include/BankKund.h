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
#include <vector>
#include <algorithm>

class BankKund {
private:
    std::string namn;
    std::string personnummer;
    std::vector<std::unique_ptr<Account>> testAcc;
public:
    BankKund();
    BankKund(std::string tmpNamn, std::string tmpPrsn);
    std::string returNamn();
    std::string returPnummer();
    int returAntalKonton();
    std::string returKontoNr(int idx);
    std::string returKontoInfo(const int &index);
    int returKundTillgang();
    void skapaKonto(std::string tmpNamn, const std::string& tmpPrsn);
    void tabortKonto(int accNr);
    bool utKonto(int tmpAcc, int input);
    void inKonto(int tmpAcc, int input);
    void andraKredit(int tmpAcc, int input);
    void skrivtillFil();
    bool lasfranFil(const std::string& tmpAcc);
};

#endif //const DT060G_BANK&KUND_H
