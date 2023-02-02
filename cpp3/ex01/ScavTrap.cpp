#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() {
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 30;
	std::cout << "ScavTrap Default Constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 30;
	this->name = name;
	std::cout << "ScavTrap Constructor name: " << this->name << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " was destroyed." << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (this->energy_point == 0) {
		std::cout << "ScavTrap " << this->name << " doesn't have any energy left in it." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage! I will Guard this Gate forever !" << std::endl;
	this->energy_point--;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " is now in Gate Keeper Mode." << std::endl;
}
