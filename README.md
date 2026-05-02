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
gym-management-cpp/
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

> ⚠️ **Note:** `httplib.h` has 20,000+ lines — that is completely normal!
> It is a ready-made library written by someone else. Your actual project code is only in `main.cpp`.

---

## ⚙️ Full Setup Guide — From Zero to Running

> 📌 Follow every step in order. Do not skip any step.
> Even if you have never done this before, you will be fine!

---

### ✅ STEP 1 — Learn How to Open CMD as Administrator

> CMD (Command Prompt) is the black window where we type commands.
> We need to open it as Administrator so it has full permissions to install things.

**How to open CMD as Administrator:**
1. Press the **Windows key** on your keyboard
2. Type `cmd`
3. You will see **Command Prompt** appear in results
4. **Right click** on it
5. Click **"Run as administrator"**
6. A black window will open — this is CMD ✅

> ⚠️ Whenever this guide says "open CMD as Administrator" — always follow these exact steps above.

---

### ✅ STEP 2 — Install VS Code

> VS Code is the program where you can read and edit the project code.

1. Go to 👉 https://code.visualstudio.com
2. Click the big **Download for Windows** button
3. Open the downloaded file and keep clicking **Next**, then **Finish**
4. Open VS Code from your Desktop or Start Menu
5. On the left side, click the **Extensions icon** (it looks like 4 small squares)
6. In the search box type: `C/C++`
7. Click **Install** on the one made by **Microsoft** ✅

---

### ✅ STEP 3 — Install CMake

> CMake is a tool that helps build C++ projects. We need it installed even if we do not use it directly.

1. Go to 👉 https://cmake.org/download
2. Scroll down to find **"Latest Release"**
3. Download this exact file: `cmake-4.3.2-windows-x86_64.msi`
4. Open the downloaded `.msi` file
5. When installer asks about PATH — select **"Add CMake to system PATH for all users"** ✅
6. Keep clicking Next → Finish

**Verify it installed correctly:**

Open CMD as Administrator (see Step 1) and type:
```cmd
cmake --version
```
Press Enter. You should see something like:
```
cmake version 4.3.2
```
If you see this — CMake is ready ✅

---

### ✅ STEP 4 — Install MSYS2 (The C++ Compiler)

> MSYS2 is a tool that gives us a modern C++ compiler called GCC.
> Without this, we cannot turn our C++ code into a running program.

**Part A — Install MSYS2:**

Open CMD as Administrator and run:
```cmd
winget install -e --id MSYS2.MSYS2
```
Wait for it to finish. It will download and install automatically ✅

**Part B — Install the C++ Compiler inside MSYS2:**

1. Press the **Windows key**
2. Search for: `MSYS2 UCRT64`
3. Click to open it — a new terminal window will appear (it looks different from CMD)
4. Inside that window, type this exactly and press Enter:
```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
```
5. It will ask:
```
:: Proceed with installation? [Y/n]
```
6. Type `y` and press Enter
7. Wait for everything to download and install ✅

---

### ✅ STEP 5 — Add the Compiler to Windows PATH

> PATH is a list inside Windows that tells it where to look for programs when you type a command.
> Right now Windows does not know where our new compiler is — we need to tell it.

Open CMD as Administrator and run these **two commands one by one**.
After each command press Enter and wait for it to say `SUCCESS`:

**Command 1:**
```cmd
setx PATH "%PATH:C:\MinGW\bin;=%" /M
```
You should see: `SUCCESS: Specified value was saved.`

**Command 2:**
```cmd
setx PATH "C:\msys64\ucrt64\bin;%PATH%" /M
```
You should see: `SUCCESS: Specified value was saved.`

Now **close CMD completely** by clicking the X button.

Open a **fresh new CMD as Administrator** (follow Step 1 again) and type:
```cmd
g++ --version
```
You should see something like:
```
g++ (Rev13, Built by MSYS2 project) 15.2.0
```
✅ If you see this — the compiler is working!

> ❌ If it says "not recognized" — close CMD and open a brand new one, then try the command again.

---

### ✅ STEP 6 — Install Git

> Git is a tool that lets you download this project to your computer.
> Think of it like a download manager made for code projects.

1. Go to 👉 https://git-scm.com/download/win
2. The download will start automatically
3. Open the downloaded file
4. Keep clicking **Next** on every screen (default settings are fine)
5. Click **Finish**

**Verify it installed:**

Open CMD as Administrator and type:
```cmd
git --version
```
You should see something like:
```
git version 2.44.0.windows.1
```
✅ Any version number means Git is ready! The number does not have to match exactly.

---

### ✅ STEP 7 — Download (Clone) This Project

> We will download the project into your Documents folder.
> The `%USERPROFILE%` part below automatically finds YOUR documents folder —
> it works for everyone no matter what your Windows username is. You do not need to change anything.

Open CMD as Administrator and run these commands **one by one**:

**Go to your Documents folder:**
```cmd
cd %USERPROFILE%\Documents
```

**Download the project:**
```cmd
git clone https://github.com/Akaza41/gym-management-cpp.git
```

You will see files downloading. When done, go into the project folder:
```cmd
cd gym-management-cpp
```

Now open the project in VS Code:
```cmd
code .
```
VS Code will open with all the project files visible on the left side ✅

---

### ✅ STEP 8 — Compile the C++ Server

