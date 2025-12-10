#include "UserAccount.h"

// Static member functions/variables
unsigned int UserAccount::numOfAccounts = 0;
unsigned int UserAccount::accountNumber = 0;


// Constructors and Destructors
UserAccount::UserAccount() : 
	accountID(0), accountType(""), user(), account(0.0, 0)
{
	
}

UserAccount::UserAccount(string accType, double bal, User u) :
	accountType(accType), user(u)
{
	numOfAccounts++;
	accountNumber++;
	accountID = accountNumber;
	account = BankAccount(bal, accountID);
}

// Decrease the total amount of account by 1;
UserAccount::~UserAccount()
{

}

// Program Functions


//Creating a Account 
// Users.txt format: accountID,name,accountType,balance
void UserAccount::createAccount()
{
	string name = user.getName();
	string username = user.getUserName();
	string password = user.getPassword();


	string userFileName = username + ".txt"; //name to txt file for UserAccount


	//check if username already exists
	ifstream checkFile("Users/" + userFileName);
	if (checkFile.is_open()) 
	{
		cout << "ERROR: Username already exists. Choose a different name.\n";
		checkFile.close();
		UserAccount::accountNumber--; //decrement account number since account creation failed
		UserAccount::numOfAccounts--; //decrement number of accounts since account creation failed
		return;
	}

	//create user file	
	ofstream outFile("Users/" + userFileName, ios::app);
	if (outFile.is_open()) 
	{
		outFile << accountID << "," 
			<< username << "," 
			<< password << ","
			<< name << ","
			<< accountType << "," 
			<< account.getBalance() << endl;

		outFile.close();

		numOfAccounts++;  // Increment number of accounts
		cout << "Account Created Successfully!" << endl;
	}
	else 
	{
		cerr << "Unable to open file for writing." << endl;
	}

	// Create a new file in the Transactions directory "user_<accountID>.txt"
	ofstream transFile("Transactions/user_" + to_string(accountID) + ".txt");
	if (transFile.is_open()) 
	{
		transFile << "Account Created for " << name << " with Account ID: " << accountID << endl;
	}
	else 
	{
		cerr << "Unable to create transaction file." << endl;
	}
	transFile.close();
}

bool UserAccount::login(const string& username, const string& password)
{
	string userFileName = username + ".txt";

	// Check if the file exists
	ifstream inFile("Users/" + userFileName);
	if (!inFile.is_open()) 
	{
		cout << "Login Failed! Username not found" << endl;
		return false; // File doesn't exist
	}

	string line;
	getline(inFile, line);

	// Find positions of commas
	size_t pos = line.find(',');
	size_t pos2 = line.find(',', pos + 1);
	size_t pos3 = line.find(',', pos2 + 1);
	size_t pos4 = line.find(',', pos3 + 1);
	size_t pos5 = line.find(',', pos4 + 1);

	//string of the values from the file
	string idStr    = line.substr(0, pos);
	string fileUser = line.substr(pos + 1, pos2 - pos - 1);
	string filePass = line.substr(pos2 + 1, pos3 - pos2 - 1);
	string fileName = line.substr(pos3 + 1, pos4 - pos3 - 1);
	string acctType = line.substr(pos4 + 1, pos5 - pos4 - 1);
	string balStr   = line.substr(pos5 + 1);

	if (password != filePass) {
		cout << "Login Failed! Incorrect password" << endl;
		return false;
	}

	unsigned int id = static_cast<unsigned int>(stoi(idStr)); // Convert string to int to unsigned int
	double bal = stod(balStr); // Convert string to double

	// Fill this temp object with real values from file so that it can be used after login
	user = User(fileName, fileUser, filePass);
	accountID = id;
	accountType = acctType;
	account = BankAccount(bal, id);
	inFile.close();

	cout << "Login Successful!\n";
	return true;
}

void UserAccount::deleteAccount() const
{
	string userFileName = "Users/" + user.getUserName() + ".txt";

	// Delete the user file
	if (remove(userFileName.c_str()) != 0) 
	{
		cerr << "Error deleting user file." << endl;
	}


	// Delete the transaction file
	string transFileName = "Transactions/user_" + to_string(accountID) + ".txt";
	if (remove(transFileName.c_str()) != 0) 
	{
		cerr << "Error deleting transaction file." << endl;
	}

	numOfAccounts--; // Decrement number of accounts
	cout << "Account deleted successfully." << endl;
}

// Update the account data in the user file after a transaction
void UserAccount::refreshAccountData()
{
	string userFileName = user.getUserName() + ".txt";
	string fullPath = "Users/" + userFileName;
	ifstream inFile(fullPath, std::ios::in);
	if (!inFile.is_open()) 
	{
		cerr << "Error opening user file for reading." << endl;
		return;
	}
	string line;
	getline(inFile, line);
	// Find positions of commas
	size_t pos = line.find(',');
	size_t pos2 = line.find(',', pos + 1);
	size_t pos3 = line.find(',', pos2 + 1);
	size_t pos4 = line.find(',', pos3 + 1);
	size_t pos5 = line.find(',', pos4 + 1);

    // Replace balance with current account balance
	string idStr = line.substr(0, pos);
	string userStr = line.substr(pos + 1, pos2 - pos - 1);
	string passStr = line.substr(pos2 + 1, pos3 - pos2 - 1);
	string nameStr = line.substr(pos3 + 1, pos4 - pos3 - 1);
	string typeStr = line.substr(pos4 + 1, pos5 - pos4 - 1);
	string balStr = line.substr(pos5 + 1);
    double newBal = account.getBalance();

	inFile.close();

    // Rewrite the line with updated balance
    ofstream outFile(fullPath, ios::out | ios::trunc);
    if (!outFile.is_open()) {
        cerr << "Error opening user file for writing." << endl;
        return;
    }

    outFile << idStr << ","
            << userStr << ","
            << passStr << ","
            << nameStr << ","
            << typeStr << ","
            << newBal << endl;

    outFile.close();

    cout << "Total balance: " << newBal << endl;
}

void UserAccount::print() const
{
	cout << "---- User Account Information ----" << endl;
	cout << "Account ID: " << accountID << endl;
	cout << "Account Type: " << accountType << endl;
	
	// Polymorphism demonstration
	Person *p;
	p = new User(user);
	p->print();
	delete p;
	cout << "Account Balance: " << account.getBalance() << endl;
}

// Getters and setters
unsigned int UserAccount::getNumofAccounts()
{
	return numOfAccounts;
}

unsigned int UserAccount::getAccountNumber()
{
	return accountNumber;
}

unsigned int UserAccount::getAccountID() const
{
	return accountID;
}


string UserAccount::getAccountType() const
{
	return accountType;
}

void UserAccount::setAccountType(string accType)
{
	accountType = accType;
}

double UserAccount::getBalance() const
{
	return account.getBalance();
}

void UserAccount::setBalance(double bal)
{
	account.setBalance(bal);
}

void UserAccount::deposit(double amount)
{
	account.Deposit(amount);
}
void UserAccount::withdraw(double amount)
{
	account.Withdraw(amount);
}
void UserAccount::printAccountSummary() const
{
	account.PrintAccountSummary();
}
