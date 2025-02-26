#include <iostream>
#include <algorithm>
#include <vector>
#include "date.h"
#include "address.h"
#include "student.h"

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


}
