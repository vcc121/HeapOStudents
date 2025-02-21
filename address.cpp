#include "address.h"
#include <iostream>

Address::Address(){
    street = "";
    town = "";
    state = "";
    zipCode = "";
}

void Address::init(std::string street, std::string town, std::string state, std::string zipCode){
    Address::street = street;
    Address::town = town;
    Address::state = state;
    Address::zipCode = zipCode;
}

void Address::printAddress(){
    std::cout << street << std::endl;
    std::cout << town << " " << state << ", ";
    std::cout << zipCode << std::endl;
}