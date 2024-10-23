#include <iostream>
#include <cstring>

using namespace std;

class Student{
    char *name;
    int rollNumber;
    string className;
    char division;
    string dob;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNo;

    static int studentCount;

    public:
        Student(){
        name = new char[30];
        strcpy(name, "Unknown");
        rollNumber = 0;
        className = "Unknown";
        division = 'U';
        dob = "Unknown";
        bloodGroup = "Unknown";
        contactAddress = "Unknown";
        telephoneNumber = "Unknown";
        drivingLicenseNo = "Unknown";
        studentCount++;
        }

        Student(const char *name, int rollNumber, string className, char division, string dob, string bloodGroup, string contactAddress, string telephoneNumber, string drivingLicenseNo) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->rollNumber = rollNumber;
        this->className = className;
        this->division = division;
        this->dob = dob;
        this->bloodGroup = bloodGroup;
        this->contactAddress = contactAddress;
        this->telephoneNumber = telephoneNumber;
        this->drivingLicenseNo = drivingLicenseNo;
        studentCount++;
        }

        Student(const Student &other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        rollNumber = other.rollNumber;
        className = other.className;
        division = other.division;
        dob = other.dob;
        bloodGroup = other.bloodGroup;
        contactAddress = other.contactAddress;
        telephoneNumber = other.telephoneNumber;
        drivingLicenseNo = other.drivingLicenseNo;
        studentCount++;
        }

        ~Student() {
        delete[] name;
        studentCount--;
        }

        inline void displayInfo() const {
        cout << "\nStudent Information:\n";
        cout << "Name: " << name << "\n";
        cout << "Roll Number: " << rollNumber << "\n";
        cout << "Class: " << className << "\n";
        cout << "Division: " << division << "\n";
        cout << "Date of Birth: " << dob << "\n";
        cout << "Blood Group: " << bloodGroup << "\n";
        cout << "Contact Address: " << contactAddress << "\n";
        cout << "Telephone Number: " << telephoneNumber << "\n";
        cout << "Driving License No.: " << drivingLicenseNo << "\n";
        }

};