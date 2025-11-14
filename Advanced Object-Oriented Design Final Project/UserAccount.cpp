#include "UserAccount.h"

// Static member functions/variables
unsigned int UserAccount::numOfAccounts = 0;
unsigned int UserAccount::accountID = 0;


UserAccount::UserAccount(string accType, double bal, User u) :
	accountType(accType), balance(bal), user(u)
{
	numOfAccounts++;
	accountID++;
	accountNumber = accountID;
}

// Decrease the total amount of account by 1;
UserAccount::~UserAccount()
{
	numOfAccounts--;
}

// Program Functions
void UserAccount::print() const
{
	cout << accountNumber << endl;
	cout << accountType << endl;
	cout << balance << endl;
	user.print();
}

// Getters and setters
unsigned int UserAccount::getNumofAccounts()
{
	return numOfAccounts;
}

unsigned int UserAccount::getAccountNumber() const
{
	return accountNumber;
}


string UserAccount :: getAccountType() const
{
	return accountType;
}

void UserAccount::setAccountType(string accType)
{
	accountType = accType;
}

double UserAccount::getBalance() const
{
	return balance;
}

void UserAccount::setBalance(double bal)
{
	balance = bal;
}