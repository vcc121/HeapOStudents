#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS

#include "date.h"
#include "address.h"
#include <string>

class Student {
	private:
		std::string studentString
		std::string firstName
		std::string lastName
		int credits;
		Address* address;
		Date* birthDate;
		Date* gradDate;
	public:
		Student();
		~Student();
		void init(std::string studentString);
		void printStudent();
		std::string getLastFirst();

};

#endif