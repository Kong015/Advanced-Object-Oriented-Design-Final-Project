#include "BankAccount.h"
#include <fstream>
#include <iostream>
#include <string>

BankAccount::BankAccount(double b, int id) {
    std::cout << "Constructor" << std::endl;
    balance = b;
    this->id = id;
}

BankAccount::BankAccount() {
    std::cout << "Default Constructor" << std::endl;
    balance = 0.0;
}

BankAccount::BankAccount(const BankAccount& other) {
    std::cout << "Copy Constructor" << std::endl;
    balance = other.balance;
    id = other.id;
}

void BankAccount::Withdraw(double v) {
    if (v > balance) 
    {
        std::cerr << "Insufficient funds for withdrawal." << std::endl;
        return;
    }
	balance -= v;
    

    std::ofstream outFile("user_" + std::to_string(id) + ".txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << "Withdraw of " << v << " successful!" << std::endl;
        balance -= v;
        outFile.close();
    }
    else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }

}

void BankAccount::Deposit(double v) 
{
	balance += v;
    std::ofstream outFile("user_" + std::to_string(id) + ".txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << "Deposit of " << v << " successful!" << std::endl;
        balance += v;
        outFile.close();
    }
    else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

void BankAccount::PrintAccountSummary() const 
{
    std::ifstream inFile("user_" + std::to_string(id) + ".txt", std::ios::in);
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
    }
    else {
        std::cerr << "Unable to open file for reading." << std::endl;
    }
}

double BankAccount::getBalance() const
{
    return balance;
}

int BankAccount::getID() const
{
    return id;
}

void BankAccount::setBalance(double b) 
{
    balance = b;
}
