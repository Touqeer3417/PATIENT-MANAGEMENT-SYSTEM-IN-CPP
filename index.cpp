#include <iostream>
#include <string>
#include <fstream> 
using namespace std;

//variables for add patient
string names[100];
int ages[100];
string genders[100];
string contactNumbers[100];
string diseases[100];
int patientccount = 0;

//variables for register/login
string usernames[100];
string passwords[100];
int userCount = 0;

//variables for appointment
int appointmentCount = 0;
string appPatientNames[100];
string appEmails[100];
string SelectDepartments[100];

//file handling
// writng in file
void savePatients()
{
    ofstream file("patients.txt");
    for (int i = 0; i < patientccount; i++)
    {
        file << names[i] << " " << ages[i] << " " << genders[i] << " "
             << contactNumbers[i] << " " << diseases[i] << "\n";
    }
    file.close();
}
void saveUsers()
{
    ofstream file("users.txt");
    for (int i = 0; i < userCount; i++)
    {
        file << usernames[i] << " " << passwords[i] << "\n";
    }
    file.close();
}

void saveAppointments()
{
    ofstream file("appointments.txt");
    for (int i = 0; i < appointmentCount; i++)
    {
        file << appPatientNames[i] << " " << appEmails[i] << " " << SelectDepartments[i] << "\n";
    }
    file.close();
}


// reading from file 
void loadPatients()
{
    ifstream file("patients.txt");
    patientccount = 0;

    string name, gender, contact, disease;
    int age;

    while (file >> name >> age >> gender >> contact >> disease)
    {
        names[patientccount] = name;
        ages[patientccount] = age;
        genders[patientccount] = gender;
        contactNumbers[patientccount] = contact;
        diseases[patientccount] = disease;

        patientccount++;
    }

    file.close();
}
void loadUsers()
{
    ifstream file("users.txt");
    userCount = 0;

    string username, password;
    while (file >> username >> password)
    {
        usernames[userCount] = username;
        passwords[userCount] = password;
        userCount++;
    }

    file.close();
}
void loadAppointments()
{
    ifstream file("appointments.txt");
    appointmentCount = 0;

    string name, email, department;
    while (file >> name >> email >> department)
    {
        appPatientNames[appointmentCount] = name;
        appEmails[appointmentCount] = email;
        SelectDepartments[appointmentCount] = department;
        appointmentCount++;
    }

    file.close();
}



// basic crud opeartion 
void addPatient()
{
    if (patientccount >= 100)
    {
        cout << "Patient  is full!" << endl;
        return;
    }

    cout << "Enter patient name: ";
    cin >> names[patientccount];

    cout << "Enter age: ";
    cin >> ages[patientccount];

    cout << "Enter gender: ";
    cin >> genders[patientccount];

    cout << "Enter contact number: ";
    cin >> contactNumbers[patientccount];

    cout << "Enter disease: ";
    cin >> diseases[patientccount];
    patientccount++;
    cout << "add patient .\n";

    savePatients();
}

void displayPatients()
{
    if (patientccount == 0)
    {
        cout << "No patients to display.\n";
        return;
    }

    for (int i = 0; i < patientccount; i++)
    {
        cout << "ID: " << i+1
             << ", Name: " << names[i]
             << ", Age: " << ages[i]
             << ", Gender: " << genders[i]
             << ", Contact: " << contactNumbers[i]
             << ", Disease: " << diseases[i] << endl;
    }
}

void searchPatient()
{

    string name1;
    cout << "Enter name to search: ";
    cin >> name1;

    bool found = false;
    for (int i = 0; i < patientccount; ++i)
    {
        if (names[i] == name1)
        {
            cout << ", Name: " << names[i]
                 << ", Age: " << ages[i]
                 << ", Gender: " << genders[i]
                 << ", Contact: " << contactNumbers[i]
                 << ", Disease: " << diseases[i] << endl;
            found = true;
        }

        if (!found)
            cout << "No patiennt found " << endl;
    }
}

