#include "User.h"

// Constructors and Destructors 
User::User(string m, string p, string a, string e) : Person(m), password(p), address(a), email(e)
{
	
}


// Program Functions
void User :: print() const
{
	cout << getName() << endl;
	cout << address << endl;
	cout << email << endl;
} 


// Getters and Setters
string User::getAddress() const
{
	return address;
}

void User::setAddress(string a)
{
	address = a;
}

string User::getEmail() const
{
	return email;
}

void User::setEmail(string e)
{
	email = e;
}
