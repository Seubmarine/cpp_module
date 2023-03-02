#include "Animal.hpp"
#include <string>
#include <iostream>

Animal::Animal() : type("Animal") {
	std::cout << this->type << " base class constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << this->type << " base class destructor called" << std::endl;
}

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