void deletePatient()
{
    string namedeletepatient;
    cout << "Enter the name of the patient to delete: ";
    cin >> namedeletepatient;

    bool found = true;
    for (int i = 0; i < patientccount; i++)
    {
        if (names[i] == namedeletepatient)
        {
            names[i] = names[i + 1];
            ages[i] = ages[i + 1];
            genders[i] = genders[i + 1];
            contactNumbers[i] = contactNumbers[i + 1];
            diseases[i] = diseases[i + 1];

            patientccount--;
            found = false;
            cout << "Patient recordd .\n";
            break;
        }
    }

    if (found)
    {
        cout  << namedeletepatient << " not found.\n";
    }
}

//accounts making
void registerUser()

{
    string uname, pass;
    cout << "Enter new username: ";
    cin >> uname;
    cout << "Enter password: ";
    cin >> pass;
    for (int i = 0; i < userCount; i++)
    {
        if (usernames[i] == uname)
        {
            cout << "Username  exists!\n";
            return;
        }
    }
    usernames[userCount] = uname;
    passwords[userCount] = pass;
    userCount++;
    saveUsers();
}

bool loginuuser()
{
    string uname, pass;
    cout << "Enter username: ";
    cin >> uname;
    cout << "Enter password: ";
    cin >> pass;
    for (int i = 0; i < userCount; i++)
    {
        if (usernames[i] == uname && passwords[i] == pass)
        {
            cout << "Login successful!\n";
            return true;
        }
    }
    cout << "Invalidd !\n";
    return false;
}

string departments[] = {"Cardiology", "Neurology", "Orthopedics", "Pediatrics", "ENT"};
void showDepartments()
{
    cout << "available Departments are:\n";
 
    for (int i = 0; i < 5; i++)
    {
        cout<<departments[i]<<endl;
    }
    
}

//appointment

void bookAppointment()
{
    if (appointmentCount >= 100)
    {
        cout << "Appointment limit reached!\n";
        return;
    }

    cout << "Enter your name: ";
    cin >> appPatientNames[appointmentCount];

    cout << "Enter your email: ";
    cin >> appEmails[appointmentCount];
//HELLO WORLD

    // C:\Users\falcon\Documents\GitHub\PATIENT-MANAGEMENT-SYSTEM-IN-CPP\index.cpp
    showDepartments();
    cout << "Choose department 1-5: ";
    int deptChoice;
    cin >> deptChoice;

    SelectDepartments[appointmentCount] = departments[deptChoice - 1];
    appointmentCount++;
    cout << "Appointment bookedd ssuccessfully.\n";
    saveAppointments();
}

void viewAppointments()
{
    if (appointmentCount == 0)
    {
        cout << "No appointments scheduled.\n";
        return;
    }

    for (int i = 0; i < appointmentCount; i++)
    {
        cout << "\nAppointment " << i + 1 << "\n";
        cout << "Name: " << appPatientNames[i] << "\n";
        cout << "Email: " << appEmails[i] << "\n";
        cout << "Department: " << SelectDepartments[i] << "\n";
    }
}

int main()
{
    loadAppointments();
    loadPatients();
    loadUsers();

    int choice;

    cout << "Welcome to Patient Management System\n";
    while (true)
    {
        cout << "\n1. Register\n2. Login\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
            registerUser();
        else if (choice == 2)
        {
            if (loginuuser())
            {
                int option;
                while (true)
                {
                    cout << "\nMenu \n";
                    cout << "1. Add Patient\n2. Display Patients\n3. Search Patient\n";
                    cout << "4. Delete Patient\n5. Show Departments\n";
                    cout << "6. Book appointment \n7. ViewAppointMent\n";
                    cout << "8 Logout\nEnter choice: ";
                    cin >> option;

                    switch (option)
                    {
                    case 1:
                        addPatient();
                        break;
                    case 2:
                        displayPatients();
                        break;
                    case 3:
                        searchPatient();
                        break;
                    case 4:
                        deletePatient();
                        break;
                    case 5:
                        showDepartments();
                        break;
                    case 6:
                        bookAppointment();
                        break;
                    case 7:
                        viewAppointments();
                        break;
                    case 8:
                        cout << "Logged out successfully.\n";
                        return 0;
                    default:
                        cout << "enter option from onee to seveen \n";
                    }
                }
            }
        }
        else if (choice == 3)
        {
            cout << "Program End !\n";
            break;
        }
        else
            cout << "please enter the  correct choice\n";
    }
    return 0;
}


