#include "Cat.hpp"
#include <string>
#include <iostream>
#include "Brain.hpp"

Cat::Cat() {
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat() {
	delete this->brain;
}

Cat& Cat::operator=(const Cat&rhs) {
	if (this != &rhs) {
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
		this->type = rhs.type;
	}
	return *this;
}

Cat::Cat(const Cat &rhs) : Animal() {
	this->brain = new Brain(*rhs.brain);
	this->type = rhs.type;
}

void Cat::makeSound() const {
	std::cout << "MEAOOOWW!!!" << std::endl;
}