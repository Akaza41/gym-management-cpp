#pragma once
#include <iostream>
#include <cstring>
#include "payment.h"
#include "person.h"
using namespace std;

class Trainer : public Person {
private:
    int id;
    char specialty[30];
    Payment salary;

    // Static member — track total trainers
    static int totalTrainers;

public:
    Trainer() {
        id = 0;
        strcpy(specialty, "");
    }

    void setData(int _id, const char* _name, int _age, const char* _spec, float sal) {
        id = _id;
        strcpy(name, _name);
        age = _age;
        strcpy(specialty, _spec);
        salary.setFee(sal);
        totalTrainers++;
    }

    void loadData(int _id, const char* _name, int _age, const char* _spec, float sal, float rem) {
        id = _id;
        strcpy(name, _name);
        age = _age;
        strcpy(specialty, _spec);
        salary.loadPayment(sal, rem);
        totalTrainers++;
    }

    void paySalary(float amount) {
        salary.pay(amount);
    }

    // Operator overloading — compare two trainers by ID
    bool operator==(Trainer& other) {
        return id == other.id;
    }

    bool operator>(Trainer& other) {
        return id > other.id;
    }

    // Getters
    int getId() { return id; }
    char* getName() { return name; }
    int getAge() { return age; }
    char* getSpecialty() { return specialty; }
    float getTotal() { return salary.getTotal(); }
    float getRemaining() { return salary.getRemaining(); }
    char* getStatus() { return salary.getStatus(); }

    // Virtual function implementation
    void display() {
        cout << "| " << id
             << " | " << name
             << " | " << age
             << " | " << specialty
             << " | " << salary.getTotal()
             << " | " << salary.getRemaining()
             << " | " << salary.getStatus()
             << " |\n";
    }

    // Static function
    static int getTotalTrainers() {
        return totalTrainers;
    }

    static void showStats() {
        cout << "Total Trainers Registered: " << totalTrainers << endl;
    }
};

// Static member initialize
int Trainer::totalTrainers = 0;