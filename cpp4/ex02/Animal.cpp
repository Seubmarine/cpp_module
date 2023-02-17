#include "Animal.hpp"
#include <string>
#include <iostream>

Animal::Animal() {}

Animal::~Animal() {
	std::cout << "Destroy an Animal" << std::endl;
}

Animal& Animal::operator=(const Animal&rhs) {
	*this = rhs;
	return *this;
}

Animal::Animal(const Animal &rhs) {
	*this = rhs;
}

std::string Animal::getType() const
{
	return (this->type);
}