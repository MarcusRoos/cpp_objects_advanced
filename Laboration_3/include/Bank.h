//
// Created by Marcus Roos on 2020-09-28.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_BANK_H
#define DT060G_BANK_H
#include <string>
#include "BankKund.h"

class Bank {
private:
    std::unique_ptr<BankKund>bankPtr;
public:
    Bank();
    Bank(std::string tmpNamn, std::string tmpPrsn);
    std::string returNamn();
    std::string returPnummer();
    int returAntalKonton();
    std::string returKontoNr(int idx);
    std::string returKontoInfo(const int &index);
    int returKundTillgang();
    bool skapaKonto(int type);
    bool tabortKonto(int accNr);
    bool utKonto(int tmpAcc, int input);
    void inKonto(int tmpAcc, int input);
    bool andraKredit(int tmpAcc, int input);
    void skrivtillFil();
    bool lasfranFil(const std::string& tmpAcc);
    std::string getAccountType(int idx);
};
#endif //DT060G_BANK_H
