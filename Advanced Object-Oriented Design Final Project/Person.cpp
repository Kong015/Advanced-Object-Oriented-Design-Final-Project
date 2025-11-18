#include "Person.h"

// Constructors and Destructors 
Person::Person(string n) : name(n)
{

}


// Getters and Setters
string Person::getName() const
{
	return name;
}

void Person::setName(string n)
{
	name = n;
}