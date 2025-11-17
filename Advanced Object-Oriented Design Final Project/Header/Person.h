#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

using namespace std;

class Person
{
    private:
        string name;

    public:
        // Constructors and Destructors 
        Person(string name);

        // Getters and setters
        string getName() const;
        void setName(string name);

        // Abstract function
        virtual void print() const = 0;
};

#endif
