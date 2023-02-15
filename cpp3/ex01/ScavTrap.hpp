#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &scavtrap);
	ScavTrap &operator=(const ScavTrap &scavtrap);
	~ScavTrap();

	// ScavTrap &operator=(const ScavTrap &scavtrap);

	void attack(const std::string &target);
	void guardGate();
};
#endif