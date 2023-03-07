#include "RobotomyRequestForm.hpp"
#include <stdlib.h> /* srand, rand */
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
		AForm("robotomy request", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm() :
		AForm("robotomy request", 72, 45), target("") {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) :
		AForm(rhs.getName(), rhs.getGradeRequirementToSign(), rhs.getGradeRequirementToExecute()), target(rhs.target) {
}

const RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	if (this != &rhs) {
		this->target = rhs.target;
	}
	return *this;
}

void RobotomyRequestForm::execute_real() const {
	if (rand() % 2) {
		std::cout << this->target << " has been robotomized successfully." << std::endl;
	} else {
		std::cout << this->target << " robotomization failed." << std::endl;
	}
}