#include "Dog.hpp"
#include <string>
#include <iostream>
#include "Brain.hpp"

Dog::Dog() {
	this->type = "Dog";
	this->brain = new Brain;
}

Dog::~Dog() {
	delete this->brain;
}

Dog& Dog::operator=(const Dog &rhs) {
	if (this != &rhs) {
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
		this->type = rhs.type;
	}
	return *this;
}

Dog::Dog(const Dog &rhs) : Animal() {
	this->brain = new Brain(*rhs.brain);
	this->type = rhs.type;
}

void Dog::makeSound() const {
	std::cout << "BARK BARK!!!" << std::endl;
}