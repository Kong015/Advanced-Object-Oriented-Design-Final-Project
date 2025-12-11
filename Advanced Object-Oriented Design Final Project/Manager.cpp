#include "Manager.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

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

void Manager::readAccountsFromFile() {
    string folderPath = "Users";  // your folder name

    // Loop through all items in the folder
    for (const auto& entry : fs::directory_iterator(folderPath)) {

        // Skip directories, only process files
        if (entry.is_regular_file()) {

            ifstream file(entry.path());
            if (!file) {
                cout << "Could not open file.\n";
                continue;
            }

            // Read the contents of the file
            string fileName = entry.path().stem().string();
            cout << "Account Username: " << fileName << endl;

            file.close();
        }
    }

}

string Manager::printCustomerPassword(string customer) const {
    string fileName = customer + ".txt";   // automatically add .txt
    string fullPath = "Users/" + fileName;
    ifstream inFile(fullPath);
    if (!inFile.is_open()) {
        cerr << "Error: could not open file " << fileName << endl;
        return "";
    }

    string line;
    getline(inFile, line);   // read the entire line

    stringstream ss(line);
    string item;

    // 1st entry 
    getline(ss, item, ',');

    // 2nd entry
    getline(ss, item, ',');

    // 3rd entry → return this
    getline(ss, item, ',');

    return item;
}
