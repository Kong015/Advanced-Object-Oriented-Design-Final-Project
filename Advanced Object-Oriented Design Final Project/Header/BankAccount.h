#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>

class BankAccount {
    private:
        double balance;
    protected:
        int id;
    public:
        BankAccount(double b = 0, int id);
        void Withdraw(double v);
        void Deposit(double v);
        void PrintAccountSummary();
};

#endif