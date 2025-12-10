#include "Manager.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


Manager::Manager(string name, string userName, string password)
    : Person(name), userName(userName), password(password) {}

string Manager::getUserName() const {
    return userName;
}
string Manager::getPassword() const {
    return password;
}

void Manager::print() const {
    cout << "Manager Name: " << getName() << endl;
    cout << "Username: " << getUserName() << endl;
}
void Manager::printUserInfo(string customer) const {
    cout << "Enter Username of Customer: " << customer << endl;

    string userFileName = customer + ".txt";
    string fullPath = "Users/" + userFileName;
    ifstream inFile(fullPath);

    if (!inFile.is_open()) {
        cerr << "Error opening user file for reading." << endl;
        return;
    }

    string line;
    if (getline(inFile, line)) {

        int commaCount = 0;
        for (char c : line) {
            if (c == ',') commaCount++;
        }
        int fieldCount = commaCount + 1;

        string* fields = new string[fieldCount];

        string field;
        stringstream ss(line);
        int index = 0;

        while (getline(ss, field, ',') && index < fieldCount) {
            fields[index] = field;
            index++;
        }

        for (int i = 0; i < fieldCount; i++) {
            if (i == 2) continue;   // Skip password
            cout << fields[i] << endl;
        }
        delete[] fields;
    }

    inFile.close();
}


void Manager::printUserName(string customer) const {
    string userFileName = customer + ".txt";
    string fullPath = "Users/" + userFileName;
    ifstream inFile(fullPath);

    if (!inFile.is_open()) {
        cerr << "Error opening user file for reading." << endl;
        return;
    }

    string line;
    if (getline(inFile, line)) {

        int commaCount = 0;
        for (char c : line) {
            if (c == ',') commaCount++;
        }
        int fieldCount = commaCount + 1;

        string* fields = new string[fieldCount];


        string field;
        stringstream ss(line);
        int index = 0;

        while (getline(ss, field, ',') && index < fieldCount) {
            fields[index] = field;
            index++;
        }
        if (fieldCount > 3) {
            cout << fields[3] << endl;  // Print the name
        } else {
            cout << "Name not found in file!" << endl;
        }

        delete[] fields;
    }

    inFile.close();
}


void Manager::printUserAccountType(string customer) const {
    string userFileName = customer + ".txt";
    string fullPath = "Users/" + userFileName;
    ifstream inFile(fullPath);

    if (!inFile.is_open()) {
        cerr << "Error opening user file for reading." << endl;
        return;
    }

    string line;
    if (getline(inFile, line)) {

        int commaCount = 0;
        for (char c : line) {
            if (c == ',') commaCount++;
        }
        int fieldCount = commaCount + 1;

        string* fields = new string[fieldCount];


        string field;
        stringstream ss(line);
        int index = 0;

        while (getline(ss, field, ',') && index < fieldCount) {
            fields[index] = field;
            index++;
        }
        if (fieldCount > 4) {
            cout << fields[4] << endl;  // Print the account type
        } else {
            cout << "Account type not found in file!" << endl;
        }

        delete[] fields;
    }

    inFile.close();
}

void Manager::printUserBalance(string customer) const {
    string userFileName = customer + ".txt";
    string fullPath = "Users/" + userFileName;
    ifstream inFile(fullPath);

    if (!inFile.is_open()) {
        cerr << "Error opening user file for reading." << endl;
        return;
    }

    string line;
    if (getline(inFile, line)) {
        int commaCount = 0;
        for (char c : line) {
            if (c == ',') commaCount++;
        }
        int fieldCount = commaCount + 1;

        string* fields = new string[fieldCount];


        string field;
        stringstream ss(line);
        int index = 0;

        while (getline(ss, field, ',') && index < fieldCount) {
            fields[index] = field;
            index++;
        }
        if (fieldCount > 5) {
            cout << fields[5] << endl;  // Print the balance
        } else {
            cout << "Balance not found in file!" << endl;
        }

        delete[] fields;
    }

    inFile.close();
}