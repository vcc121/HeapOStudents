#include "date.h"
#include <sstream>

Date::Date(){
	day = 0;
	month = 0;
	year = 0;
	dateString = "";
}

void Date::init(std::dateString){

	std::string tDay;
	std::string tMonth;
	std::string tYear;

	getline(ss, tDay, '/');
	getline(ss, tMonth, '/');
	getline(ss, tYear);

	ss.clear();
	ss.str("");
	
	ss << tDay << " " << tMonth << " " << tYear;
    ss >> day >> month >> year;
}