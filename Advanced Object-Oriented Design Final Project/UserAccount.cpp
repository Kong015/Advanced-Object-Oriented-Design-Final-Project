#include "UserAccount.h"

// Static member functions/variables
unsigned int UserAccount::numOfAccounts = 0;
unsigned int UserAccount::accountID = 0;


// Constructors and Destructors
UserAccount::UserAccount() : 
	accountNumber(0), accountType(""), user(), account(0.0, 0)
{
	
}

UserAccount::UserAccount(string accType, double bal, User u) :
	accountType(accType), user(u), account(bal, ++accountID)
{
	numOfAccounts++;
	accountNumber = accountID;
}

// Decrease the total amount of account by 1;
UserAccount::~UserAccount()
{
	numOfAccounts--;
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
	ifstream checkFile(userFileName);
	if (checkFile.is_open()) 
	{
		cout << "ERROR: Username already exists. Choose a different name.\n";
		checkFile.close();
		return;
	}

	//create user file
	ofstream outFile(userFileName, ios::app);
	if (outFile.is_open()) 
	{
		outFile << UserAccount::getAccountID() << "," 
			<< username << "," 
			<< password << ","
			<< name << ","
			<< accountType << "," 
			<< account.getBalance() << endl;

		outFile.close();
		cout << "Account Created Successfully!" << endl;
	}
	else 
	{
		cerr << "Unable to open file for writing." << endl;
	}

	// Create a new file in the Transactions directory "user_<accountID>.txt"
	ofstream transFile("Transactions/" + username + "_" + to_string(UserAccount::getAccountID()) + ".txt");
	if (transFile.is_open()) 
	{
		transFile << "Account Created for " << name << " with Account ID: " << UserAccount::getAccountID() << endl;
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
	ifstream inFile(userFileName);
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
	string idStr = line.substr(0, pos);
	string fileUser = line.substr(pos2 + 1, pos2 - pos - 1);
	string filePass = line.substr(pos2 + 1, pos3 - pos2 - 1);
	string fileName = line.substr(pos3 + 1, pos4 - pos3 - 1);
	string acctType = line.substr(pos4 + 1, pos5 - pos4 - 1);
	string balStr = line.substr(pos5 + 1);

	if (password != filePass) {
		cout << "Login Failed! Incorrect password" << endl;
		return false;
	}

	unsigned int id = static_cast<unsigned int>(stoi(idStr)); // Convert string to int to unsigned int
	double bal = stod(balStr); // Convert string to double

	// Fill this temp object with real values from file so that it can be used after login
	user = User(fileName, fileUser, filePass);
	accountType = acctType;
	accountNumber = id;
	account = BankAccount(bal, id);
	inFile.close();

	cout << "Login Successful!\n";
	return true;
}


void UserAccount::print() const
{
	cout << accountNumber << endl;
	cout << accountType << endl;
	cout << account.getBalance() << endl;
	user.print();
}

// Getters and setters
unsigned int UserAccount::getNumofAccounts()
{
	return numOfAccounts;
}

int UserAccount::getAccountID()
{
	return accountID;
}

unsigned int UserAccount::getAccountNumber() const
{
	return accountNumber;
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
