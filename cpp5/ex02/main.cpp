#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <stdlib.h> /* srand, rand */
#include <time.h> /* time */
#include <iostream>

void test1() {
	AForm *shrub = new ShrubberyCreationForm("minecraft");
	Bureaucrat theo("Theo", 150);

	theo.signForm(*shrub);
	theo.executeForm(*shrub);

	try {
		while (1)
			theo.gradeIncrement();
	} catch (const std::exception &e) {
	}

	theo.signForm(*shrub);
	theo.executeForm(*shrub);

	delete shrub;
}

void test2() {
	AForm *robot = new RobotomyRequestForm("mergez");
	Bureaucrat theo("Theo", 150);

	theo.signForm(*robot);
	theo.executeForm(*robot);

	try {
		while (1)
			theo.gradeIncrement();
	} catch (const std::exception &e) {
	}

	theo.signForm(*robot);
	for (size_t i = 0; i < 6; i++) {
		theo.executeForm(*robot);
	}

	delete robot;
}

void test3() {
	AForm *pardon = new PresidentialPardonForm("Michel");
	Bureaucrat theo("Theo", 150);

	theo.signForm(*pardon);
	theo.executeForm(*pardon);

	try {
		while (1)
			theo.gradeIncrement();
	} catch (const std::exception &e) {
	}

	theo.signForm(*pardon);
	theo.executeForm(*pardon);

	delete pardon;
}

int main() {
	test1();
	srand(time(NULL));
	test2();
	test3();
	return 0;
}
