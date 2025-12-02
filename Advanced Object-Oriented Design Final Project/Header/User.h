#ifndef USER_H
#define USER_H
#include "Person.h"

class User : public Person
{
	private:
		string name;
		string password;
		string address;
		string email;

	public:
		// Constructors and Destructors 
		User(string name, string password, string address, string email);

		// Program Functions
		void print() const;

		// Getters and setters
		string getAddress() const;
		string getEmail() const;
		void setAddress(string address);
		void setEmail(string phone);
};

#endif