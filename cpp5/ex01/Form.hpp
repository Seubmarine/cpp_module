#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string name;
    const int grade_requirement_to_sign;
    const int grade_requirement_to_execute;
    bool sign;
public:
    class GradeTooHighException : public std::exception {};
    class GradeTooLowException : public std::exception {};
 
    Form();
    ~Form();
    Form(const Form &rhs);
    const Form &operator=(const Form &rhs);
    Form(const std::string name, int grade_to_execute, int grade_to_sign);


	static void checkGrade(int grade);
    std::string getName() const;
    bool getSign() const;
    int getGradeRequirementToSign() const;
    int getGradeRequirementToExecute() const;
    void beSigned(Bureaucrat &buraucrat);
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif