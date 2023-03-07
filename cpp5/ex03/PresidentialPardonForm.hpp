#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
private:
	std::string target;
	virtual void execute_real() const;

public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &rhs);
	const PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
};

#endif