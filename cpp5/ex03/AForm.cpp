#include "AForm.hpp"
#include <iostream>

void AForm::checkGrade(int grade) {
	if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm() :
		name("DefaultAForm"), grade_requirement_to_sign(1), grade_requirement_to_execute(1), sign(false) {
	this->checkGrade(grade_requirement_to_execute);
	this->checkGrade(grade_requirement_to_sign);
}

AForm::~AForm() {}
AForm::AForm(const AForm &rhs) :
		name(rhs.getName()),
		grade_requirement_to_sign(rhs.getGradeRequirementToSign()),
		grade_requirement_to_execute(rhs.getGradeRequirementToExecute()),
		sign(rhs.getSign()) {
	this->checkGrade(grade_requirement_to_execute);
	this->checkGrade(grade_requirement_to_sign);
}

const AForm &AForm::operator=(const AForm &rhs) {
	this->sign = rhs.getSign();
	return *this;
}

AForm::AForm(const std::string name, int grade_to_sign, int grade_to_execute) :
		name(name), grade_requirement_to_sign(grade_to_sign), grade_requirement_to_execute(grade_to_execute), sign(false) {
	this->checkGrade(grade_requirement_to_execute);
	this->checkGrade(grade_requirement_to_sign);
}

std::string AForm::getName() const {
	return this->name;
}

bool AForm::getSign() const {
	return this->sign;
}

int AForm::getGradeRequirementToSign() const {
	return this->grade_requirement_to_sign;
}

int AForm::getGradeRequirementToExecute() const {
	return this->grade_requirement_to_execute;
}

void AForm::beSigned(Bureaucrat &buraucrat) {
	if (buraucrat.getGrade() <= this->grade_requirement_to_sign) {
		this->sign = true;
	} else {
		throw AForm::GradeTooLowException();
	}
}

void AForm::execute(Bureaucrat const &executor) const {
	if (!this->getSign())
		throw NotSignedException();
	if (executor.getGrade() <= this->grade_requirement_to_execute) {
		this->execute_real();
	} else {
		throw AForm::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << "Form name: " << form.getName() << "\n"
	   << "is signed : " << (form.getSign() ? "true" : "false") << "\n"
	   << "grade requirement to sign : " << form.getGradeRequirementToSign() << "\n"
	   << "grade requirement to execute : " << form.getGradeRequirementToExecute();
	return (os);
}