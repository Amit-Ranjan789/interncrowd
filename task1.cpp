#include <iostream>
#include <string>
#include <map>

using namespace std;

// Function to add a friend's birthday to the list
void addBirthday(map<string, string>& birthdays) {
    string name, date;
    cout << "Enter friend's name: ";
    cin >> name;
    cout << "Enter friend's birthday (mm/dd/yyyy): ";
    cin >> date;
    birthdays[name] = date;
}

// Function to edit a friend's birthday in the list
void editBirthday(map<string, string>& birthdays) {
    string name, date;
    cout << "Enter friend's name to edit: ";
    cin >> name;
    if (birthdays.find(name) != birthdays.end()) {
        cout << "Enter new birthday for " << name << " (mm/dd/yyyy): ";
        cin >> date;
        birthdays[name] = date;
        cout << "Birthday updated." << endl;
    } else {
        cout << "Friend not found in list." << endl;
    }
}

// Function to display the list of birthdays
void displayBirthdays(map<string, string>& birthdays) {
    if (birthdays.empty()) {
        cout << "Birthday list is empty." << endl;
    } else {
        cout << "List of birthdays:" << endl;
        for (auto& p : birthdays) {
            cout << p.first << ": " << p.second << endl;
        }
    }
}

// Function to search for a friend's birthday by name
void searchBirthday(map<string, string>& birthdays) {
    string name;
    cout << "Enter friend's name to search for: ";
    cin >> name;
    if (birthdays.find(name) != birthdays.end()) {
        cout << "Birthday for " << name << ": " << birthdays[name] << endl;
    } else {
        cout << "Friend not found in list." << endl;
    }
}

int main() {
    map<string, string> birthdays;
    int choice;
    do {
        cout << "Birthday List:" << endl;
        cout << "1. Add a friend's birthday" << endl;
        cout << "2. Edit a friend's birthday" << endl;
        cout << "3. Display all birthdays" << endl;
        cout << "4. Search for a friend's birthday" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addBirthday(birthdays);
                break;
            case 2:
                editBirthday(birthdays);
                break;
            case 3:
                displayBirthdays(birthdays);
                break;
            case 4:
                searchBirthday(birthdays);
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    } while (choice != 5);
    return 0;
}
