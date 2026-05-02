#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Person {
protected:
    char name[50];
    int age;

public:
    // Constructor
    Person() {
        age = 0;
        strcpy(name, "");
    }

    // Pure virtual function — har derived class mein display() hogi
    virtual void display() = 0;

    // Getters
    char* getName() { return name; }
    int getAge() { return age; }
};