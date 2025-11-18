#include "UserAccount.h"

void bankingPrompt();

int main()
{
	int userinput = 0;
	while (userinput != 4)
	{
		bankingPrompt();
		cin >> userinput;
		if (userinput == 1)
		{
			User u("string", "koing", "voss", "ethan");
			UserAccount a("Checkings", 200.0, u);
			a.print();
			UserAccount b("Checkings", 200.0, u);
			a.print();
		}
		else if (userinput == 2)
		{

		}
		else if (userinput == 3)
		{

		}
		else if (userinput == 4)
		{

		}
		else
		{
			cout << "ERROR: Input a Number 1-4." << endl;
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