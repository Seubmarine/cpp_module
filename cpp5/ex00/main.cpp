#include "Buraucrat.hpp"
#include <iostream>

int main()
{
    Buraucrat one("Theo", 1);

    Buraucrat two("Kevin", 150);
    
	try {
		Buraucrat bad_too_high("BadTheo", 0);
	}
	catch (Buraucrat::GradeTooHighException &)
	{
		std::cout << "Create Instance with too high exception" << std::endl;
	}


	try {
	    Buraucrat bad_too_low("BadKevin", 151);
	}
	catch (Buraucrat::GradeTooLowException &)
	{
		std::cout << "Create Instance with too low exception" << std::endl;
	}

	//increment test
	try {
		Buraucrat inc_test("inc", 1);
		inc_test.gradeDecrement();
		inc_test.gradeIncrement();
		inc_test.gradeIncrement();
	}
	catch (Buraucrat::GradeTooHighException &)
	{
		std::cout << "increment exception" << std::endl;
	}
	catch (Buraucrat::GradeTooLowException &)
	{
		std::cout << "decrement exception" << std::endl;
	}


	//decrement test
	try {
		Buraucrat dec_test("dec", 150);
		dec_test.gradeIncrement();
		dec_test.gradeDecrement();
		dec_test.gradeDecrement();
	}
	catch (Buraucrat::GradeTooHighException &)
	{
		std::cout << "increment exception" << std::endl;
	}
	catch (Buraucrat::GradeTooLowException &)
	{
		std::cout << "decrement exception" << std::endl;
	}
	
	std::cout << one << std::endl;
	std::cout << two << std::endl;

	two = one;

	std::cout << two << std::endl;

    return 0;
}
