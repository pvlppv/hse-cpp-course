// User class: The base class from which the
// all other classes are inherited. Includes
// basic information about the user (for example, name).

// Employee class: Derived from User, representing
// employee. Adds a level of access to resources specific
// for staff.

// Manager class: Derived from User, representing a manager.
// Managers have a higher level of access than regular ones
// employees, and can manage department resources.

// Administrator class: Derived class that should inherit
// properties and methods from both Employee and Manager. Administrators
// have the highest level of access allowing them to manage resources
// at all levels.

// Implement a class system using virtual inheritance,
// to solve the problem of diamond-shaped inheritance and correctly
// organize a hierarchy of classes User, Employee, Manager and
//Administrator. Every class must provide a method
// accessResources() demonstrating the user's access level.
#include <iostream>
#include <string>

class User {
public:
    virtual void accessResources() {
        std::cout << "Access granted: User level\n";
    }
};

class Employee : virtual public User {
public:
    void accessResources() override {
        std::cout << "Access granted: Employee level\n";
    }
};

class Manager : virtual public User {
public:
    void accessResources() override {
        std::cout << "Access granted: Manager level\n";
    }
};

class Administrator : public Employee, public Manager {
public:
    void accessResources() override {
        std::cout << "Access granted: Administrator level\n";
    }
};

int main() {
    User user;
    Employee employee;
    Manager manager;
    Administrator admin;

    user.accessResources();
    employee.accessResources();
    manager.accessResources();
    admin.accessResources();

    return 0;
}
