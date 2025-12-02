#include "User.h"

// Constructors and Destructors 
User::User(string m, string p) : Person(m), password(p)
{
	
}


// Program Functions
void User :: print() const
{
	cout << getName() << endl;
} 
