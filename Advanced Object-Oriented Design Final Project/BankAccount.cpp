#include "BankAccount.h"

BankAccount::BankAccount() {
    std::cout << "Constructor" << std::endl;
}

void BankAccount::Withdraw() {
    std::cout << "Withdraw" << std::endl;
}

void BankAccount::Deposit() {
    std::cout << "Deposit" << std::endl;
}

void BankAccount::print() {
    std::cout << "Balance: " << balance << std::endl;
}