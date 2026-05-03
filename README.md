# Gym Management System

A full-stack Gym Management System built as a 2nd Semester Object-Oriented Programming project. The backend is written entirely in C++ using core OOP principles, and the frontend is a browser-based interface that communicates with the C++ server through a REST API.

This project demonstrates how C++ can be used beyond console applications — the same OOP classes that would normally take input from `cin` instead receive data from a live web interface, process it in C++, and send results back to the browser in real time.

---

## What the System Does

The system manages three types of people in a gym — customers, trainers, and staff. Each person can be registered, viewed, and paid through the web interface. Every action on the website triggers actual C++ functions on the backend, which are logged to the server console in real time so you can see exactly which classes and functions are being called.

---

## OOP Concepts Implemented

| Concept | Where Used |
|---|---|
| Classes and Objects | Customer, Trainer, Staff, Payment |
| Inheritance | Person (base) → Customer, Trainer, Staff (derived) |
| Encapsulation | Private data members with public getters and setters |
| Polymorphism | Virtual `display()` function overridden in each derived class |
| Virtual Functions | Pure virtual `display()` in Person base class |
| Static Members | `totalCustomers`, `totalTrainers`, `totalStaff` counters |
| Operator Overloading | `==` and `>` operators for comparing objects by ID |
| Templates | Generic `searchById<T>()` and `displayAll<T>()` functions |
| File Handling | Data saved to `.txt` files and loaded on server start |

---

## Tech Stack

| Layer | Technology |
|---|---|
| Backend | C++ with httplib (header-only HTTP library) |
| Frontend | HTML, CSS, JavaScript |
| Compiler | GCC 15.2.0 via MSYS2 |
| Deployment | Railway.app (Docker-based, Linux server) |
| Local Sharing | ngrok (temporary public tunnel) |

---

## Project Structure

```
gym-management-cpp/
│
├── backend/
│   ├── main.cpp              C++ server entry point, API routes, templates
│   ├── models/
│   │   ├── person.h          Abstract base class with virtual display()
│   │   ├── customer.h        Customer class, inherits Person
│   │   ├── trainer.h         Trainer class, inherits Person
│   │   ├── staff.h           Staff class, inherits Person
│   │   └── payment.h         Payment class with operator overloading
│   └── routes/
│       └── register.h        Route helper (unused in final version)
│
├── frontend/
│   └── index.html            Complete web UI — single file, no frameworks
│
├── include/
│   └── httplib.h             Third-party HTTP library (not written by us)
│
├── Dockerfile                Linux build instructions for Railway deployment
└── README.md                 This file
```

> `httplib.h` contains over 20,000 lines and is not part of the OOP project — it is a third-party library that handles the HTTP layer so C++ can act as a web server.

---

## How It Works

The browser sends HTTP requests to the C++ server. The server parses each request, calls the appropriate C++ class methods, and sends a response back. The browser then displays the result.

```
User fills form and clicks Register
           |
           v
JavaScript sends POST /register/customer to C++ server
           |
           v
C++ server calls Customer::setData() and Payment::setFee()
           |
           v
Static counter increments — Customer::showStats() called
           |
           v
display() virtual function prints to server console
           |
           v
Response sent back — browser shows success message
```

Everything visible in the browser originated from C++ logic on the backend.

---

## Deployment

This project was deployed on Railway.app using Docker. The Dockerfile tells Railway how to set up a Linux environment, install the GCC compiler, compile the C++ code, and run the server — all automatically on every push to GitHub.

The Railway deployment is available at:

```
https://gym-management-cpp-production.up.railway.app
```

Since Railway's free tier does not support persistent volumes, the deployed version stores data in memory only. Data is lost when the server restarts. For persistent data with file handling, the project is run locally where `.txt` files store and reload data between sessions.

---

## Setup Guide — Windows

Follow every step in order. Do not skip any step.

### Step 1 — Open CMD as Administrator

Search for `cmd` in the Windows start menu, right-click on Command Prompt, and select Run as administrator. A black window will open — this is CMD.

Every time this guide says "open CMD as Administrator", follow these same steps.

### Step 2 — Install VS Code

Download from https://code.visualstudio.com and install it. After installing, open VS Code, go to the Extensions panel on the left side, search for `C/C++`, and install the extension made by Microsoft.

### Step 3 — Install CMake

Download `cmake-4.3.2-windows-x86_64.msi` from https://cmake.org/download and run it. When the installer asks about PATH, select "Add CMake to system PATH for all users". After installing, verify with:

```
cmake --version
```

