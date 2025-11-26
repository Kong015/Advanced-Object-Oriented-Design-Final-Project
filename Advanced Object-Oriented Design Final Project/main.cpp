#include "UserAccount.h"
#include <fstream>
#include <iostream>

void bankingPrompt();

int main() {
	int userinput = 0;
	while (userinput != 4) {
		bankingPrompt();
		cin >> userinput;
		switch (userinput) {
			case 1: {
				User u("string", "koing", "voss", "ethan");
				UserAccount a("Checkings", 200.0, u);
				a.print();
				UserAccount b("Checkings", 200.0, u);
				a.print();
				break;
			}
			case 2: {
				// Create a new User object with the provided information
				cout << "Enter User Information to Create Account:" << endl;

				cout << "Name: ";
				string name;
				cin >> name;

				cout << "Address: ";
				string address;
				cin >> address;

				cout << "Email: ";
				string email;
				cin >> email;

				cout << "Phone: ";
				string phone;
				cin >> phone;

				User newUser(name, address, email, phone);

				cout << "Account Type: ";
				string accountType;
				cin >> accountType;
				UserAccount(accountType, 0.0, newUser);

				// Create a new line in the Users.txt file with the user's information
				// Users.txt format: accountID,name,address,email,phone,accountType,balance
				ofstream outFile("Users.txt", ios::app);
				if (outFile.is_open()) {
					outFile << UserAccount::getAccountID() << "," << name << "," << address << "," << email << "," << phone << "," << accountType << ",0.0" << endl;
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
				bool loginSuccess = false;
				ifstream inFile("Managers.txt");
				// Manager.txt file format: username,password
				while (inFile.is_open()) {
					getline(inFile, fileUsername, ',');
					getline(inFile, filePassword);
					if (username == fileUsername && password == filePassword) {
						cout << "Login Successful!" << endl;
						loginSuccess = true;
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
	return 0;
}

void bankingPrompt()
{
	cout << "1. User Login" << endl;
	cout << "2. Create Account" << endl;
	cout << "3. Manager Login" << endl;
	cout << "4. Exit" << endl;
}