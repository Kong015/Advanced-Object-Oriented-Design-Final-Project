#include "BankAccount.h"
#include <fstream>
#include <iostream>
#include <string>

BankAccount::BankAccount(double b, int id) 
{    
    balance = b;
    this->id = id;
}

BankAccount::BankAccount() 
{    
    balance = 0.0;
    id = 0;
}

BankAccount::BankAccount(const BankAccount& other) 
{
    balance = other.balance;
    id = other.id;
}

void BankAccount::Withdraw(double v) 
{
     if (v <= 0) 
     {
        std::cerr << "Withdrawal amount must be positive." << std::endl;
        return;
    }

    if (v > balance) 
    {
        std::cerr << "Insufficient funds for withdrawal." << std::endl;
        return;
    }

    std::ofstream outFile("Transactions/user_" + std::to_string(id) + ".txt", std::ios::app);
    if (outFile.is_open()) {
        balance -= v;
        outFile << "Withdraw of " << v << " successful! New balance: " << balance << std::endl;
        outFile.close();
    }
    else 
    {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

void BankAccount::Deposit(double v) 
{
    // Validate deposit amount
    if (v <= 0) 
    {
        std::cerr << "Enter Valid Positive Amount" << std::endl;
        return;
    }


    std::ofstream outFile("Transactions/user_" + std::to_string(id) + ".txt", std::ios::app);
    if (outFile.is_open()) {
        balance += v;
        outFile << "Deposit of " << v << " successful! New balance: " << balance << std::endl;
        outFile.close();
    }
    else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

void BankAccount::PrintAccountSummary() const 
{
    std::ifstream inFile("Transactions/user_" + std::to_string(id) + ".txt", std::ios::in);
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

void BankAccount::setID(int newID)
{
    id = newID;
}