### Step 4 — Install MSYS2 and GCC

Open CMD as Administrator and run:

```
winget install -e --id MSYS2.MSYS2
```

After it finishes, search for MSYS2 UCRT64 in the Windows start menu and open it. Inside that terminal, run:

```
pacman -S mingw-w64-ucrt-x86_64-gcc
```

Type `y` when asked and wait for installation to complete.

### Step 5 — Add GCC to PATH

Open CMD as Administrator and run these two commands one at a time:

```
setx PATH "%PATH:C:\MinGW\bin;=%" /M
```

```
setx PATH "C:\msys64\ucrt64\bin;%PATH%" /M
```

Close CMD completely, open a new CMD as Administrator, and verify:

```
g++ --version
```

You should see GCC 15.2.0 or similar.

### Step 6 — Install Git

Download from https://git-scm.com/download/win, run the installer with all default settings, and verify:

```
git --version
```

### Step 7 — Clone the Project

Open CMD as Administrator and run:

```
cd %USERPROFILE%\Documents
git clone https://github.com/Akaza41/gym-management-cpp.git
cd gym-management-cpp
code .
```

VS Code will open with the full project.

### Step 8 — Compile the Server

```
cd backend
g++ -std=c++17 -o server main.cpp -I"../include" -lws2_32 -lwsock32 -DWIN32_LEAN_AND_MEAN
```

If no errors appear, compilation was successful.

> The `-DWIN32_LEAN_AND_MEAN` flag resolves a conflict between the Windows SDK and the C++ standard library on newer GCC versions.

### Step 9 — Run the Server

```
server.exe
```

You should see:

```
================================
  GYM MANAGEMENT API RUNNING
  http://localhost:8080
================================
```

Keep this window open. If it closes, the server stops.

If Windows shows a firewall popup, click Allow Access.

### Step 10 — Open the Web UI

Open File Explorer, navigate to `Documents > gym-management-cpp > frontend`, and double-click `index.html`. It will open in your browser.

---

## API Configuration

The frontend connects to the backend through a single line in `index.html`:

```javascript
const API = "...";
```

Change this value depending on how you are running the project:

| Mode | Value |
|---|---|
| Local only | `http://localhost:8080` |
| Sharing via ngrok | Your ngrok URL |
| Railway deployment | `https://gym-management-cpp-production.up.railway.app` |

After changing the value, save the file. If using Railway or ngrok, also push to GitHub so the server re-serves the updated file.

---

## Sharing with Friends via ngrok

ngrok creates a temporary public URL that forwards to your local server. Anyone with the link can access your app as long as your PC is on and the server is running.

Install ngrok:

```
winget install ngrok.ngrok
```

Create a free account at https://dashboard.ngrok.com/signup, get your auth token, and run:

```
ngrok config add-authtoken YOUR_TOKEN_HERE
```

Then run the server in one CMD window and ngrok in another:

```
ngrok http 8080
```

Copy the forwarding URL and send it to your friends. The URL changes every time ngrok restarts.

---

## Quick Start — Every Session

```
cd %USERPROFILE%\Documents\gym-management-cpp\backend
g++ -std=c++17 -o server main.cpp -I"../include" -lws2_32 -lwsock32 -DWIN32_LEAN_AND_MEAN && server.exe
```

In a second CMD window, if sharing:

```
ngrok http 8080
```

Then open `frontend/index.html` in your browser, or share the ngrok link.

---

## Data and File Handling

The C++ server saves all registered customers, trainers, and staff to `.txt` files in the backend directory. When the server starts, it reads these files and loads existing data back into memory. This means data survives server restarts when running locally.

These data files are listed in `.gitignore` and are not pushed to GitHub, since they contain user data and are specific to each machine.

On Railway, data is stored in memory only and is lost on restart, since the free tier does not support persistent volumes.

---

## Common Problems

| Problem | Solution |
|---|---|
| `g++` not recognized | Close CMD, open a fresh one as Admin, try again |
| `server.exe` not found | Run the compile command in Step 8 first |
| Blank page or no connection | Make sure server.exe is still running |
| View shows no records | Register some data first, then click View |
| ngrok link not working | Make sure both server and ngrok are running |
| Windows Firewall popup | Click Allow Access |
| ngrok warning page | Click Visit Site |
| Data gone after restart | Expected — register again, or use local file handling |
| `WIN32_LEAN_AND_MEAN` warning | Harmless warning, not an error — server still runs |

---

## Author

Akaza41 — 2nd Semester OOP Project
https://github.com/Akaza41/gym-management-cpp