#include "Animal.hpp"
#include <string>
#include <iostream>

Animal::Animal() {}

Animal::~Animal() {}

Animal& Animal::operator=(const Animal&rhs) {
	*this = rhs;
	return *this;
}

Animal::Animal(const Animal &rhs) {
	*this = rhs;
}

void Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}