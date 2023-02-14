#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap Default Constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) {
	this->name = name;
	this->hit_point = FragTrap::hit_point;
	this->energy_point = ScavTrap::energy_point;
	this->attack_damage = FragTrap::attack_damage;
	
	std::cout << "DiamondTrap " << this->name << " was created." << this->attack_damage << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " was destroyed." << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name is " << this->name << " with ClapTrap name " << ClapTrap::name << std::endl;
	
}

//Hit points (FragTrap)     = 100
// Energy points (ScavTrap) = 50
// Attack damage (FragTrap) = 30