#include "User.h"

// Constructors and Destructors 
User::User(string m, string a, string e, string p) : Person(m), address(a), email(e), phone(p)
{
	
}


// Program Functions
void User :: print() const
{
	cout << getName() << endl;
	cout << address << endl;
	cout << email << endl;
	cout << phone << endl;
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

string User::getPhone() const
{
	return phone;
}

void User::setPhone(string p)
{
	phone = p;
}
