#include <iostream>
#include <fstream>
#include <string>
#include "models/payment.h"
#include "models/person.h"
#include "models/customer.h"
#include "models/trainer.h"
#include "models/staff.h"
#include "../include/httplib.h"
using namespace std;

// ========== TEMPLATES ==========
// Generic search by ID
template <typename T>
int searchById(T arr[], int size, int id) {
    for(int i = 0; i < size; i++) {
        if(arr[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

// Generic display all
template <typename T>
void displayAll(T arr[], int size) {
    if(size == 0) {
        cout << "No records found.\n";
        return;
    }
    for(int i = 0; i < size; i++) {
        arr[i].display();
    }
}

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

    // OPTIONS preflight
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
        Customer::showStats();
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
        Trainer::showStats();
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
        Staff::showStats();
        staffs[s-1].display();

        res.set_content("Staff Registered! ID: " + to_string(300 + s), "text/plain");
    });

    // ---------- VIEW CUSTOMERS ----------
    app.Get("/view/customers", [&](const httplib::Request&, httplib::Response& res) {
        setCORS(res);
        cout << "\n[API CALL] GET /view/customers\n";
        cout << ">> searchById<Customer>() template called\n";
        displayAll(customers, c);

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
        cout << ">> displayAll<Trainer>() template called\n";
        displayAll(trainers, t);

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
        cout << ">> displayAll<Staff>() template called\n";
        displayAll(staffs, s);

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
        cout << ">> searchById<Customer>() template called\n";

        int index = searchById(customers, c, id);
        if(index != -1) {
            customers[index].payFee(amount);
            customers[index].display();
            res.set_content("Payment Successful! Remaining: " + 
                to_string((int)customers[index].getRemaining()), "text/plain");
        } else {
            res.set_content("Customer Not Found!", "text/plain");
        }
    });

    // ---------- PAY TRAINER ----------
    app.Post("/pay/trainer", [&](const httplib::Request& req, httplib::Response& res) {
        setCORS(res);
        int id = stoi(req.get_param_value("id"));
        float amount = stof(req.get_param_value("amount"));

        cout << "\n[API CALL] POST /pay/trainer\n";
        cout << ">> searchById<Trainer>() template called\n";

        int index = searchById(trainers, t, id);
        if(index != -1) {
            trainers[index].paySalary(amount);
            trainers[index].display();
            res.set_content("Salary Paid! Remaining: " + 
                to_string((int)trainers[index].getRemaining()), "text/plain");
        } else {
            res.set_content("Trainer Not Found!", "text/plain");
        }
    });

    // ---------- PAY STAFF ----------
    app.Post("/pay/staff", [&](const httplib::Request& req, httplib::Response& res) {
        setCORS(res);
        int id = stoi(req.get_param_value("id"));
        float amount = stof(req.get_param_value("amount"));

        cout << "\n[API CALL] POST /pay/staff\n";
        cout << ">> searchById<Staff>() template called\n";

        int index = searchById(staffs, s, id);
        if(index != -1) {
            staffs[index].paySalary(amount);
            staffs[index].display();
            res.set_content("Salary Paid! Remaining: " + 
                to_string((int)staffs[index].getRemaining()), "text/plain");
        } else {
            res.set_content("Staff Not Found!", "text/plain");
        }
    });

    // ---------- SERVE FRONTEND ----------
    app.Get("/", [](const httplib::Request&, httplib::Response& res) {
        ifstream file("../frontend/index.html");
        string content((istreambuf_iterator<char>(file)),
                        istreambuf_iterator<char>());
        res.set_content(content, "text/html");
    });

    // ---------- SYSTEM STATS ----------
    app.Get("/stats", [&](const httplib::Request&, httplib::Response& res) {
        setCORS(res);
        string result = "";
        result += "Total Customers: " + to_string(c) + "\n";
        result += "Total Trainers: " + to_string(t) + "\n";
        result += "Total Staff: " + to_string(s) + "\n";
        result += "Total Payments: " + to_string(Payment::totalPayments) + "\n";
        res.set_content(result, "text/plain");
    });

    cout << "================================\n";
    cout << "  GYM MANAGEMENT API RUNNING\n";
    cout << "  http://localhost:8080\n";
    cout << "================================\n";

    app.listen("0.0.0.0", 8080);
    return 0;
}