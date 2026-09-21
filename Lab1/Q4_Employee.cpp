/*
Explain the concept of inheritance in C++ using a real-world example of an Employee
Management System. Create a base class Employee and two derived classes Manager and
Developer. Implement functions display_Manager() and display_Developer() to display the
respective details.
*/


#include <iostream>
using namespace std;

class Employee{
public:
    string name;
    int id;
};

class Manager : public Employee{
public:
    void display_Manager()
    {
        cout << "Manager Name: " << name << endl;
        cout << "Manager ID: " << id << endl;
    }
};

class Developer : public Employee{
public:
    void display_Developer()
    {
        cout << "Developer Name: " << name << endl;
        cout << "Developer ID: " << id << endl;
    }
};

int main(){
    Manager manager;

    manager.name = "Diksha";
    manager.id = 101;

    manager.display_Manager();

    Developer developer;

    developer.name = "Rahul";
    developer.id = 102;

    developer.display_Developer();

    return 0;
}