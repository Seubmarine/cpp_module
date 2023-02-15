#include "WrongCat.hpp"
#include <string>
#include <iostream>

WrongCat::WrongCat() {
	this->type = "WrongCat";
}

WrongCat::~WrongCat() {}

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