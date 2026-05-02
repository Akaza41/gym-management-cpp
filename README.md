# 🏋️ Gym Management System
C++ OOP based Gym Management System with Web UI using httplib.

---

## 👨‍💻 Tech Stack
- **Backend:** C++ (OOP) + httplib
- **Frontend:** HTML, CSS, JavaScript
- **Compiler:** GCC 15.2.0 via MSYS2

## 🧠 OOP Concepts Used
- Classes & Objects
- Inheritance (Person → Customer, Trainer, Staff)
- Encapsulation
- Polymorphism (virtual display())

---

## ⚙️ Setup Guide (Windows) — From Scratch

### Step 1 — Install VS Code
1. Go to https://code.visualstudio.com
2. Download and install
3. Install extension: **C/C++** by Microsoft

---

### Step 2 — Install CMake
1. Go to https://cmake.org/download
2. Download **cmake-4.3.2-windows-x86_64.msi**
3. Run → check **"Add CMake to system PATH"** ✅
4. Verify in CMD:
```cmd
cmake --version
```

---

### Step 3 — Install MSYS2
1. Open CMD as Admin:
```cmd
winget install -e --id MSYS2.MSYS2
```
2. Open **MSYS2 UCRT64** from Start Menu
3. Inside MSYS2 terminal type:
```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
```
4. Press `y` ✅

---

### Step 4 — Add GCC to PATH
Open CMD as **Admin**, run one by one:
```cmd
setx PATH "%PATH:C:\MinGW\bin;=%" /M
setx PATH "C:\msys64\ucrt64\bin;%PATH%" /M
```
Close CMD, reopen and verify:
```cmd
g++ --version
```
Should show: `g++ 15.2.0` ✅

---

### Step 5 — Clone the Project
```cmd
git clone https://github.com/Akaza41/gym-management-cpp.git
cd gym-management-cpp
```

---

### Step 6 — Compile the Server
```cmd
cd backend
g++ -std=c++17 -o server main.cpp -I"../include" -lws2_32 -lwsock32
```

---

### Step 7 — Run the Server
```cmd
server.exe
```
You should see:
```
================================
  GYM MANAGEMENT API RUNNING
  http://localhost:8080
================================
```

---

### Step 8 — Open the UI
1. Keep `server.exe` running in CMD
2. Open `frontend/index.html` in browser
3. Done! 🎉

---

## 🚀 Features
- ✅ Register Customers, Trainers, Staff
- ✅ View all records in table
- ✅ Process Payments & Salaries
- ✅ Live C++ API call logs shown in UI
- ✅ Console shows which C++ functions called