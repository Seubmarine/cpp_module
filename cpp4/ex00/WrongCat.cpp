#include "WrongCat.hpp"
#include <string>
#include <iostream>

WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << this->type << " constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << this->type << " destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat&rhs) {
	*this = rhs;
	return *this;
}

WrongCat::WrongCat(const WrongCat &rhs) : WrongAnimal() {
	*this = rhs;
}

void WrongCat::makeSound() const {
	std::cout << "WRONG MEAOOOWW!!!" << std::endl;
}