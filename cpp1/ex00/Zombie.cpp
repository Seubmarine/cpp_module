#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( std::string name ) {
	this->_name = name;
}

Zombie::~Zombie() {
	std::cout << this->_name << ":  Destroyed" << std::endl;
}

void Zombie::announce() {
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}