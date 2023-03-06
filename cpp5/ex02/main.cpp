#include <AForm.hpp>
#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
#include <iostream>

int main() {
	AForm *shrub = new ShrubberyCreationForm("minecraft");
	Bureaucrat theo("Theo", 150);

	theo.signForm(*shrub);
	theo.executeForm(*shrub);

	try {
		while (1)
			theo.gradeIncrement();
	} catch (const std::exception &e) {
	}

	theo.signForm(*shrub);
	theo.executeForm(*shrub);

	delete shrub;
	return 0;
}
