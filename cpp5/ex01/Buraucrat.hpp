#ifndef BURAUCRAT_HPP
#define BURAUCRAT_HPP

#include <string>
#include <exception>
#include <Form.hpp>

class Form;

class Buraucrat
{
private:
    const std::string name;
    int grade;
public:
    class GradeTooHighException : public std::exception {};
    class GradeTooLowException : public std::exception {};
    Buraucrat(std::string name, int grade);

	Buraucrat();
    ~Buraucrat();
    Buraucrat(const Buraucrat &rhs);
    const Buraucrat &operator=(const Buraucrat &rhs);
	
	static void checkGrade(int i);

	const std::string getName() const;
	int getGrade() const;
	void gradeIncrement();
	void gradeDecrement();
    void signForm(Form &form);
};

std::ostream &operator<<(std::ostream &os, Buraucrat const &m);

#endif