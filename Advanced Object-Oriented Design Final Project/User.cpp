#include "User.h"

// Constructors and Destructors 
User::User() : Person(""), userName(""), password("")
{

}

User::User(string n, string u, string p) : Person(n), userName(u), password(p)
{

}

User::User(const User& other) : Person(other.getName()), userName(other.userName), password(other.password)
{

}

// Program Functions
void User::print() const
{
	cout << "Username: " << userName << endl;
	cout << "Name: " << getName() << endl;
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
