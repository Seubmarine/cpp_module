#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
		AForm("presidential pardon", 25, 5), target(target){};

void PresidentialPardonForm::execute_real() const {
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {}
