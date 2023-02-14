#include "Dog.hpp"
#include <string>
#include <iostream>

Dog::Dog() {
	this->type = "Dog";
}

Dog::~Dog() {}

Dog& Dog::operator=(const Dog&rhs) {
	*this = rhs;
	return *this;
}

Dog::Dog(const Dog &rhs) : Animal() {
	*this = rhs;
}

void Dog::makeSound() const {
	std::cout << "BARK BARK!!!" << std::endl;
}