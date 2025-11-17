#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>

class BankAccount {
    private:
        double balance;
    protected:
        int id;
    public:
        BankAccount();
        void Withdraw();
        void Deposit();
        void print();
};

#endif