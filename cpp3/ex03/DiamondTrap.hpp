#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string name;
	using FragTrap::hit_point;
	using ScavTrap::energy_point;
	using FragTrap::attack_damage;
	using FragTrap::ClapTrap;

public:
	DiamondTrap(); //default constructor
	DiamondTrap(std::string name); //constructor with args

	using ScavTrap::attack;
	void whoAmI();
	~DiamondTrap(); //destructor
};
#endif