/*
You are tasked with creating a program to manage a database 
of students' information. Each student record consists of the 
following fields: name, age, and grade. You need to implement 
a structure to represent a student record, including various 
overloaded operators for comparison and input/output operations.

In the main program, you should provide functionality to read 
student records from a file, add new records, delete existing 
records, modify records, and display all records. Additionally, 
you should implement the ability to save the updated database 
to a file.

Furthermore, you are required to store the collection of student 
records in a container such as a vector or any other appropriate 
container provided by the Standard Template Library (STL).

Your program should support the following operations:

Reading student records from a file and storing them in the database.
Adding a new student record to the database.
Deleting an existing student record from the database.
Modifying the information of an existing student record.
Displaying all student records.
Saving the updated database to a file.
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int age;
    double grade;

    friend std::istream& operator>>(std::istream& is, Student& student) {
        return is >> student.name >> student.age >> student.grade;
    }

    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        return os << "Name: " << student.name << ", Age: " << student.age << ", Grade: " << student.grade;
    }
};

bool operator==(const Student& lhs, const Student& rhs) {
    return lhs.name == rhs.name && lhs.age == rhs.age && lhs.grade == rhs.grade;
}

bool operator!=(const Student& lhs, const Student& rhs) {
    return !(lhs == rhs);
}

bool operator<(const Student& lhs, const Student& rhs) {
    return lhs.name < rhs.name || (lhs.name == rhs.name && (lhs.age < rhs.age || (lhs.age == rhs.age && lhs.grade < rhs.grade)));
}

std::vector<Student> readRecordsFromFile(const std::string& fileName) {
    std::vector<Student> students;
    std::ifstream file(fileName);

    Student student;
    while (file >> student) {
        students.push_back(student);
    }

    return students;
}

void addRecord(std::vector<Student>& students, const Student& student) {
    students.push_back(student);
}

void deleteRecord(std::vector<Student>& students, size_t index) {
    students.erase(students.begin() + index);
}

void displayRecords(const std::vector<Student>& students) {
    for (const auto& student : students) {
        std::cout << student << "\n";
    }
}

void writeRecordsToFile(const std::string& fileName, const std::vector<Student>& students) {
    std::ofstream file(fileName);

    for (const auto& student : students) {
        file << student << "\n";
    }
}

int main() {
    std::vector<Student> students = readRecordsFromFile("students.txt");

    Student newStudent;
    std::cin >> newStudent;
    addRecord(students, newStudent);

    size_t index;
    std::cin >> index;
    deleteRecord(students, index);

    displayRecords(students);

    writeRecordsToFile("students_v2.txt", students);

    return 0;
}


