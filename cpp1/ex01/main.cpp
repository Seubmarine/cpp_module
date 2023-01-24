#include "Zombie.hpp"
#include <iostream>

void new_horde_announce_die(int horde_size, std::string horde_name) {
	Zombie *valid_horde = zombieHorde(horde_size, horde_name);
	for (int i = 0; i < horde_size; i++) {
		valid_horde[i].announce();
	}
	delete[] valid_horde;
}

void new_horde_announce_live(int horde_size, std::string horde_name) {
	Zombie *valid_horde = zombieHorde(horde_size, horde_name);
	for (int i = 0; i < horde_size; i++) {
		valid_horde[i].announce();
	}
}

int main(void)
{	
	new_horde_announce_die(3, "Mary");
	// new_horde_announce_die(-1, "invalide"); //Watch out for passing negative number to new[] will abort the program
	// new_horde_announce_live(5, "Will"); // Watch out to delete correctly, should leak
	
	//using zero sized array, see: https://stackoverflow.com/a/1087066/17480217
	{
		Zombie *zero_size_horde = zombieHorde(-1, "Invalid");
		// zero_size_horde[0].setName("Zero");
		// zero_size_horde[0].announce();
		
		(void)zero_size_horde;
		delete[] zero_size_horde; //even if the allocated array is of size 0 you should always call delete on it
	}
}
