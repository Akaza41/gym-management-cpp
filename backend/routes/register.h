#pragma once
#include "../include/httplib.h"
#include "../models/customer.h"
#include "../models/trainer.h"
#include "../models/staff.h"

// Global arrays - same as your original code
extern Customer customers[50];
extern Trainer trainers[20];
extern Staff staffs[20];
extern int c, t, s;

void registerRoutes(httplib::Server &app) {

    // ---------- REGISTER CUSTOMER ----------
    app.Post("/register/customer", [](const httplib::Request& req, httplib::Response& res) {
        
        res.set_header("Access-Control-Allow-Origin", "*");
        
        // Get data from request
        std::string name = req.get_param_value("name");
        int age = std::stoi(req.get_param_value("age"));
        float fee = std::stof(req.get_param_value("fee"));

        customers[c].setData(100 + c + 1, name.c_str(), age, fee);
        c++;

        res.set_content("Customer Registered Successfully!", "text/plain");
    });

    // ---------- REGISTER TRAINER ----------
    app.Post("/register/trainer", [](const httplib::Request& req, httplib::Response& res) {
        
        res.set_header("Access-Control-Allow-Origin", "*");
        
        std::string name = req.get_param_value("name");
        int age = std::stoi(req.get_param_value("age"));
        std::string specialty = req.get_param_value("specialty");
        float salary = std::stof(req.get_param_value("salary"));

        trainers[t].setData(200 + t + 1, name.c_str(), age, specialty.c_str(), salary);
        t++;

        res.set_content("Trainer Registered Successfully!", "text/plain");
    });

    // ---------- REGISTER STAFF ----------
    app.Post("/register/staff", [](const httplib::Request& req, httplib::Response& res) {
        
        res.set_header("Access-Control-Allow-Origin", "*");
        
        std::string name = req.get_param_value("name");
        int age = std::stoi(req.get_param_value("age"));
        std::string role = req.get_param_value("role");
        float salary = std::stof(req.get_param_value("salary"));

        staffs[s].setData(300 + s + 1, name.c_str(), age, role.c_str(), salary);
        s++;

        res.set_content("Staff Registered Successfully!", "text/plain");
    });
}