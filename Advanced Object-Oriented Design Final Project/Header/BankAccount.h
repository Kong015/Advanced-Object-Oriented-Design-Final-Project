#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>

class BankAccount 
{
private:
    double balance;
protected:
    int id;
public:
    BankAccount();
    BankAccount(double b = 0, int id = 0);
    BankAccount(const BankAccount& other);
    void Withdraw(double v);
    void Deposit(double v);
    void PrintAccountSummary() const;
    double getBalance() const;
    int getID() const;
    void setBalance(double b);
};

#endif
