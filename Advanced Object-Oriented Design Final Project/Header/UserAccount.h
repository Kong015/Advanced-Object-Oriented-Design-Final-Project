#ifndef USERACCOUNT_H
#define USERACCOUNT_H
#include "User.h"
#include "BankAccount.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdio>

class UserAccount
{
private:
	static unsigned int numOfAccounts; // keeps track of the amount of accounts created
	static unsigned int accountNumber; // keeps track of the account id (increase by 1 each account created)
	unsigned int accountID;
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
	void refreshAccountData(); // update user file after transaction
	void deleteAccount(); 
	void deposit(double amount);
	void withdraw(double amount);
	void printAccountSummary() const;
	bool login(const string& username, const string& password);
	void print() const;
	static void saveCounters(); // save static counters to file
	static void loadCounters(); // load static counters from file

	// Getters and setters
	static unsigned int getNumofAccounts();
	static unsigned int getAccountNumber();
	unsigned int getAccountID() const;
	string getAccountType() const;
	double getBalance() const;
	void setAccountType(string accountType);
	void setBalance(double balance);
};

#endif 