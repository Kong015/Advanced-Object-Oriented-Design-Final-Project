#include "BankAccount.h"
#include <fstream>
#include <iostream>
#include <string>

BankAccount::BankAccount(double b, int id) {
    std::cout << "Constructor" << std::endl;
    balance = b;
    this->id = id;
}

void BankAccount::Withdraw(double v) {
    std::ofstream outFile("user_ " + std::to_string(id) + ".txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << "Withdraw of " << v << " successful!" << std::endl;
        outFile.close();
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
    
}

void BankAccount::Deposit(double v) {
    std::ofstream outFile("user_ " + std::to_string(id) + ".txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << "Deposit of " << v << " successful!" << std::endl;
        balance += v;
        outFile.close();
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

void BankAccount::PrintAccountSummary() {
    std::ifstream inFile("user_ " + std::to_string(id) + ".txt", std::ios::app);
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}