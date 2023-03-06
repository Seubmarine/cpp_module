#include "Buraucrat.hpp"
#include <iostream>

void Buraucrat::checkGrade(int grade) {
    if (grade < 1)
        throw Buraucrat::GradeTooHighException();
    else if (grade > 150)
        throw Buraucrat::GradeTooLowException();
}

Buraucrat::Buraucrat() : grade(150) {
	this->checkGrade(this->grade);
}

Buraucrat::~Buraucrat() {}

Buraucrat::Buraucrat(const Buraucrat &rhs) : name(rhs.name), grade(rhs.grade) {
	this->checkGrade(this->grade);
}

const Buraucrat &Buraucrat::operator=(const Buraucrat &rhs) {
    if (this != &rhs) {
        this->grade = rhs.grade;
    }
	this->checkGrade(this->grade);
    return *this;
}

Buraucrat::Buraucrat(std::string name, int grade) : name(name), grade(grade) {
	this->checkGrade(this->grade);
}
const std::string Buraucrat::getName() const {
	return this->name;
}

int Buraucrat::getGrade() const {
	return this->grade;
}

void Buraucrat::gradeIncrement() {
	this->checkGrade(this->grade - 1);
	this->grade -= 1;
}

void Buraucrat::gradeDecrement() {
	this->checkGrade(this->grade + 1);
	this->grade += 1;
}

std::ostream &operator<<(std::ostream &os, Buraucrat const &m) {
	os << m.getName() << ", bureaucrat grade " << m.getGrade() << ".";
	return os;
}

void Buraucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because of Form::GradeTooLow exception" << std::endl;
	}
}