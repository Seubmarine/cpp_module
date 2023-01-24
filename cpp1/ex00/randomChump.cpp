#include "Zombie.hpp"

void randomChump( std::string name) {
	Zombie temporary_chump = Zombie(name);
	temporary_chump.announce();
}