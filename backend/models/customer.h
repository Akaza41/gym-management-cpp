//customer.h
#pragma once
#include <cstring>
#include "payment.h"

class Customer {
private:
    int id;
    char name[50];
    int age;
    Payment payment;

public:
    Customer() : id(0), age(0) {
        memset(name, 0, sizeof(name));
    }

    void setData(int _id, const char* _name, int _age, float fee) {
        id = _id;
        strcpy(name, _name);
        age = _age;
        payment.setFee(fee);
    }

    void payFee(float amount) {
        payment.pay(amount);
    }

    int getId() { return id; }
    const char* getName() { return name; }
    int getAge() { return age; }
    float getTotal() { return payment.getTotal(); }
    float getRemaining() { return payment.getRemaining(); }
    char* getStatus() { return payment.getStatus(); }
};