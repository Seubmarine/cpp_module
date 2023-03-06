#include <Bureaucrat.hpp>
#include <Form.hpp>
#include <iostream>

int main()
{

    try {
		Form bad("BadForm", 0, 150);
	}
	catch (const Form::GradeTooHighException &)
	{
		std::cout << "Create Instance with grade too high exception" << std::endl;
	}

    try {
		Form bad("BadForm", 1, 151);
	}
	catch (const Form::GradeTooLowException &)
	{
		std::cout << "Create Instance with grade too low exception" << std::endl;
	}

    Bureaucrat theo("Theo", 55);
    Form normal("Normal", 54, 150);

    std::cout << normal << std::endl << std::endl;
    theo.signForm(normal);
    theo.gradeIncrement();
    theo.signForm(normal);
    std::cout << normal << std::endl << std::endl;

    Form highest("Highest", 1, 1);
    theo.signForm(highest);
    try {
        while (1)
            theo.gradeIncrement();
    }
    catch(const std::exception& e) {}
    theo.signForm(highest);
    std::cout << highest << std::endl << std::endl;
    return 0;
}
