#include "BankAccount.h"

BankAccount::BankAccount(double b, int id) 
{
    std::cout << "Constructor" << std::endl;
}

void BankAccount::Withdraw(double v) 
{
    std::cout << "Old balance: " << balance << std::endl;
    balance -= v;
    std::cout << "New balance: " << balance << std::endl;
    std::cout << "Withdraw of " << v << "successful!" << std::endl;
}

void BankAccount::Deposit(double v) 
{
    std::cout << "Old balance: " << balance << std::endl;
    balance += v;
    std::cout << "New balance: " << balance << std::endl;
    std::cout << "Deposit of " << v << "successful!" << std::endl;
}

void BankAccount::PrintAccountSummary() 
{
    std::cout << "Balance: " << balance << std::endl;
}
