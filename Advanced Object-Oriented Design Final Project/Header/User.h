#ifndef USER_H
#define USER_H
#include "Person.h"

class User : public Person
{
	private:
		string name;
		string password;

	public:
		// Constructors and Destructors 
		User(string name, string password);

		// Program Functions
		void print() const;
};

#endif