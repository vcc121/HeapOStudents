#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "date.h"
#include "address.h"
#include "student.h"

void loadStudents(std::vector<Student*>& students);
void printStudents(std::vector<Student*>& students);
void showStudentNames(std::vector<Student*>& students);
void findStudent(std::vector<Student*>& students);
void delStudents(std::vector<Student*>& students);
std::string menu();

void loadStudents(std::vector<Student*>& students) {
    std::ifstream file("students.csv");
    if (!file) {
        std::cerr << "Error: Could not open students.csv\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << "Reading line: " << line << std::endl; // Debugging output

        if (line.empty()) continue; // Avoid creating empty students

        Student* student = new Student(line);
        if (!student) {
            std::cerr << "Error: Failed to allocate memory for Student\n";
            continue;
        }

        students.push_back(student);
    }

    file.close();
}

void showStudentNames(std::vector<Student*>& students) {
    for (Student* s : students) {
        std::cout << s->getLastFirst() << std::endl;;
    }
}

// Function to print full student records
void printStudents(std::vector<Student*>& students) {
    for (Student* s : students) {
        s->printStudent();  // Assuming printStudent() outputs full details
        std::cout << "____________________________________\n";
    }
}

void delStudents(std::vector<Student*>& students) {
    for (Student* s : students) {
        delete s;
    }
    students.clear();
}

void findStudent(std::vector<Student*>& students) {
    std::string target;
    bool notFound = true;
    std::cout << "last name of student: ";
    getline(std::cin, target);

    for (Student* s : students) {
        std::string lName = s->getLastFirst();
        if (lName.find(target) != std::string::npos) {
            s->printStudent();
            notFound = false;
        }
    }

    if (notFound) {
        std::cout << "No students found with that last name.\n";
    }
}

std::string menu() {
    std::cout << "\n0) quit\n"
              << "1) print all student names\n"
              << "2) print all student data\n"
              << "3) find a student\n"
              << "please choose 0-3: ";
    std::string choice;
    getline(std::cin, choice);
    return choice;
}

int main() {
    std::vector<Student*> students;
    loadStudents(students);

    bool keepGoing = true;
    while (keepGoing) {
        std::string choice = menu();

        if (choice == "0") {
            keepGoing = false;
        } else if (choice == "1") {
            showStudentNames(students);
        } else if (choice == "2") {
            printStudents(students);
        } else if (choice == "3") {
            findStudent(students);
        } else {
            std::cout << "Please enter a valid number\n";
        }
    }

    delStudents(students);
    return 0;
}