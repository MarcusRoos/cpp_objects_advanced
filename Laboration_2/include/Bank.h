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
    BankKund testBankKund;
public:
    Bank();
    std::string returNamn();
    std::string returPnummer();
    int returAntalKonton();
    std::string returKontoNr(int idx);
    std::string returKontoInfo(const int &index);
    int returKundTillgang();
    void skapaKonto(const std::string& a, int b, int c);
    void tabortKonto(int accNr);
    void utKonto(int tmpAcc, int input);
    void inKonto(int tmpAcc, int input);
    void andraKredit(int tmpAcc, int input);
    void skrivtillFil();
    void lasfranFil(const std::string& tmpAcc);
};
#endif //DT060G_BANK_H
