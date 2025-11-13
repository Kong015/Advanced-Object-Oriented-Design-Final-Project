#ifndef Person_h
#define Person_h

#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;

public:
    virtual void print() const = 0;
};

#endif // PERSON_H

