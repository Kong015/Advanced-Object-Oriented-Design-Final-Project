#ifndef USERACCOUNT_H
#define USERACCOUNT_H
#include "User.h"
#include "BankAccount.h"
#include <fstream>
#include <string>
#include <iostream>

class UserAccount
{
private:
	static unsigned int numOfAccounts; // keeps track of the amount of accounts created
	static unsigned int accountID; // keeps track of the account id (increase by 1 each account created)
	unsigned int accountNumber;
	string accountType;
	BankAccount account;
	User user;

public:
	// Constructors and Destructors 
	UserAccount();
	UserAccount(string accountType, double balance, User user);
	~UserAccount();

	// Program Functions
	void createAccount();
	void deleteAccount() const; 
	void loadAccount() const;
	bool login(const string& username, const string& password);
	void print() const;

	// Getters and setters
	static unsigned int getNumofAccounts();
	static int getAccountID();
	unsigned int getAccountNumber() const;
	string getAccountType() const;
	double getBalance() const;
	void setAccountType(string accountType);
	void setBalance(double balance);
};

#endif 

