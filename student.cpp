#include "date.h"
#include "address.h"

#include <iostream>
#include <sstream>

Student::Student(){
	studentString "";
	firstName = "";
	lastName = "";
	birthDate = new Date();
	gradDate = new Date();
	address = new Address();
	credits = 0;
}

Student::Student(std::string studentString){
	Student::init(studentString;
}

Student::~Student(){
	delete birthDate;
	delete gradDate;
	delete address;
}
