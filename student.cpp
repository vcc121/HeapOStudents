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

    std::cout << "Processing student string: " << studentString << std::endl;

    getline(ss, firstName, ',');
    std::cout << "First name: " << firstName << std::endl;
    getline(ss, lastName, ',');
    std::cout << "Last name: " << lastName << std::endl;

    getline(ss, street, ',');
    std::cout << "Street: " << street << std::endl;
    getline(ss, town, ',');
    std::cout << "Town: " << town << std::endl;
    getline(ss, state, ',');
    std::cout << "State: " << state << std::endl;
    getline(ss, zipCode, ',');
    std::cout << "ZipCode: " << zipCode << std::endl;

    getline(ss, tBirthDate, ',');
    std::cout << "Birth date: " << tBirthDate << std::endl;
    getline(ss, tGradDate, ',');
    std::cout << "Graduation date: " << tGradDate << std::endl;
    getline(ss, tCreditHours);
    std::cout << "Credit Hours: " << tCreditHours << std::endl;

    // Initialize address and dates
    address->init(street, town, state, zipCode);
    birthDate->init(tBirthDate);
    gradDate->init(tGradDate);

    // Set credits
    std::stringstream creditStream(tCreditHours);
    creditStream >> credits;
    std::cout << "Credits set: " << credits << std::endl;
}