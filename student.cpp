#include "date.h"
#include "address.h"
#include "student.h"

#include <iostream>
#include <sstream>

Student::Student(){
	studentString = "";
	firstName = "";
	lastName = "";
	birthDate = new Date();
	gradDate = new Date();
	address = new Address();
	credits = 0;
}

Student::Student(std::string studentString){
	Student::init(studentString);
}

Student::~Student(){
	delete birthDate;
	delete gradDate;
	delete address;
}

void Student::printStudent() {
    std::cout << firstName << " " << lastName << std::endl;
    address->printAddress();
    
    std::cout << "DOB: ";
    birthDate->printDate();
    
    std::cout << "Grad: ";
    gradDate->printDate();
    
    std::cout << "Credits: " << credits << std::endl;
    std::cout << "____________________";
	std::cout << std::endl;
}

std::string Student::getLastFirst() {
    std::stringstream ss;
    ss.clear();
    ss << lastName << ", " << firstName;
    return ss.str();
}


void Student::init(std::string studentString) {
    std::stringstream ss(studentString);

    std::string street, town, state, zipCode;
    std::string tBirthDate, tGradDate, tCreditHours;

    getline(ss, firstName, ',');
    getline(ss, lastName, ',');
    getline(ss, street, ',');
    getline(ss, town, ',');
    getline(ss, state, ',');
    getline(ss, zipCode, ',');
    getline(ss, tBirthDate, ',');
    getline(ss, tGradDate, ',');
    getline(ss, tCreditHours);

    address->init(street, town, state, zipCode);
    birthDate->init(tBirthDate);
    gradDate->init(tGradDate);

    ss.clear();
    ss.str(tCreditHours);
    ss >> credits;
}
