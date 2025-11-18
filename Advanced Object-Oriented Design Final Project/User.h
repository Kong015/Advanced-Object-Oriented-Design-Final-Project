#ifndef USER_H
#define USER_H
#include "Person.h"

class User : public Person
{
private:
	string address;
	string email;
	string phone;

public:
	// Constructors and Destructors 
	User(string name, string address, string email, string phone);

	// Program Functions
	void print() const;

	// Getters and setters
	string getAddress() const;
	string getEmail() const;
	string getPhone() const;
	void setAddress(string address);
	void setEmail(string phone);
	void setPhone(string email);
};

#endif