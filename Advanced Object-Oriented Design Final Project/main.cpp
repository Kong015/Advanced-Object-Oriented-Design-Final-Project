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
				// Create a new file in the Transactions directory "user_<accountID>.txt"
				// Prompt the user for their information (name, address, email, phone)
				// Create a new line in the Users.txt file with the user's information
				// Create a new User object with the provided information
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