#ifndef ADDRESS_H_EXISTS
#define ADDRESS_H_EXISTS

class Address {
	private:
		std::string street;
		std::string town;
		std::string state;
		std::string zipCode;
	public:
		Address();
		void init(std::string street, std::string town, std::string state, std::string zipCode);
		void printAddress();
};

#endif
