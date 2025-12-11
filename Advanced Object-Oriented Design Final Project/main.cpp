#include "UserAccount.h"
#include "Manager.h"
#include <fstream>
#include <iostream>
#include <limits>

void bankingPrompt();
void managerConsolePrint();
void managerConsole();
int getInteger(const string& prompt);
double getDouble(const string& prompt);
string getString(const string& prompt);
string getLineString(const string& prompt);
string getAccountType(const string& prompt);

int main() 
{
	int userinput = 0;
	
	while (userinput != 4) 
	{
		bankingPrompt();
		userinput = getInteger("Select an option (1-4): ");
		switch (userinput)
		{
		case 1:
		{
			string username = getString("Username: ");
			string password = getString("Password: ");

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
					bankingOption = getInteger("Select an option (1-6): ");

					switch (bankingOption)
					{
					case 1:
					{
						double amount = getDouble("Enter amount to deposit: ");
						temp.deposit(amount);
						temp.refreshAccountData();
						break;
					}
					case 2:
					{
						double amount = getDouble("Enter amount to withdraw: ");
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
			// Clear input buffer before taking string inputs
			// Need Only for getline which name uses or else it will count \n from userinput after pressing enter
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			// Create a new User object with the provided information
			string name = getLineString("Name: ");

			string username = getString("Username: ");

			string password = getString("Password: ");

			User newUser(name, username, password);

			string accountType = getAccountType("Account Type (Checkings/Savings): ");

			double initialDeposit = getDouble("How much would you like to deposit initially: ");

			UserAccount newAccount(accountType, initialDeposit, newUser);
			newAccount.createAccount();

			break;
		}
		case 3:
		{
			bool managerLogin = false; // to track if manager login is successful


			// Prompt the manager for their login information
			// Read Managers.txt file and verify login information
			string username = getString("Enter Username: ");
			string password = getString("Enter Password: ");
			
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
		managerOption = getInteger("\nSelect an option (1-5): ");
		switch (managerOption) 
		{
		case 1:
			// View all User Information
			customer = getString("Enter Username of Customer: ");
			admin.printUserInfo(customer);

			break;
		case 2:
			// View account name of user
			customer = getString("Enter Username of Customer: ");
			admin.printUserName(customer);
			break;
		case 3:
			// View account type of user
			customer = getString("Enter Username of Customer: ");
			admin.printUserAccountType(customer);
			break;
		case 4:
			// View account balance of user
			customer = getString("Enter Username of Customer: ");
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


int getInteger(const string& prompt)
{
    int value;
    while (true)
    {
        cout << prompt;

		// Input validation
        if (!(cin >> value)) //
        {
            cout << "Invalid input. Enter a number.\n";
            cin.clear(); // resets error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            continue;
        }

        if (value <= 0)
        {
            cout << "Please enter a positive number.\n";
            continue;
        }

        return value;
    }
}

double getDouble(const string& prompt)
{
    double value;
    while (true)
    {
        cout << prompt;
        if (!(cin >> value))
        {
            cout << "Invalid input. Enter a numeric value.\n";
            cin.clear(); // resets error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            continue;
        }

        if (value <= 0.0)
        {
            cout << "Amount must be positive.\n";
            continue;
        }

        return value;
    }
}

string getString(const string& prompt)
{
    string input;
    while (true)
    {
        cout << prompt;
        cin >> input;   // reads a single word safely
		

        if (input.empty())
        {
            cout << "Input cannot be empty. Try again.\n";
            continue;
        }

        return input;
    }
}

// Function to get a full line string input (name with spaces)
string getLineString(const string& prompt)
{
	string input;
	while (true)
	{
		cout << prompt;
		getline(cin, input);   // reads an entire line

		if (input.empty())
		{
			cout << "Input cannot be empty. Try again.\n";
			continue;
		}

		return input;
	}
}

string getAccountType(const string& prompt)
{
	string input;
	while (true)
	{
		cout << prompt;
		cin >> input;

		if (input == "Checkings" || input == "Savings")
		{
			return input;
		}
		else
		{
			cout << "Invalid account type. Please enter 'Checking' or 'Savings'.\n";
			continue;
		}
	}
}