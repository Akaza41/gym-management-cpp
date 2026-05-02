# 🏋️ Gym Management System
### C++ OOP Project with Web UI

A complete Gym Management System built in **C++** using Object-Oriented Programming concepts.  
It has a real web interface where you can register customers, trainers, staff, view records, and process payments — all connected to a live C++ backend!

---

## 👨‍💻 What This Project Does

| Feature | Description |
|---|---|
| 📋 Register | Add Customers, Trainers, and Staff |
| 👁️ View | See all records in a clean table |
| 💰 Pay | Process customer fees and staff/trainer salaries |
| 🖥️ API Logs | See which C++ functions run in real-time |

---

## 🧠 OOP Concepts Used

- **Classes & Objects** — Customer, Trainer, Staff, Payment
- **Inheritance** — Person (base) → Customer, Trainer, Staff (derived)
- **Encapsulation** — private data with public getters/setters
- **Polymorphism** — virtual `display()` function

---

## 🛠️ Tech Stack

| Layer | Technology |
|---|---|
| Backend | C++ with httplib (header-only library) |
| Frontend | HTML, CSS, JavaScript |
| Compiler | GCC 15.2.0 via MSYS2 |
| Sharing | ngrok (to share with friends) |

---

## 📁 Project Folder Structure

```
Uni GYM Project Cpp 2nd_semester/
│
├── backend/
│   └── main.cpp          ← All C++ code (classes + API routes)
│
├── frontend/
│   └── index.html        ← The web UI (open in browser)
│
├── include/
│   └── httplib.h         ← HTTP library (downloaded, don't touch)
│
└── README.md             ← This file
```

> ⚠️ **Note:** `httplib.h` has 20,000+ lines — that's normal! It's a ready-made library, not your code. Your actual code is in `main.cpp`.

---

## ⚙️ Full Setup Guide — From Zero to Running

> Follow every step carefully. Even if you have never done this before, you will be fine!

---

### ✅ STEP 1 — Install VS Code

1. Go to 👉 https://code.visualstudio.com
2. Click **Download for Windows**
3. Run the installer, keep clicking **Next**, then **Finish**
4. Open VS Code
5. On the left side click the **Extensions** icon (looks like 4 squares)
6. Search: `C/C++` → Install the one by **Microsoft**

---

### ✅ STEP 2 — Install CMake

1. Go to 👉 https://cmake.org/download
2. Under **Latest Release**, download:  
   `cmake-4.3.2-windows-x86_64.msi`
3. Run the `.msi` installer
4. When it asks — select **"Add CMake to system PATH for all users"** ✅
5. Click Next → Finish
6. Open **CMD** (search "cmd" in Windows search, open it) and type:
```cmd
cmake --version
```
You should see: `cmake version 4.3.2` ✅

---

### ✅ STEP 3 — Install MSYS2 (This gives us the C++ compiler)

> MSYS2 is a tool that lets us install a modern C++ compiler easily.

1. Open **CMD as Administrator**  
   *(search "cmd" → right click → Run as Administrator)*
2. Run this command:
```cmd
winget install -e --id MSYS2.MSYS2
```
3. Wait for it to finish (may take a few minutes)
4. After it installs, search in Windows Start Menu for: **MSYS2 UCRT64**
5. Open it — a new terminal window will appear
6. Inside that MSYS2 terminal, type this exactly:
```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
```
7. It will ask `:: Proceed with installation? [Y/n]` — type `y` and press Enter
8. Wait for it to finish ✅

---

### ✅ STEP 4 — Add the Compiler to PATH

> PATH tells Windows where to find programs. We need to add our new compiler.

Open **CMD as Administrator** and run these two commands **one by one**:

```cmd
setx PATH "%PATH:C:\MinGW\bin;=%" /M
```
```cmd
setx PATH "C:\msys64\ucrt64\bin;%PATH%" /M
```

Now **close CMD completely** and open a **fresh new CMD** (as Admin), then run:
```cmd
g++ --version
```

You should see something like:
```
g++ (Rev13, Built by MSYS2 project) 15.2.0
```
✅ If you see this — compiler is ready!

---

### ✅ STEP 5 — Install Git

> Git is needed to download (clone) this project.

1. Go to 👉 https://git-scm.com/download/win
2. Download and install it (keep all default settings, just click Next)
3. After install, open CMD and check:
```cmd
git --version
```
Should show a version number ✅

---

### ✅ STEP 6 — Clone This Project

Open CMD and run:
```cmd
git clone https://github.com/Akaza41/gym-management-cpp.git
```

Then go into the project folder:
```cmd
cd gym-management-cpp
```

Now open it in VS Code:
```cmd
code .
```

---

### ✅ STEP 7 — Compile the C++ Server

In CMD, run this one command (copy it exactly):
```cmd
cd backend && g++ -std=c++17 -o server main.cpp -I"../include" -lws2_32 -lwsock32
```

If no errors appear — it compiled successfully! ✅  
If errors appear — check that you did Step 4 correctly.

---

### ✅ STEP 8 — Run the Server

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

🎉 Your C++ backend is now running!

> ⚠️ **Keep this CMD window open.** Do not close it while using the app.

---

### ✅ STEP 9 — Open the Web UI

1. Keep the server running in CMD
2. Go to your project folder in File Explorer
3. Open the `frontend` folder
4. Double-click `index.html` — it opens in your browser
5. Done! Try registering a customer 🎉

---

## 🌐 Share With Friends Using ngrok

> ngrok creates a public link so your friends can access your app while your PC is on.

### Install ngrok

Open CMD and run:
```cmd
winget install ngrok.ngrok
```

Close CMD, reopen it, then add your auth token:
```cmd
ngrok config add-authtoken 3DA0ctfrOxYTgP5unY4ON19jOM2_4hiv3MAC7Zd7zucRDvphp
```

### Run ngrok

Open a **second CMD window** (keep server.exe running in the first one) and run:
```cmd
ngrok http 8080
```

You will see something like:
```
Forwarding    https://abc123.ngrok-free.app -> http://localhost:8080
```

That `https://abc123.ngrok-free.app` link — **send this to your friends!**  
They can open it in their browser and use your app 🔥

> ⚠️ The link changes every time you restart ngrok. Send the new link to friends each time.

---

## 🚀 How to Run Every Time (Quick Reference)

Every time you want to start the project, open **2 CMD windows**:

**CMD Window 1 — Start the server:**
```cmd
cd "PATH\TO\gym-management-cpp\backend" && g++ -std=c++17 -o server main.cpp -I"../include" -lws2_32 -lwsock32 && server.exe
```

**CMD Window 2 — Start ngrok (if sharing with friends):**
```cmd
ngrok http 8080
```

Then open `frontend/index.html` in your browser — or use the ngrok link!

---

## ❓ Common Problems & Fixes

| Problem | Fix |
|---|---|
| `g++ not recognized` | Redo Step 4, make sure to close and reopen CMD |
| `server.exe` not found | Run the compile command in Step 7 first |
| ngrok link not working | Make sure `server.exe` is still running in CMD 1 |
| View shows no records | Register some data first, then click View |
| Friends can't access | Make sure both CMDs are open and ngrok is running |

---

## 👤 Author

**Akaza41** — 2nd Semester OOP Project  
GitHub: https://github.com/Akaza41/gym-management-cpp