#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

const int MAX = 20;

class Student {
    int rollno;
    char name[MAX];
    char city[MAX];
    char div;
    int year;

public:
    Student() {
        rollno = year = div = 0;
        strcpy(name, "");
        strcpy(city, "");
    }

    Student(int rollno, char name[MAX], int year, char div, char city[MAX]) {
        this->rollno = rollno;
        this->year = year;
        this->div = div;
        strcpy(this->name, name);
        strcpy(this->city, city);
    }

    int getRollNo() {
        return rollno;
    }

    void displayRecord() {
        cout << left << setw(6) << rollno << setw(20) << name << setw(6) << year << setw(6) << div << setw(20) << city << endl;
    }
};

class FileOperations {
    fstream file;

public:
    FileOperations(char* filename) {
        file.open(filename, ios::in | ios::out | ios::ate | ios::binary);
    }

    void insertRecord(int rollno, char name[MAX], int year, char div, char city[MAX]) {
        Student s1(rollno, name, year, div, city);
        file.seekp(0, ios::end);
        file.write((char*)&s1, sizeof(Student));
        file.clear();
    }

    void displayAll() {
        Student s1;
        file.seekg(0, ios::beg);
        cout << left << setw(6) << "ROLL" << setw(20) << "NAME" << setw(6) << "YEAR" << setw(6) << "DIV" << setw(20) << "CITY" << endl;
        while (file.read((char*)&s1, sizeof(Student))) {
            s1.displayRecord();
        }
        file.clear();
    }

    void displayRecord(int rollNo) {
        Student s1;
        file.seekg(0, ios::beg);
        bool flag = false;
        while (file.read((char*)&s1, sizeof(Student))) {
            if (s1.getRollNo() == rollNo) {
                s1.displayRecord();
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "\nRecord of " << rollNo << " is not present.";
        }
        file.clear();
    }

    void deleteRecord(int rollno) {
        ofstream outFile("new.dat", ios::binary);
        file.seekg(0, ios::beg);
        bool flag = false;
        Student s1;

        while (file.read((char*)&s1, sizeof(Student))) {
            if (s1.getRollNo() == rollno) {
                flag = true;
                continue;
            }
            outFile.write((char*)&s1, sizeof(Student));
        }
        if (!flag) {
            cout << "\nRecord of " << rollno << " is not present.";
        }
        file.close();
        outFile.close();
        remove("student.dat");
        rename("new.dat", "student.dat");
        file.open("student.dat", ios::in | ios::out | ios::ate | ios::binary);
    }

    ~FileOperations() {
        file.close();
        cout << "\nFile Closed.";
    }
};

int main() {
    ofstream newFile("student.dat", ios::app | ios::binary);
    newFile.close();
    FileOperations file((char*)"student.dat");
    int rollNo, year, choice = 0;
    char div;
    char name[MAX], address[MAX];

    while (choice != 5) {
        cout << "\n*****Student Database*****\n";
        cout << "1) Add New Record\n";
        cout << "2) Display All Records\n";
        cout << "3) Display by RollNo\n";
        cout << "4) Deleting a Record\n";
        cout << "5) Exit\n";
        cout << "Choose your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nEnter RollNo and Name: ";
            cin >> rollNo >> name;
            cout << "Enter Year and Division: ";
            cin >> year >> div;
            cout << "Enter Address: ";
            cin.ignore();
            cin.getline(address, MAX);
            file.insertRecord(rollNo, name, year, div, address);
            cout << "\nRecord Inserted.";
            break;
        case 2:
            // cout << left << setw(6) << "ROLL" << setw(20) << "NAME" << setw(6) << "YEAR" << setw(6) << "DIV" << setw(20) << "CITY" << endl;
            file.displayAll();
            break;
        case 3:
            cout << "Enter Roll Number: ";
            cin >> rollNo;
            file.displayRecord(rollNo);
            break;
        case 4:
            cout << "Enter RollNo: ";
            cin >> rollNo;
            file.deleteRecord(rollNo);
            break;
        case 5:
            break;
        }
    }

    return 0;
}
