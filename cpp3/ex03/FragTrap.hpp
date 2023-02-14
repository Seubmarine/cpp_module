#ifndef FragTrap_H
#define FragTrap_H
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
private:
public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();

	void attack(const std::string &target);
	void highFivesGuys(void);
};
#endif