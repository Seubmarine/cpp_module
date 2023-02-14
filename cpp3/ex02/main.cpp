#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	{
		FragTrap no_name = FragTrap();
	}
	FragTrap nancy("Nancy");
	//Nancy can call takeDamage since it inherits the class ClapTrap
	nancy.takeDamage(4);
	//It rewrited attack to the new member function
	nancy.attack("Lola");
	ClapTrap nord("Nord");
	nord.attack("Boby");
	nancy.highFivesGuys();
	// nord is of class Claptrap and can't call other class function
	// nord.guardGate();
	FragTrap copy_assign = nancy;
}
