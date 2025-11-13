#include <iostream>
using namespace std;

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