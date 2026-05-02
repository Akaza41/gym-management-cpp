#pragma once
#include <iostream>
#include <cstring>
#include "payment.h"
#include "person.h"
using namespace std;

class Customer : public Person {
private:
    int id;
    Payment payment;

    // Static member — track total customers
    static int totalCustomers;

public:
    Customer() {
        id = 0;
    }

    void setData(int _id, const char* _name, int _age, float fee) {
        id = _id;
        strcpy(name, _name);
        age = _age;
        payment.setFee(fee);
        totalCustomers++;
    }

    void payFee(float amount) {
        payment.pay(amount);
    }

    // Operator overloading — compare two customers by ID
    bool operator==(Customer& other) {
        return id == other.id;
    }

    bool operator>(Customer& other) {
        return id > other.id;
    }

    // Getters
    int getId() { return id; }
    char* getName() { return name; }
    int getAge() { return age; }
    float getTotal() { return payment.getTotal(); }
    float getRemaining() { return payment.getRemaining(); }
    char* getStatus() { return payment.getStatus(); }

    // Virtual function implementation
    void display() {
        cout << "| " << id
             << " | " << name
             << " | " << age
             << " | " << payment.getTotal()
             << " | " << payment.getRemaining()
             << " | " << payment.getStatus()
             << " |\n";
    }

    // Static function
    static int getTotalCustomers() {
        return totalCustomers;
    }

    static void showStats() {
        cout << "Total Customers Registered: " << totalCustomers << endl;
    }
};

// Static member initialize
int Customer::totalCustomers = 0;