> Compiling means turning the C++ code into a program (.exe file) that your computer can actually run.
> You only need to do this once — or again if the code ever changes.

In the same CMD window from Step 7, run:

```cmd
cd backend
```
```cmd
g++ -std=c++17 -o server main.cpp -I"../include" -lws2_32 -lwsock32
```

Wait a few seconds. If **no error appears** and you just see the folder path again — it compiled successfully! ✅

> ❌ If you see red error text — make sure you completed Step 5 correctly and are using a fresh CMD.

---

### ✅ STEP 9 — Run the Server

In the same CMD window, type:
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

> ⚠️ **Very Important:** Keep this CMD window open the entire time you use the app.
> If you close it — the server stops and nothing will work.

> 🔥 **Windows Firewall Popup:** The first time you run `server.exe`, Windows may show a
> security warning popup. Just click **"Allow Access"** — this is completely normal and safe.

---

### ✅ STEP 10 — Open the Web UI

1. Keep the server running in CMD from Step 9
2. Open **File Explorer** (the folder icon on your taskbar)
3. Go to: `This PC → Documents → gym-management-cpp → frontend`
4. Double click on `index.html`
5. It will open in your browser automatically

**Try it out:**
- Click **Register** → fill in the details → click the Register button
- Click **View** → see all your registered records in a table
- Click **Pay** → enter an ID and amount to process a payment

🎉 Everything is working now!

---

## 🌐 Share With Friends Using ngrok

> ngrok creates a public internet link so your friends can open your app
> in their browser from anywhere — as long as your PC is on and the server is running.

### Part A — Install ngrok

Open CMD as Administrator and run:
```cmd
winget install ngrok.ngrok
```
Close CMD completely and open a fresh new CMD as Administrator.

### Part B — Create Your Own Free ngrok Account

> ⚠️ Everyone must make their own free account. Do not use someone else's token.

1. Go to 👉 https://dashboard.ngrok.com/signup
2. Sign up for a free account (just email and password)
3. After signing in, go to 👉 https://dashboard.ngrok.com/get-started/your-authtoken
4. You will see a long token on that page — click the **Copy** button next to it

### Part C — Connect Your ngrok Account

In CMD as Administrator, run this command.
Replace `PASTE_YOUR_TOKEN_HERE` with the token you copied:
```cmd
ngrok config add-authtoken PASTE_YOUR_TOKEN_HERE
```
You should see: `Authtoken saved to configuration file` ✅

### Part D — Run Everything

You need **2 CMD windows open at the same time:**

**CMD Window 1 — Start the server:**
```cmd
cd %USERPROFILE%\Documents\gym-management-cpp\backend
g++ -std=c++17 -o server main.cpp -I"../include" -lws2_32 -lwsock32 && server.exe
```
Keep this window open ✅

**CMD Window 2 — Open a new CMD and start ngrok:**
```cmd
ngrok http 8080
```

You will see something like this appear:
```
Forwarding    https://abc123.ngrok-free.app -> http://localhost:8080
```

Copy that `https://abc123.ngrok-free.app` link and **send it to your friends!** 🔥

**When your friend opens the link:**
> They may see a warning page from ngrok saying "You are about to visit..."
> This is completely normal — they just need to click **"Visit Site"** and the app will open.

> ⚠️ The link changes every time you restart ngrok.
> If you restart, copy the new link and send it to your friends again.

---

## 🚀 Quick Start — Every Time You Want to Run the Project

After the one-time setup above is done, every time you want to use the project just do this:

**Open CMD Window 1 — Start the server:**
```cmd
cd %USERPROFILE%\Documents\gym-management-cpp\backend
g++ -std=c++17 -o server main.cpp -I"../include" -lws2_32 -lwsock32 && server.exe
```

**Open CMD Window 2 — Start ngrok (only if sharing with friends):**
```cmd
ngrok http 8080
```

**Then open the UI:**
- **For yourself** → open `Documents\gym-management-cpp\frontend\index.html` in browser
- **For friends** → send them the ngrok link shown in CMD Window 2

---

## 🔁 If You Accidentally Close the Server CMD Window

No problem! Just open CMD as Administrator again and run:
```cmd
cd %USERPROFILE%\Documents\gym-management-cpp\backend && server.exe
```
The server will start again ✅

> ⚠️ **Important:** All data you entered (customers, trainers, staff) will be gone when the
> server restarts because data is stored in memory, not saved to a file.
> You will need to register everything again.

---

## ❓ Common Problems and Fixes

| Problem | What To Do |
|---|---|
| `g++` not recognized | Close CMD completely, open a brand new CMD as Admin, try again |
| `server.exe` not found | Run the compile command in Step 8 first |
| App not loading in browser | Make sure `server.exe` is still running in CMD Window 1 |
| View shows no records | Register some data first, then click View |
| ngrok link not working | Make sure both CMD windows are open (server + ngrok) |
| Windows Firewall popup | Click "Allow Access" — completely safe |
| ngrok warning page in browser | Click "Visit Site" — completely normal |
| Friend cannot access the link | Check that your PC is on and both CMD windows are still running |
| Data disappeared after restart | Server was restarted — you need to register data again |
| Compile shows errors | Make sure Step 5 PATH commands were run successfully |

---

## 👤 Author

**Akaza41** — 2nd Semester OOP Project
GitHub: https://github.com/Akaza41/gym-management-cpp