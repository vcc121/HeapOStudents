#include <iostream>
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
    std::string line;
    while (std::getline(file, line)) {
        Student* student = new Student(line);
        students.push_back(student);
    }
    
    file.close();
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
 bool compFirst(Student* a, Student* b){
    return a->getFirstName() < b->getFirstName();
 }