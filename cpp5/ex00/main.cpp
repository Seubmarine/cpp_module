#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    Bureaucrat one("Theo", 1);

    Bureaucrat two("Kevin", 150);
    
	try {
		Bureaucrat bad_too_high("BadTheo", 0);
	}
	catch (Bureaucrat::GradeTooHighException &)
	{
		std::cout << "Create Instance with too high exception" << std::endl;
	}


	try {
	    Bureaucrat bad_too_low("BadKevin", 151);
	}
	catch (Bureaucrat::GradeTooLowException &)
	{
		std::cout << "Create Instance with too low exception" << std::endl;
	}

	//increment test
	try {
		Bureaucrat inc_test("inc", 1);
		inc_test.gradeDecrement();
		inc_test.gradeIncrement();
		inc_test.gradeIncrement();
	}
	catch (Bureaucrat::GradeTooHighException &)
	{
		std::cout << "increment exception" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &)
	{
		std::cout << "decrement exception" << std::endl;
	}


	//decrement test
	try {
		Bureaucrat dec_test("dec", 150);
		dec_test.gradeIncrement();
		dec_test.gradeDecrement();
		dec_test.gradeDecrement();
	}
	catch (Bureaucrat::GradeTooHighException &)
	{
		std::cout << "increment exception" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &)
	{
		std::cout << "decrement exception" << std::endl;
	}
	
	std::cout << one << std::endl;
	std::cout << two << std::endl;

	two = one;

	std::cout << two << std::endl;

    return 0;
}
