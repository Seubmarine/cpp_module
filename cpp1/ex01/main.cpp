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

void test_zero_sized_zombie_horde() {
	//using zero sized array, see: https://stackoverflow.com/a/1087066/17480217
	{
		Zombie *zero_size_horde = zombieHorde(0, "Invalid");
		// zero_size_horde[0].setName("Zero");
		// zero_size_horde[0].announce(); // shouldn't access member or call function
		delete[] zero_size_horde; //even if the allocated array is of size 0 you should always call delete on it
	}
}

void test_leak() {
	new_horde_announce_live(5, "Will");
}

void test_bad_alloc() {
	new_horde_announce_die(-1, "invalide");
}

void test_ok() {
	new_horde_announce_die(3, "Mary");
}

int main(void)
{	
	test_ok();
	// test_leak(); // Watch out to delete correctly, should leak
	// test_bad_alloc(); //Watch out for passing negative number to new[] will abort the program
	// test_zero_sized_zombie_horde(); // a horde of size zero
}
