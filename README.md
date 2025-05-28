
# Patient Management System (C++)

This is a simple file-based console application built in C++ to manage patients, user authentication, and appointment bookings. It uses arrays and basic file handling (`ifstream`, `ofstream`) to save and load data.

---

## 🚀 Features

- **User Registration & Login**
- **Patient Management (CRUD Operations)**
- **Department Listing**
- **Appointment Booking & Viewing**
- **File Persistence for Data**

---

## 📁 Files Used

- `users.txt` — Stores registered usernames and passwords.
- `patients.txt` — Stores patient details.
- `appointments.txt` — Stores appointment records.

---

## 🧾 Functional Overview

### 🔐 Authentication

- `registerUser()` — Registers a new user.
- `loginuuser()` — Authenticates existing users.

### 🏥 Patient Management

- `addPatient()` — Adds a new patient.
- `displayPatients()` — Displays all saved patients.
- `searchPatient()` — Finds a patient by name.
- `deletePatient()` — Deletes a patient record.

### 📄 File Handling

- **Save Functions**
  - `saveUsers()`
  - `savePatients()`
  - `saveAppointments()`
- **Load Functions**
  - `loadUsers()`
  - `loadPatients()`
  - `loadAppointments()`

### 🏬 Departments

- `showDepartments()` — Displays available departments:
  - Cardiology
  - Neurology
  - Orthopedics
  - Pediatrics
  - ENT

### 📅 Appointment System

- `bookAppointment()` — Book appointment for a department.
- `viewAppointments()` — View all booked appointments.

---

## 🧑‍💻 Usage Instructions

1. **Start the Program**  
   Compile and run `main()`.  
   You'll be welcomed with a menu to `Register`, `Login`, or `Exit`.

2. **Once Logged In**  
   You'll be provided with the following options:
   ```
   1. Add Patient
   2. Display Patients
   3. Search Patient
   4. Delete Patient
   5. Show Departments
   6. Book Appointment
   7. View Appointment
   8. Logout
   ```

3. **File Persistence**  
   Data is saved after each modification and loaded when the program starts.

---

## 💡 Notes

- Data is stored in plain text files using space-separated values.
- Max limit of records: `100` for patients, users, and appointments.
- Basic error checks for duplicates and bounds are included.

---

## ⚙️ Requirements

- C++ compiler (like `g++`)
- Compatible with Windows, Linux, or macOS (console only)

---

## 📌 Limitations

- No GUI — purely CLI-based.
- Uses fixed-size arrays instead of dynamic data structures.
- No encryption for passwords (for educational/demo use only).

---

## 👨‍🏫 Author

> Created for educational purposes — includes basic C++ concepts like arrays, functions, file I/O, conditionals, and loops.

---

## 🧠 Future Improvements

Here are some ideas to enhance this project further:

### 🔒 Security
- Add password hashing instead of storing plain text passwords.
- Implement session timeout or multi-user tracking.

### 🗃️ Data Structures
- Replace arrays with STL containers like `vector` or `map`.
- Implement classes and objects for better structure (OOP).

### 💾 Database Support
- Use SQLite or MySQL for storing data instead of text files.

### 🖥️ GUI Support
- Add a GUI using libraries like Qt or create a web-based front-end.

### 📊 Analytics
- Track number of appointments per department.
- Generate reports for patients and appointments.

### 🌐 Multi-language Support
- Add language localization support (e.g., Urdu, English).

---

## 📝 Sample Output

```
Welcome to Patient Management System

1. Register
2. Login
3. Exit
Enter choice: 2

Enter username: user1
Enter password: pass123
Login successful!

Menu 
1. Add Patient
2. Display Patients
3. Search Patient
4. Delete Patient
5. Show Departments
6. Book appointment 
7. ViewAppointMent
8 Logout
Enter choice: 1
Enter patient name: Ali
Enter age: 25
Enter gender: Male
Enter contact number: 03001234567
Enter disease: Fever
Patient added.
```

---

## 🧪 Testing Tips

- Try edge cases like deleting a non-existing patient.
- Attempt duplicate registration to test validation.
- Book multiple appointments and check file persistence.

---

## 📬 Contact

For suggestions or contributions, feel free to reach out!

---

© 2025 Patient Management System — C++ Console Project
