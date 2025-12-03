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
		case 1: 
		{
			cout << "Username: ";
			string username;
			cin >> username;

			cout << "Password: ";
			string password;
			cin >> password;

			UserAccount temp;  // empty object used a UserAccount that hold the value of the txt file if login is successful
			if (temp.login(username, password)) 
			{
				//localAccount = temp; // you can now use localAccount for further operations  
				//hasLocalAccount = true; // indicate that you have created a local account
				loginSuccess = true;
			}
			break;
		}
		case 2: {
			// Create a new User object with the provided information
			cout << "Name: ";
			string name;
			cin >> name;

			cout << "Username: ";
			string username;
			cin >> username;

			cout << "Password: ";
			string password;
			cin >> password;

			User newUser(name, username, password);

			cout << "Account Type: ";
			string accountType;
			cin >> accountType;

			UserAccount newAccount(accountType, 0.0, newUser);
			newAccount.createAccount();

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
	}
	else if (loginSuccess) {
		cout << "Welcome to the Banking System!" << endl;

		int bankingOption = 0;

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
