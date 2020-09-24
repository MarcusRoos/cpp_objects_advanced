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
    std::string fornamn;
    std::string efternamn;
    std::string personnummer;
    std::unique_ptr<Account[3]>bankArray;
public:
    BankKund();
    std::string returNamn();
    std::string returPnummer();
    int returAntalKonton();
    int returKontoNr();
    int returKontoInfo();
    int returKundTillgang();
    void skapaKonto();
    void tabortKonto();
    void utKonto(int input);
    void inKonto(int input);
    void andraKredit(int input);
    void skrivtillFil();
    void lasfranFil();
};

#endif //DT060G_BANKKUND_H
