#include "Form.hpp"
#include <iostream>

void Form::checkGrade(int grade) {
    if (grade < 1)
        throw Form::GradeTooHighException();
    else if (grade > 150)
        throw Form::GradeTooLowException();
}

Form::Form() : name("DefaultForm"), grade_requirement_to_sign(1), grade_requirement_to_execute(1), sign(false) {
    this->checkGrade(grade_requirement_to_execute);
    this->checkGrade(grade_requirement_to_sign);
}

Form::~Form() {}
Form::Form(const Form &rhs) : 
    name(rhs.getName()),
    grade_requirement_to_sign(rhs.getGradeRequirementToSign()),
    grade_requirement_to_execute(rhs.getGradeRequirementToExecute()),
    sign(rhs.getSign())
{
    this->checkGrade(grade_requirement_to_execute);
    this->checkGrade(grade_requirement_to_sign);
}

const Form &Form::operator=(const Form &rhs) {
    this->sign = rhs.getSign();
    return *this;
}

Form::Form(const std::string name, int grade_to_sign, int grade_to_execute) : name(name), grade_requirement_to_sign(grade_to_sign), grade_requirement_to_execute(grade_to_execute), sign(false)
{
    this->checkGrade(grade_requirement_to_execute);
    this->checkGrade(grade_requirement_to_sign);
}


std::string Form::getName() const {
    return this->name;
}

bool Form::getSign() const {
    return this->sign;
}

int Form::getGradeRequirementToSign() const {
    return this->grade_requirement_to_sign;
}

int Form::getGradeRequirementToExecute() const {
    return this->grade_requirement_to_execute;
}

void Form::beSigned(Bureaucrat &buraucrat) {
    if (buraucrat.getGrade() <= this->grade_requirement_to_sign) {
        this->sign = true;
    }
    else {
        throw Form::GradeTooLowException();
    }
}



std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << "Form name: " << form.getName() << "\n"
    << "is signed : " << (form.getSign() ? "true" : "false")<< "\n"
    << "grade requirement to sign : " << form.getGradeRequirementToSign() << "\n"
    << "grade requirement to execute : " << form.getGradeRequirementToExecute();
    return (os);
}