#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern &rhs) {
	*this = rhs;
}
const Intern &Intern::operator=(const Intern &rhs) {
	*this = rhs;
	return *this;
}

AForm *Intern::makeForm(std::string form_name, std::string target) {
	AForm *forms[] = {
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target),
		new ShrubberyCreationForm(target)
	};
	AForm *form_to_return = NULL;
	for (size_t i = 0; i < (sizeof(forms) / sizeof(forms[0])); i++) {
		if (forms[i]->getName() == form_name) {
			form_to_return = forms[i];
		} else {
			delete forms[i];
		}
	}
	return (form_to_return);
}