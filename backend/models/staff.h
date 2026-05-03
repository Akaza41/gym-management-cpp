#pragma once
#include <iostream>
#include <cstring>
#include "payment.h"
#include "person.h"
using namespace std;

class Staff : public Person {
private:
    int id;
    char role[30];
    Payment salary;

    // Static member — track total staff
    static int totalStaff;

public:
    Staff() {
        id = 0;
        strcpy(role, "");
    }

    void setData(int _id, const char* _name, int _age, const char* _role, float sal) {
        id = _id;
        strcpy(name, _name);
        age = _age;
        strcpy(role, _role);
        salary.setFee(sal);
        totalStaff++;
    }

    void loadData(int _id, const char* _name, int _age, const char* _role, float sal, float rem) {
        id = _id;
        strcpy(name, _name);
        age = _age;
        strcpy(role, _role);
        salary.loadPayment(sal, rem);
        totalStaff++;
    }

    void paySalary(float amount) {
        salary.pay(amount);
    }

    // Operator overloading — compare two staff by ID
    bool operator==(Staff& other) {
        return id == other.id;
    }

    bool operator>(Staff& other) {
        return id > other.id;
    }

    // Getters
    int getId() { return id; }
    char* getName() { return name; }
    int getAge() { return age; }
    char* getRole() { return role; }
    float getTotal() { return salary.getTotal(); }
    float getRemaining() { return salary.getRemaining(); }
    char* getStatus() { return salary.getStatus(); }

    // Virtual function implementation
    void display() {
        cout << "| " << id
             << " | " << name
             << " | " << age
             << " | " << role
             << " | " << salary.getTotal()
             << " | " << salary.getRemaining()
             << " | " << salary.getStatus()
             << " |\n";
    }

    // Static function
    static int getTotalStaff() {
        return totalStaff;
    }

    static void showStats() {
        cout << "Total Staff Registered: " << totalStaff << endl;
    }
};

// Static member initialize
int Staff::totalStaff = 0;