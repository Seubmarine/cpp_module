#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	{
		ScavTrap no_name = ScavTrap();
	}
	ScavTrap nancy("Nancy");
	//Nancy can call takeDamage since it inherits the class ClapTrap
	nancy.takeDamage(4);
	//It rewrited attack to the new member function
	nancy.attack("Lola");
	ClapTrap nord("Nord");
	nord.attack("Boby");
	nancy.guardGate();
	// nord is of class Claptrap and can't call other class function
	// nord.guardGate();
	ScavTrap copy_assign = nancy;
}
