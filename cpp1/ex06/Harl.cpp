#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl() {
}

Harl::~Harl() {
}

void Harl::complain(std::string level) {
	const struct HarlHelper levels_data[4] = {
		{"DEBUG", &Harl::debug},
		{"INFO",  &Harl::info},
		{"WARNING",  &Harl::warning},
		{"ERROR", &Harl::error}
	};
	
	bool activate_complaint = false;
	for (size_t i = 0; i < (sizeof(levels_data) / sizeof(levels_data[0])); i++)
	{
		struct HarlHelper current = levels_data[i];
		if (!activate_complaint && current.level_name == level) {
			activate_complaint = true;
		}
		if (activate_complaint) {
			(this->*current.level_function)();
		}
	}

	if (!activate_complaint) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
