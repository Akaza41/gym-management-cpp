#pragma once
#include <cstring>

class Payment {
private:
    float total;
    float remaining;
    char status[10];

public:
    Payment() {
        total = 0;
        remaining = 0;
        updateStatus();
    }

    void setFee(float f) {
        total = f;
        remaining = f;
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

    float getTotal() { return total; }
    float getRemaining() { return remaining; }
    char* getStatus() { return status; }
};