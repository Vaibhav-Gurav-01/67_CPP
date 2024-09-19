//Q.No. 1 Banking Record System.
//File handling has been effectively used for each feature of this project
//Operations
//? Add Record:
//? Show/List Data:
//? Search Record:
//? Edit Record:
//? Delete Record:


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const string FILE_NAME = "BankRecords.txt";

struct Record {
    string account_number;
    string name;
    float balance;
};

void addRecord() {
    Record record;
    cout << "Enter account holder's name: ";
    cin >> record.name;
    cout << "Enter account number: ";
    cin >> record.account_number;
    cout << "Enter account balance: ";
    cin >> record.balance;

    ofstream file(FILE_NAME, ios::app);
    if (file.is_open()) {
        file << record.account_number << "," << record.name << "," << record.balance << endl;
        cout << "Record added successfully!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}

void showRecords() {
    ifstream file(FILE_NAME);
    if (!file) {
        cout << "No records found." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;  // Directly print the line
    }
}

void searchRecord() {
    string account_number;
    cout << "Enter account number to search: ";
    cin >> account_number;

    ifstream file(FILE_NAME);
    string line;
    while (getline(file, line)) {
        if (line.substr(0, line.find(',')) == account_number) {
            cout << "Record found: " << line << endl;
            return;
        }
    }
    cout << "Record not found." << endl;
}

void deleteRecord() {
    string account_number;
    cout << "Enter account number to delete: ";
    cin >> account_number;

    ifstream file(FILE_NAME);
    ofstream tempFile("temp.txt");
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.substr(0, line.find(',')) != account_number) {
            tempFile << line << endl;
        } else {
            found = true;
        }
    }

    file.close();
    tempFile.close();
    remove(FILE_NAME.c_str());
    rename("temp.txt", FILE_NAME.c_str());

    if (found) {
        cout << "Record deleted successfully!" << endl;
    } else {
        cout << "Record not found." << endl;
    }
}

int main() {
    while (true) {
        cout << "\nBanking Record System\n";
        cout << "1. Add Record\n";
        cout << "2. Show/List Data\n";
        cout << "3. Search Record\n";
        cout << "4. Delete Record\n";
        cout << "5. Exit\n";
        
        int choice;
        cout << "Choose an operation: ";
        cin >> choice;

        switch (choice) {
            case 1: addRecord(); break;
            case 2: showRecords(); break;
            case 3: searchRecord(); break;
            case 4: deleteRecord(); break;
            case 5: return 0;
            default: cout << "Invalid choice. Please try again." << endl; break;
        }
    }
}

