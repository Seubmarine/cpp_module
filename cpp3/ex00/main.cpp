#include "ClapTrap.hpp"

int main(void) {
	ClapTrap garry("Garry");
	ClapTrap mario("Mario");
	ClapTrap no_name = ClapTrap();
	for (size_t i = 0; i < 12; i++) {
		garry.takeDamage(4);
		garry.beRepaired(2);
		garry.attack("Boby");
		no_name.attack("something");
		mario.beRepaired(5);
	}
	return 0;
}
