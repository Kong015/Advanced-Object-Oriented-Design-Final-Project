#include "UserAccount.h"
#include "Manager.h"
#include <fstream>
#include <iostream>

void bankingPrompt();
void managerConsolePrint();
void managerConsole();

int main() 
{
	int userinput = 0;
	bool managerLogin = false; // to track if manager login is successful
	
	while (userinput != 4) 
	{
		bankingPrompt();
		cin >> userinput;
		switch (userinput)
		{
		case 1:
		{
			cout << "Username: ";
			string username;
			cin >> username;

			cout << "Password: ";
			string password;
			cin >> password;

			UserAccount temp;  // empty object used a UserAccount that holds the value of the txt file if login is successful
			if (temp.login(username, password))
			{

				// After user logs in successfully, present them with their banking options
				int bankingOption = 0;

				while (bankingOption != 6)
				{

					cout << "\n---- Banking Menu ----" << endl;
					cout << "1. Deposit" << endl;
					cout << "2. Withdraw" << endl;
					cout << "3. Delete Account" << endl;
					cout << "4. Print Account Information" << endl;
					cout << "5. Print Account Summary" << endl;
					cout << "6. Logout\n" << endl;
					cin >> bankingOption;

					switch (bankingOption)
					{
					case 1:
					{
						cout << "Enter amount to deposit: ";
						double amount;
						cin >> amount;
						temp.deposit(amount);
						temp.refreshAccountData();
						break;
					}
					case 2:
					{
						cout << "Enter amount to withdraw: ";
						double amount;
						cin >> amount;
						temp.withdraw(amount);
						temp.refreshAccountData();
						break;
					}
					case 3:
					{
						temp.deleteAccount();
						bankingOption = 6; // logout after deleting account
						break;
					}
					case 4:
					{
						temp.print();
						break;
					}
					case 5:
					{
						temp.printAccountSummary();
						break;
					}
					case 6:
					{
						cout << "Logging out\n";
						break;
					}
					default:
						cout << "Invalid option\n";
						break;
					}
				}
			}
			break;
		}
		case 2:
		{
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

			cout << "Account Type (Checking/Savings): ";
			string accountType;
			cin >> accountType;

			cout << "How much would you like to deposit initially? ";
			double initialDeposit;
			cin >> initialDeposit;

			UserAccount newAccount(accountType, initialDeposit, newUser);
			newAccount.createAccount();

			break;
		}
		case 3:
		{
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

			while (inFile.is_open()) 
			{
				getline(inFile, fileUsername, ',');
				getline(inFile, filePassword);
				if (username == fileUsername && password == filePassword) 
				{
					cout << "Login Successful!" << endl;
					managerConsole();
					managerLogin = true;
					break;
				}
				else
				{
					managerLogin = false;
					break;
				}
				
			}
			if (!managerLogin) 
			{
				cout << "Login Failed!" << endl;
			}
			inFile.close();
			break;
		}
		case 4:
		{
			cout << "Exiting Program..." << endl;
			break;
		}
		default:
		{
			cout << "ERROR: Input a Number 1-4." << endl;
			break;
		}
		}
	}
}

void bankingPrompt()
{
	cout << "\n---- Login Menu ----" << endl;
	cout << "1. User Login" << endl;
	cout << "2. Create Account" << endl;
	cout << "3. Manager Login" << endl;
	cout << "4. Exit\n" << endl;
}

void managerConsolePrint() 
{
	cout << "---- Manager Console ----" << endl;
	cout << "1. View all User Information" << endl;
	cout << "2. View account name of user" << endl;
	cout << "3. View account type of user" << endl;
	cout << "4. View account balance of user" << endl;
	cout << "5. Logout" << endl;
}

void managerConsole() 
{
	int managerOption = 0;
	string customer;
	Manager admin("Admin", "Manager", "Password123"); // Basic Manager Object to call functions
	while (managerOption != 5) 
	{
		managerConsolePrint();
		cin >> managerOption;
		switch (managerOption) 
		{
		case 1:
			// View all User Information
			cout << "Enter Username of Customer: ";
			cin >> customer;
			admin.printUserInfo(customer);

			break;
		case 2:
			// View account name of user
			cout << "Enter Username of Customer: ";
			cin >> customer;
			admin.printUserName(customer);
			break;
		case 3:
			// View account type of user
			cout << "Enter Username of Customer: ";
			cin >> customer;
			admin.printUserAccountType(customer);
			break;
		case 4:
			// View account balance of user
			cout << "Enter Username of Customer: ";
			cin >> customer;
			admin.printUserBalance(customer);
			break;
		case 5:
			cout << "Logging out of Manager Console" << endl;
			break;
		default:
			cout << "Invalid option" << endl;
			break;
		}
	}
}