#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string name;
    const int grade_requirement_to_sign;
    const int grade_requirement_to_execute;
    bool sign;
public:
    class GradeTooHighException : public std::exception {};
    class GradeTooLowException : public std::exception {};
 
    ~AForm();
    AForm();
    AForm(const AForm &rhs);
    const AForm &operator=(const AForm &rhs);

    AForm(const std::string name, int grade_to_sign, int grade_to_execute);


	static void checkGrade(int grade);
    std::string getName() const;
    bool getSign() const;
    int getGradeRequirementToSign() const;
    int getGradeRequirementToExecute() const;
    void beSigned(Bureaucrat &buraucrat);
    virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif