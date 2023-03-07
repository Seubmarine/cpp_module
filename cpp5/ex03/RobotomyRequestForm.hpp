#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <AForm.hpp>

class RobotomyRequestForm : public AForm {
private:
	std::string target;
	virtual void execute_real() const;

public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &rhs);
	const RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
};

#endif