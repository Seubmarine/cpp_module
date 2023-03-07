#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	std::string target;
	virtual void execute_real() const;

public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
	const ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
};

#endif