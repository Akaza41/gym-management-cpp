#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Payment {
private:
    float total;
    float remaining;
    char status[10];

public:
    // Static member — track total payments in system
    static int totalPayments;

    Payment() {
        total = 0;
        remaining = 0;
        updateStatus();
    }

    void setFee(float f) {
        total = f;
        remaining = f;
        totalPayments++;
        updateStatus();
    }

    void loadPayment(float t, float r) {
        total = t;
        remaining = r;
        totalPayments++;
        updateStatus();
    }

    void pay(float amount) {
        remaining -= amount;
        updateStatus();
    }

    void updateStatus() {
        if(remaining <= 0) {
            remaining = 0;
            strcpy(status, "PAID");
        } else {
            strcpy(status, "PENDING");
        }
    }

    // Operator overloading — compare two payments by remaining amount
    bool operator>(Payment& other) {
        return remaining > other.remaining;
    }

    bool operator==(Payment& other) {
        return remaining == other.remaining;
    }

    float getTotal() { return total; }
    float getRemaining() { return remaining; }
    char* getStatus() { return status; }

    // Static function
    static void showTotalPayments() {
        cout << "Total Payment Records: " << totalPayments << endl;
    }
};

// Static member initialize
int Payment::totalPayments = 0;