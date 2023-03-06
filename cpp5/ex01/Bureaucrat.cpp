#include "Bureaucrat.hpp"
#include <iostream>

void Bureaucrat::checkGrade(int grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat() :
		grade(150) {
	this->checkGrade(this->grade);
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs) :
		name(rhs.name), grade(rhs.grade) {
	this->checkGrade(this->grade);
}

const Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs) {
		this->grade = rhs.grade;
	}
	this->checkGrade(this->grade);
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade) :
		name(name), grade(grade) {
	this->checkGrade(this->grade);
}
const std::string Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::gradeIncrement() {
	this->checkGrade(this->grade - 1);
	this->grade -= 1;
}

void Bureaucrat::gradeDecrement() {
	this->checkGrade(this->grade + 1);
	this->grade += 1;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &m) {
	os << m.getName() << ", bureaucrat grade " << m.getGrade() << ".";
	return os;
}

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	} catch (Form::GradeTooLowException &e) {
		std::cout << "Form " << this->getName() << " need a grade of " << form.getGradeRequirementToExecute() << " to be signed, but bureaucrat " << this->getName() << " only has a grade of " << this->getGrade() << std::endl;
	}
}