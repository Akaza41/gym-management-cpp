#include <iostream>
#include <cstring>
#include <string>
#include "../include/httplib.h"

using namespace std;

// ========== PAYMENT ==========
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

// ========== PERSON ==========
class Person {
protected:
    char name[50];
    int age;
public:
    virtual void display() = 0;
};

// ========== CUSTOMER ==========
class Customer : public Person {
private:
    int id;
    Payment payment;

public:
    Customer() { id = 0; age = 0; strcpy(name, ""); }

    void setData(int _id, const char* _name, int _age, float fee) {
        id = _id;
        strcpy(name, _name);
        age = _age;
        payment.setFee(fee);
    }

    void payFee(float amount) { payment.pay(amount); }
    int getId() { return id; }
    char* getName() { return name; }
    int getAge() { return age; }
    float getTotal() { return payment.getTotal(); }
    float getRemaining() { return payment.getRemaining(); }
    char* getStatus() { return payment.getStatus(); }

    void display() {
        cout << "| " << id << " | " << name << " | " << age
             << " | " << payment.getTotal() << " | "
             << payment.getRemaining() << " | " << payment.getStatus() << " |\n";
    }
};

// ========== TRAINER ==========
class Trainer : public Person {
private:
    int id;
    char specialty[30];
    Payment salary;

public:
    Trainer() { id = 0; age = 0; strcpy(name, ""); strcpy(specialty, ""); }

    void setData(int _id, const char* _name, int _age, const char* _spec, float sal) {
        id = _id;
        strcpy(name, _name);
        age = _age;
        strcpy(specialty, _spec);
        salary.setFee(sal);
    }

    void paySalary(float amount) { salary.pay(amount); }
    int getId() { return id; }
    char* getName() { return name; }
    int getAge() { return age; }
    char* getSpecialty() { return specialty; }
    float getTotal() { return salary.getTotal(); }
    float getRemaining() { return salary.getRemaining(); }
    char* getStatus() { return salary.getStatus(); }

    void display() {
        cout << "| " << id << " | " << name << " | " << age
             << " | " << specialty << " | " << salary.getTotal() << " | "
             << salary.getRemaining() << " | " << salary.getStatus() << " |\n";
    }
};

// ========== STAFF ==========
class Staff : public Person {
private:
    int id;
    char role[30];
    Payment salary;

public:
    Staff() { id = 0; age = 0; strcpy(name, ""); strcpy(role, ""); }

    void setData(int _id, const char* _name, int _age, const char* _role, float sal) {
        id = _id;
        strcpy(name, _name);
        age = _age;
        strcpy(role, _role);
        salary.setFee(sal);
    }

    void paySalary(float amount) { salary.pay(amount); }
    int getId() { return id; }
    char* getName() { return name; }
    int getAge() { return age; }
    char* getRole() { return role; }
    float getTotal() { return salary.getTotal(); }
    float getRemaining() { return salary.getRemaining(); }
    char* getStatus() { return salary.getStatus(); }

    void display() {
        cout << "| " << id << " | " << name << " | " << age
             << " | " << role << " | " << salary.getTotal() << " | "
             << salary.getRemaining() << " | " << salary.getStatus() << " |\n";
    }
};

// ========== GLOBAL DATA ==========
Customer customers[50];
Trainer trainers[20];
Staff staffs[20];
int c = 0, t = 0, s = 0;

// ========== CORS HELPER ==========
void setCORS(httplib::Response& res) {
    res.set_header("Access-Control-Allow-Origin", "*");
    res.set_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
    res.set_header("Access-Control-Allow-Headers", "Content-Type");
}

