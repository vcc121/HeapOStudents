#ifndef DATA_H_EXISTS
#define DATA_H_EXISTS

class Data {
	private:
		int day;
		int month;
		int year;
		std::string dateString;

	public:
		Date();
		void init(dateString);
		void printDate();

};

#endif
