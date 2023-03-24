#include <iostream>
#include <string>
#include <map>

using namespace std;

// Student structure
struct Student {
    string name;
    string password;
};

// Map to store registered students
map<string, Student> registered_students;

// Student login function
bool login(string name, string password) {
    // Check if student is registered
    if (registered_students.find(name) != registered_students.end()) {
        // Check if password matches
        if (registered_students[name].password == password) {
            cout << "Login successful. Welcome " << name << "!" << endl;
            return true;
        } else {
            cout << "Incorrect password." << endl;
        }
    } else {
        cout << "Student not registered." << endl;
    }
    return false;
}

// Student registration function
void register_student(string name, string password) {
    // Check if student is already registered
    if (registered_students.find(name) != registered_students.end()) {
        cout << "Student already registered." << endl;
    } else {
        // Add student to map
        Student student = {name, password};
        registered_students[name] = student;
        cout << "Registration successful. Welcome " << name << "!" << endl;
    }
}

int main() {
    string name, password;
    int choice;

    do {
        cout << "Enter 1 to register, 2 to login, or 3 to quit: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter password: ";
                cin >> password;
                register_student(name, password);
                break;
            case 2:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter password: ";
                cin >> password;
                login(name, password);
                break;
            case 3:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 3);

    return 0;
}