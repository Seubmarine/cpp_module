#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
}

WrongAnimal::~WrongAnimal()
{
}

WrongAnimal::WrongAnimal(const WrongAnimal &from) {
	this->type = from.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &rhs) {
	this->type = rhs.type;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal default song" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}
