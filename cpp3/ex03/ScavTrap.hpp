#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
private:
public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();

	// ScavTrap &operator=(const ScavTrap &scavtrap);

	void attack(const std::string &target);
	void guardGate();
};
#endif