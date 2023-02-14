#include "Cat.hpp"
#include <string>
#include <iostream>

Cat::Cat() {
	this->type = "Cat";
}

Cat::~Cat() {}

Cat& Cat::operator=(const Cat&rhs) {
	*this = rhs;
	return *this;
}

Cat::Cat(const Cat &rhs) : Animal() {
	*this = rhs;
}

void Cat::makeSound() const {
	std::cout << "MEAOOOWW!!!" << std::endl;
}