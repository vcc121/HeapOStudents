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

    // Extracting values from the dateString
    getline(ss, tMonth, '/');
    getline(ss, tDay, '/');
    getline(ss, tYear);

    // Printing extracted strings before conversion
    std::cout << "Extracted: " << tDay << " " << tMonth << " " << tYear << std::endl;

    // Converting to integers
    ss.clear();
    ss.str("");  // Clearing any remaining content

    ss << tDay << " " << tMonth << " " << tYear;
    ss >> day >> month >> year;

    // Printing parsed integer values
    std::cout << "Parsed: " << day << " " << month << " " << year << std::endl;
}

void Date::printDate(){
	std::string months[] = {
        "Null", "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };
	std::cout << months[month] << " ";
	std::cout << day << ", " << year << std::endl;
}