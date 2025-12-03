#include "User.h"

// Constructors and Destructors 
User::User() : Person(""), userName(""), password("")
{

}
User::User(string n, string u, string p) : Person(n), userName(u), password(p)
{

}


// Program Functions
void User::print() const
{
	cout << getName() << endl;
}

// Getters and setters
string User::getUserName() const
{
	return userName;
}
string User::getPassword() const
{
	return password;
}
void User::setUserName(string name)
{
	userName = name;
}
void User::setPassword(string pass)
{
	password = pass;
}
