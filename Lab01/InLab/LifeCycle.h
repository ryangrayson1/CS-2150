/**
 * Ryan Grayson
 * rtg5xkh
 * 02/12/2021
 * LifeCycle.h
 * Lab 1 inLab
 */

#include <iostream>
#include <string>
using namespace std;
#ifndef LIFECYCLE_H
#define LIFECYCLE_H

// Declare the MyObject class
class MyObject {
public:
    static int numObjs;

    MyObject();                    // default constructor
    MyObject(string n);            // constructor with name parameter
    MyObject(const MyObject& rhs); // copy constructor
    ~MyObject();                   // destructor

    string getName() const;
    void setName(const string& newName);

    friend ostream& operator<<(ostream& output, const MyObject& obj);
private:
    string name;
    int id;
};

#endif
