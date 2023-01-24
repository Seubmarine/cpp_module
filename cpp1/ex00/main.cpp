#include "Zombie.hpp"

int main(void)
{
	randomChump("Will");
	Zombie *returned = newZombie("Gabe");
	returned->announce();
	randomChump("Jonathan");
	returned->announce();
	delete returned;
	return 0;
}
