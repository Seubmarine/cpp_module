#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <AForm.hpp>

class AForm;

class Bureaucrat
{
private:
    const std::string name;
    int grade;
public:
    class GradeTooHighException : public std::exception {};
    class GradeTooLowException : public std::exception {};
    Bureaucrat(std::string name, int grade);

	Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &rhs);
    const Bureaucrat &operator=(const Bureaucrat &rhs);
	
	static void checkGrade(int i);

	const std::string getName() const;
	int getGrade() const;
	void gradeIncrement();
	void gradeDecrement();
    void signForm(AForm &form);
    void executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &m);

#endif