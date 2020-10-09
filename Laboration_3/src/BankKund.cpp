//
// Created by Marcus Roos on 2020-09-24.
// Mittuniversitet
// StudentID: Maro1904
//

#include "BankKund.h"
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
    size_t pos = tmpString.find("-");
    tmpString.erase(0,pos+1);
    std::string tmpCred, tmpBal, tmpTot, Type, tmpInt, withdrawals;
    int tmpWith=0, tmpMaxWith=0, interest=0;
    double tmpInterest;
    Type = testAcc[index]->getAccountType();
    tmpBal = std::to_string(testAcc[index]->getBalance());
    tmpTot = std::to_string(testAcc[index]->getDisposable());
    if (Type == "Transaction Account"){
        tmpCred = std::to_string(testAcc[index]->getCredit());
        std::string s1{Type + " nr  " + tmpString + "\n" + "Balance: " + tmpBal
                       + "kr\n" + "Credit: " + tmpCred + "kr\n" + "Available: " + tmpTot + "kr\n" + "Remaining withdrawals: Unlimited\n\n"};
        return s1;
    }
    else {
        tmpInterest = testAcc[index]->getInterest();
        interest = ((tmpInterest * 100)-100);
        tmpInt = std::to_string(interest);
        tmpMaxWith = testAcc[index]->getMaxWithdrawals();
        tmpWith = testAcc[index]->getNrOfWithdrawals();
        tmpWith = tmpMaxWith - tmpWith;
        withdrawals = std::to_string(tmpWith);
        std::string s1{Type + " nr " + tmpString + "\n" + "Balance: " + tmpBal
                       + "kr\n" + "Interest: " + tmpInt + "%\n" + "Available: " + tmpTot + "kr\n" + "Remaining withdrawals: " + withdrawals + "\n\n"};
        return s1;
    }
}

int BankKund::returKundTillgang() {
    int tot=0;
    for (auto & i : testAcc){
        tot += i->getDisposable();
    }
    return tot;
}

void BankKund::skapaKonto(std::string tmpNamn, const std::string& tmpPrsn, int type) {
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
           if (type == 1){
               testAcc.push_back(std::unique_ptr<Account>(
                       new TransactionAccount(std::string(), 0, tmpString, 0, 0)));
               break;
           }
           if (type == 2){testAcc.push_back(std::unique_ptr<Account>(
                   new SavingsAccount(tmpString, 0)));

           break;
           }
           if (type == 3){testAcc.push_back(std::unique_ptr<Account>(
                   new LongSavingsAccount(tmpString, 0)));
           break;
           }

        }
    }
}

bool BankKund::lasfranFil(const std::string& tmpAcc) {
    std::string tmpANr, tmpType;
    int tmpBalance, tmpCredit;
    double tmpInterest;
    std::ifstream inFile(tmpAcc +".knt");
    std::ifstream exFile(tmpAcc +".knt");
    if (inFile.is_open()){
        getline(inFile, namn);
        getline(inFile, personnummer);
        int i=0;
        while (getline(inFile, tmpANr)){
            getline(inFile, tmpType);
            if (tmpType == "Transaction Account") {
                inFile >> tmpBalance;
                inFile >> tmpCredit;
                inFile.get();
                testAcc.push_back(std::unique_ptr<Account>(
                        new TransactionAccount(std::string(), 0, tmpANr,
                                               tmpBalance, tmpCredit)));
            }
            if (tmpType == "Savings Account") {
                inFile >> tmpBalance;
                inFile >> tmpInterest;
                inFile.get();
                testAcc.push_back(std::unique_ptr<Account>(
                        new SavingsAccount(std::string(), 0, tmpANr,
                                               tmpBalance, tmpInterest)));
            }
            if (tmpType == "Long Savings Account") {
                inFile >> tmpBalance;
                inFile >> tmpInterest;
                inFile.get();
                testAcc.push_back(std::unique_ptr<Account>(
                        new LongSavingsAccount(std::string(), 0, tmpANr,
                                               tmpBalance, tmpInterest)));
            }
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
    return testAcc[tmpAcc]->withdrawal(input);
}

void BankKund::inKonto(int tmpAcc, int input) {
        testAcc[tmpAcc]->deposit(input);
}

bool BankKund::andraKredit(int tmpAcc, int input) {
    if (testAcc[tmpAcc]->getAccountType() == "Transaction Account") {
        testAcc[tmpAcc]->setCredit(input);
        return true;
    }
    else
        return false;
}

void BankKund::skrivtillFil() {
    std::ofstream outFile(personnummer + ".knt");
    outFile << namn << std::endl << personnummer << std::endl;
    for (auto &idx : testAcc){
        if (idx->getAccountType() == "Transaction Account") {
            outFile << idx->accountInfo() << std::endl << idx->getAccountType() << std::endl
                    << idx->getBalance() <<
                    std::endl << idx->getCredit() << std::endl;
        }
        else{
            outFile << idx->accountInfo() << std::endl << idx->getAccountType() << std::endl
                    << idx->getBalance() <<
                    std::endl << idx->getInterest() << std::endl;
        }
    }
    outFile.close();
}

std::string BankKund::getAccountType(int idx) {
    return testAcc[idx]->getAccountType();
}
