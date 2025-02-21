#include "date.h"
#include <sstream>
#include <iostream>

Date::Date(){
	day = 0;
	month = 0;
	year = 0;
}

void Date::init(std::string dateString) {
    std::stringstream ss(dateString);

    std::string tDay, tMonth, tYear;


    getline(ss, tMonth, '/');
    getline(ss, tDay, '/');
    getline(ss, tYear);


    ss.clear();
    ss.str("");

    ss << tDay << " " << tMonth << " " << tYear;
    ss >> day >> month >> year;
}

void Date::printDate(){
	std::string months[] = {
        "Null", "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };
	std::cout << months[month] << " ";
	std::cout << day << ", " << year << std::endl;
}