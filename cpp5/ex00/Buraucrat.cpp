#include "Buraucrat.hpp"

Buraucrat::Buraucrat() : grade(150) {}

Buraucrat::~Buraucrat() {}

Buraucrat::Buraucrat(const Buraucrat &rhs) : name(rhs.name), grade(rhs.grade) {}

const Buraucrat &Buraucrat::operator=(const Buraucrat &rhs) {
    if (this != &rhs) {
        this->grade = rhs.grade;
    }
    return *this;
}

Buraucrat::Buraucrat(std::string name, int grade) : name(name), grade(grade) {

}

void checkGrade(int grade) {
    if (grade < 1)
        throw Buraucrat::GradeTooHighException();
    else if (grade > 150)
        throw Buraucrat::GradeTooLowException();
}