#include "RobotomyRequestForm.hpp"
#include <stdlib.h> /* srand, rand */
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
		AForm("robotomy request", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::execute_real() const {
	if (rand() % 2) {
		std::cout << this->target << " has been robotomized successfully." << std::endl;
	} else {
		std::cout << this->target << " robotomization failed." << std::endl;
	}
}