#ifndef DATE_H_EXISTS
#define DATE_H_EXISTS

#include <string>

class Date {
	private:
		int day;
		int month;
		int year;
		std::string dateString;

	public:
		Date();
		void init(std::string dateString);
		void printDate();

};

#endif
