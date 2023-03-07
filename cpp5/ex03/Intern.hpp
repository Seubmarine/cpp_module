#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
public:
	Intern();
	~Intern();
	Intern(const Intern &rhs);
	const Intern &operator=(const Intern &rhs);
	AForm *makeForm(std::string form_name, std::string target);
};

#endif