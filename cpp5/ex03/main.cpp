#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
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
	RobotomyRequestForm original("mergez");
	AForm *robot = new RobotomyRequestForm(original);
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
	PresidentialPardonForm original("Michel");
	AForm *pardon = new PresidentialPardonForm(original);
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

void test4() {
	Intern someRandomIntern;
	AForm *rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	Bureaucrat micheal("Micheal", 25);

	micheal.signForm(*rrf);
	micheal.executeForm(*rrf);
	delete rrf;

	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	micheal.signForm(*rrf);
	micheal.executeForm(*rrf);
	delete rrf;

	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	micheal.signForm(*rrf);
	micheal.executeForm(*rrf);
	delete rrf;
}

int main() {
	test1();
	srand(time(NULL));
	test2();
	test3();
	test4();
	return 0;
}
