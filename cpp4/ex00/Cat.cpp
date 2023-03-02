#include "Cat.hpp"
#include <string>
#include <iostream>

Cat::Cat() {
	this->type = "Cat";
	std::cout << this->type << " constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << this->type << " destructor called" << std::endl;
}

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