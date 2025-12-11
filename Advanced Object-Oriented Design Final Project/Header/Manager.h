#ifndef MANAGER_H
#define MANAGER_H
#include "Person.h"

class Manager : public Person {
    private:
        string userName;
        string password;

    public:
        Manager(string name, string userName, string password);
        string getUserName() const;
        string getPassword() const;
        void print() const override;
        void readAccountsFromFile();
        void printUserInfo(string customer) const;
        void printUserName(string customer) const;
        void printUserAccountType(string customer) const;
        void printUserBalance(string customer) const;
        string printCustomerPassword(string customer) const;
        

};
#endif