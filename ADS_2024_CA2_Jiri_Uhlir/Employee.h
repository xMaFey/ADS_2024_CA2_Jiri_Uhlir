#pragma once
#include <string>

using namespace std;

class Employee {
    string id;
    string name;
    int age;
    string department;
    string joiningDate;

public:
    Employee() {};
    Employee(string id, string name, int age, string department, string joiningDate);

    string getId() { return id; }
    string getName() { return name; }
    int getAge() { return age; }
    string getDepartment() { return department; }
    string getJoiningDate() { return joiningDate; }

};

Employee::Employee(string id, string name, int age, string department, string joiningDate) {
    this->id = id;
    this->name = name;
    this->age = age;
    this->department = department;
    this->joiningDate = joiningDate;
}