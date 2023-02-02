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
	size_t mary_count = 3;
	Zombie *marys = zombieHorde(mary_count, "Mary");
	size_t gabe_count = 7;
	Zombie *gabes = zombieHorde(gabe_count, "Gabe");
	for (size_t i = 0; i < mary_count; i++) {
		marys[i].announce();
	}
	for (size_t i = 0; i < gabe_count; i++) {
		gabes[i].announce();
	}
	delete[] marys;
	delete[] gabes;
}

int main(void)
{	
	test_ok();
	// test_leak(); // Watch out to delete correctly, should leak
	// test_bad_alloc(); //Watch out for passing negative number to new[] will abort the program
	// test_zero_sized_zombie_horde(); // a horde of size zero
}
