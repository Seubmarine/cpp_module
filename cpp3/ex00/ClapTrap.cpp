#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() :
		name(""), hit_point(10), energy_point(10), attack_damage(0) {
	std::cout << "ClapTrap Default Constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
		name(name), hit_point(10), energy_point(10), attack_damage(0) {
	std::cout << "ClapTrap Constructor name: " << this->name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap) {
	*this = claptrap;
	std::cout << "ClapTrap Copy Constructor: " << this->name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap) {
	this->hit_point = claptrap.hit_point;
	this->attack_damage = claptrap.attack_damage;
	this->energy_point = claptrap.energy_point;
	this->name = claptrap.name;
	std::cout << "ClapTrap Copy Assign: " << this->name << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " was destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (this->energy_point == 0) {
		std::cout << "ClapTrap " << this->name << " doesn't have any energy left in it." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
	this->energy_point--;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hit_point == 0 || this->energy_point == 0) {
		std::cout << "ClapTrap " << this->name << " doesn't have any " << (this->hit_point == 0 ? "health" : "energy")
				  << " left in it." << std::endl;
		return;
	}
	this->hit_point += amount;
	std::cout << "ClapTrap " << this->name << " repaired by " << amount << ", and is now at " << this->hit_point << " health" << std::endl;
	this->energy_point--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hit_point == 0) {
		std::cout << "ClapTrap " << this->name << " doesn't hany any health to be damaged." << std::endl;
		return;
	}
	if (this->hit_point - amount > this->hit_point)
		this->hit_point = 0;
	else
		this->hit_point -= amount;
	std::cout << "ClapTrap " << this->name << " has taken " << amount << " damage , health is at " << this->hit_point << std::endl;
}

void ClapTrap::debugStatus() {
	std::cout << "ClapTrap " << this->name << " has hit_point(health): " << this->hit_point << ", energy: " << this->energy_point << " , attack_damage: " << this->attack_damage << std::endl;
}