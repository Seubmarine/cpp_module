#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() {
	this->hit_point = 100;
	this->energy_point = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap Default Constructor" << std::endl;
}

FragTrap::FragTrap(std::string name) {
	this->hit_point = 100;
	this->energy_point = 100;
	this->attack_damage = 30;
	this->name = name;
	std::cout << "FragTrap Constructor name: " << this->name << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " was destroyed." << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragtrap) {
	*this = fragtrap;
	std::cout << "FragTrap Copy Constructor: " << this->name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap) {
	// *this = FragTrap;
	this->hit_point = fragtrap.hit_point;
	this->attack_damage = fragtrap.attack_damage;
	this->energy_point = fragtrap.energy_point;
	this->name = fragtrap.name;
	std::cout << "FragTrap Copy Assign: " << this->name << std::endl;
	return *this;
}

void FragTrap::attack(const std::string &target) {
	if (this->energy_point == 0) {
		std::cout << "FragTrap " << this->name << " doesn't have any energy left in it." << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage! I will Guard this Gate forever !" << std::endl;
	this->energy_point--;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->name << " is doing an high five." << std::endl;
}
