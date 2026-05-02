//trainer.h
#pragma once
#include <cstring>
#include "payment.h"

class Trainer {

private:
    int id;
    char name[50];
    int age;
    char specialty[30];
    Payment salary;

public:
    void setData(int _id, const char* _name, int _age, const char* _spec, float sal) {
        id = _id;
        strcpy(name, _name);
        age = _age;
        strcpy(specialty, _spec);
        salary.setFee(sal);
    }

    void paySalary(float amount) {
        salary.pay(amount);
    }

    int getId() { return id; }
    char* getName() { return name; }
    int getAge() { return age; }
    char* getSpecialty() { return specialty; }
    float getTotal() { return salary.getTotal(); }
    float getRemaining() { return salary.getRemaining(); }
    char* getStatus() { return salary.getStatus(); }
};