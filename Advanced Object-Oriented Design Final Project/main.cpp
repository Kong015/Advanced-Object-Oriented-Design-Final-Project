#include "UserAccount.h"
#include <fstream>
#include <iostream>

void bankingPrompt();

int main() {
	int userinput = 0;
	bool loginSuccess = false;
	bool isManager = false;

	while (userinput != 4 && loginSuccess == false) {
		bankingPrompt();
		cin >> userinput;
		switch (userinput) {
			case 1: {
				cout << "Username: ";
				string username;
				cin >> username;

				cout << "Password: ";
				string password;
				cin >> password;

				std::ifstream inFile("Users.txt");
				if (inFile.is_open()) {
					string line;
					while(std::getline(inFile, line)) {
						size_t pos = line.find(',');
						size_t pos2 = line.find(',', pos + 1);
						size_t pos3 = line.find(',', pos2 + 1);
						string accountID = line.substr(0, pos);
						string fileName = line.substr(pos + 1, pos2 - pos - 1);
						string filePassword = line.substr(pos2 + 1, pos3 - pos2 - 1);
						cout << "Username: " << fileName << ", Password: " << filePassword << endl;

						if (username == fileName && password == filePassword) {
							cout << "Login Successful!" << endl;

							User u(fileName, filePassword);
							UserAccount a("", 0.0, u);
							loginSuccess = true;
							break;
						} else {
							cout << "Login Failed!" << endl;
						}
					}
				}

				// For testing purposes, create a dummy user and account

				//User u("string", "koing", "voss", "ethan");
				//UserAccount a("Checkings", 200.0, u);
				//a.print();
				//UserAccount b("Checkings", 200.0, u);
				//a.print();
				break;
			}
			case 2: {
				// Create a new User object with the provided information
				cout << "Enter User Information to Create Account:" << endl;

				cout << "Name: ";
				string name;
				cin >> name;

				cout << "Password: ";
				string password;
				cin >> password;

				User newUser(name, password);

				cout << "Account Type: ";
				string accountType;
				cin >> accountType;
				UserAccount(accountType, 0.0, newUser);

				// Create a new line in the Users.txt file with the user's information
				// Users.txt format: accountID,name,accountType,balance
				ofstream outFile("Users.txt", ios::app);
				if (outFile.is_open()) {
					outFile << UserAccount::getAccountID() << "," << name << "," << accountType << ",0.0" << endl;
					outFile.close();
					cout << "Account Created Successfully!" << endl;
				} else {
					cerr << "Unable to open file for writing." << endl;
				}

				// Create a new file in the Transactions directory "user_<accountID>.txt"
				ofstream transFile("Transactions/user_" + to_string(UserAccount::getAccountID()) + ".txt");
				if (transFile.is_open()) {
					transFile << "Account Created for " << name << " with Account ID: " << UserAccount::getAccountID() << endl;
				} else {
					cerr << "Unable to create transaction file." << endl;
				}
				transFile.close();

				break;
			}
			case 3: {
				// Prompt the manager for their login information
				// Read Managers.txt file and verify login information
				string username;
				string password;
				cout << "Enter Username: ";
				cin >> username;
				cout << "Enter Password: ";
				cin >> password;
				string fileUsername;
				string filePassword;
				ifstream inFile("Managers.txt");
				// Manager.txt file format: username,password
				while (inFile.is_open()) {
					getline(inFile, fileUsername, ',');
					getline(inFile, filePassword);
					if (username == fileUsername && password == filePassword) {
						cout << "Login Successful!" << endl;
						loginSuccess = true;
						isManager = true;
						break;
					}
				}
				if (!loginSuccess) {
					cout << "Login Failed!" << endl;
				}
				inFile.close();
				break;
			}
			case 4: {
				cout << "Exiting Program..." << endl;
				break;
			}
			default: {
				cout << "ERROR: Input a Number 1-4." << endl;
				break;
			}
		}
	}

	// After user logs in successfully, present them with their banking options
	// Know if user or manager logged in
	if (loginSuccess && isManager) {
		cout << "Welcome to the Banking System!" << endl;
		// Further banking operations would go here
	} else if (loginSuccess) {
		cout << "Welcome to the Banking System!" << endl;

		int bankingOption;
		
		while (bankingOption != 4) {
			cout << "1. Deposit" << endl;
			cout << "2. Withdraw" << endl;
			cout << "3. Print Account Summary" << endl;
			cout << "4. Exit" << endl;
			cin >> bankingOption;
			switch (bankingOption) {
				case 1: {
					cout << "Enter amount to deposit: ";
					double amount;
					cin >> amount;
					break;
				}
				case 2: {
					cout << "Enter amount to withdraw: ";
					double amount;
					cin >> amount;
					break;
				}
				case 3: {
					break;
				}
				default: {
					cout << "ERROR: Input a valid banking option." << endl;
					break;
				}
			}
		}
	}

	return 0;
}

void bankingPrompt()
{
	cout << "1. User Login" << endl;
	cout << "2. Create Account" << endl;
	cout << "3. Manager Login" << endl;
	cout << "4. Exit" << endl;
}