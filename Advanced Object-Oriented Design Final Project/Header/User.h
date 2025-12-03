#ifndef USER_H
#define USER_H
#include "Person.h"

class User : public Person
{
private:
	string userName;
	string password;

public:
	// Constructors and Destructors 
	User();
	User(string name, string username,  string password);

	// Program Functions
	void print() const;
	// Getters and setters
	string getUserName() const;
	string getPassword() const;
	void setUserName(string userName);
	void setPassword(string password);
};

#endif
