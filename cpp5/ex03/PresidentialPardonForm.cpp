#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
		AForm("presidential pardon", 25, 5), target(target){};

PresidentialPardonForm::PresidentialPardonForm() :
		AForm("presidential pardon", 25, 5), target("") {}
PresidentialPardonForm::~PresidentialPardonForm() {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) :
		AForm(rhs.getName(), rhs.getGradeRequirementToSign(), rhs.getGradeRequirementToExecute()), target(rhs.target) {
}

const PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	if (this != &rhs) {
		this->target = rhs.target;
	}
	return *this;
}

void PresidentialPardonForm::execute_real() const {
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