int main() {

    httplib::Server app;

    // Handle OPTIONS preflight for all routes
    app.Options(".*", [](const httplib::Request&, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
        res.set_header("Access-Control-Allow-Headers", "Content-Type");
        res.status = 204;
    });

    // ---------- REGISTER CUSTOMER ----------
    app.Post("/register/customer", [&](const httplib::Request& req, httplib::Response& res) {
        setCORS(res);
        string name = req.get_param_value("name");
        int age = stoi(req.get_param_value("age"));
        float fee = stof(req.get_param_value("fee"));

        customers[c].setData(100 + c + 1, name.c_str(), age, fee);
        c++;

        cout << "\n[API CALL] POST /register/customer\n";
        cout << ">> Customer::setData() called\n";
        cout << ">> Payment::setFee(" << fee << ") called\n";
        cout << ">> customers[" << c-1 << "] stored\n";
        customers[c-1].display();

        res.set_content("Customer Registered! ID: " + to_string(100 + c), "text/plain");
    });

    // ---------- REGISTER TRAINER ----------
    app.Post("/register/trainer", [&](const httplib::Request& req, httplib::Response& res) {
        setCORS(res);
        string name = req.get_param_value("name");
        int age = stoi(req.get_param_value("age"));
        string specialty = req.get_param_value("specialty");
        float sal = stof(req.get_param_value("salary"));

        trainers[t].setData(200 + t + 1, name.c_str(), age, specialty.c_str(), sal);
        t++;

        cout << "\n[API CALL] POST /register/trainer\n";
        cout << ">> Trainer::setData() called\n";
        cout << ">> Payment::setFee(" << sal << ") called\n";
        cout << ">> trainers[" << t-1 << "] stored\n";
        trainers[t-1].display();

        res.set_content("Trainer Registered! ID: " + to_string(200 + t), "text/plain");
    });

    // ---------- REGISTER STAFF ----------
    app.Post("/register/staff", [&](const httplib::Request& req, httplib::Response& res) {
        setCORS(res);
        string name = req.get_param_value("name");
        int age = stoi(req.get_param_value("age"));
        string role = req.get_param_value("role");
        float sal = stof(req.get_param_value("salary"));

        staffs[s].setData(300 + s + 1, name.c_str(), age, role.c_str(), sal);
        s++;

        cout << "\n[API CALL] POST /register/staff\n";
        cout << ">> Staff::setData() called\n";
        cout << ">> Payment::setFee(" << sal << ") called\n";
        cout << ">> staffs[" << s-1 << "] stored\n";
        staffs[s-1].display();

        res.set_content("Staff Registered! ID: " + to_string(300 + s), "text/plain");
    });

    // ---------- VIEW CUSTOMERS ----------
    app.Get("/view/customers", [&](const httplib::Request&, httplib::Response& res) {
        setCORS(res);
        cout << "\n[API CALL] GET /view/customers\n";
        cout << ">> Customer::display() called for " << c << " records\n";

        string result = "";
        for(int i = 0; i < c; i++) {
            result += to_string(customers[i].getId()) + "|" +
                      string(customers[i].getName()) + "|" +
                      to_string(customers[i].getAge()) + "|" +
                      to_string((int)customers[i].getTotal()) + "|" +
                      to_string((int)customers[i].getRemaining()) + "|" +
                      string(customers[i].getStatus()) + "\n";
        }

        if(result.empty()) result = "EMPTY";
        res.set_content(result, "text/plain");
    });

    // ---------- VIEW TRAINERS ----------
    app.Get("/view/trainers", [&](const httplib::Request&, httplib::Response& res) {
        setCORS(res);
        cout << "\n[API CALL] GET /view/trainers\n";
        cout << ">> Trainer::display() called for " << t << " records\n";

        string result = "";
        for(int i = 0; i < t; i++) {
            result += to_string(trainers[i].getId()) + "|" +
                      string(trainers[i].getName()) + "|" +
                      to_string(trainers[i].getAge()) + "|" +
                      string(trainers[i].getSpecialty()) + "|" +
                      to_string((int)trainers[i].getTotal()) + "|" +
                      to_string((int)trainers[i].getRemaining()) + "|" +
                      string(trainers[i].getStatus()) + "\n";
        }

        if(result.empty()) result = "EMPTY";
        res.set_content(result, "text/plain");
    });

    // ---------- VIEW STAFF ----------
    app.Get("/view/staff", [&](const httplib::Request&, httplib::Response& res) {
        setCORS(res);
        cout << "\n[API CALL] GET /view/staff\n";
        cout << ">> Staff::display() called for " << s << " records\n";

        string result = "";
        for(int i = 0; i < s; i++) {
            result += to_string(staffs[i].getId()) + "|" +
                      string(staffs[i].getName()) + "|" +
                      to_string(staffs[i].getAge()) + "|" +
                      string(staffs[i].getRole()) + "|" +
                      to_string((int)staffs[i].getTotal()) + "|" +
                      to_string((int)staffs[i].getRemaining()) + "|" +
                      string(staffs[i].getStatus()) + "\n";
        }

        if(result.empty()) result = "EMPTY";
        res.set_content(result, "text/plain");
    });

    // ---------- PAY CUSTOMER ----------
    app.Post("/pay/customer", [&](const httplib::Request& req, httplib::Response& res) {
        setCORS(res);
        int id = stoi(req.get_param_value("id"));
        float amount = stof(req.get_param_value("amount"));

        cout << "\n[API CALL] POST /pay/customer\n";
        cout << ">> Customer::payFee(" << amount << ") called\n";
        cout << ">> Payment::pay() -> remaining -= amount\n";

        for(int i = 0; i < c; i++) {
            if(customers[i].getId() == id) {
                customers[i].payFee(amount);
                customers[i].display();
                res.set_content("Payment Successful! Remaining: " + to_string((int)customers[i].getRemaining()), "text/plain");
                return;
            }
        }
        res.set_content("Customer Not Found!", "text/plain");
    });

    // ---------- PAY TRAINER ----------
    app.Post("/pay/trainer", [&](const httplib::Request& req, httplib::Response& res) {
        setCORS(res);
        int id = stoi(req.get_param_value("id"));
        float amount = stof(req.get_param_value("amount"));

        cout << "\n[API CALL] POST /pay/trainer\n";
        cout << ">> Trainer::paySalary(" << amount << ") called\n";
        cout << ">> Payment::pay() -> remaining -= amount\n";

        for(int i = 0; i < t; i++) {
            if(trainers[i].getId() == id) {
                trainers[i].paySalary(amount);
                trainers[i].display();
                res.set_content("Salary Paid! Remaining: " + to_string((int)trainers[i].getRemaining()), "text/plain");
                return;
            }
        }
        res.set_content("Trainer Not Found!", "text/plain");
    });

    // ---------- PAY STAFF ----------
    app.Post("/pay/staff", [&](const httplib::Request& req, httplib::Response& res) {
        setCORS(res);
        int id = stoi(req.get_param_value("id"));
        float amount = stof(req.get_param_value("amount"));

        cout << "\n[API CALL] POST /pay/staff\n";
        cout << ">> Staff::paySalary(" << amount << ") called\n";
        cout << ">> Payment::pay() -> remaining -= amount\n";

        for(int i = 0; i < s; i++) {
            if(staffs[i].getId() == id) {
                staffs[i].paySalary(amount);
                staffs[i].display();
                res.set_content("Salary Paid! Remaining: " + to_string((int)staffs[i].getRemaining()), "text/plain");
                return;
            }
        }
        res.set_content("Staff Not Found!", "text/plain");
    });

    cout << "================================\n";
    cout << "  GYM MANAGEMENT API RUNNING\n";
    cout << "  http://localhost:8080\n";
    cout << "================================\n";

    app.listen("0.0.0.0", 8080);
    return 0;
}