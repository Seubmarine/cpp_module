#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
		AForm("shrubbery creation", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm() :
		AForm("shrubbery creation", 145, 137), target("") {}

void ShrubberyCreationForm::execute_real() const {
	std::ofstream outfile;
	std::string filename = this->target + "_shrubbery";
	outfile.open(filename.c_str(), std::ios::out);
	if (!outfile.is_open()) {
		std::cerr << "Could not open file." << std::endl;
		return;
	}
	const char tree[] = "  #  \n ### \n#####\n ### \n  [  \n  ]  \n..M..\n";
	outfile << tree << std::endl;
	outfile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs) :
		AForm(rhs.getName(), rhs.getGradeRequirementToSign(), rhs.getGradeRequirementToExecute()), target(rhs.target) {
}

const ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	if (this != &rhs) {
		this->target = rhs.target;
	}
	return *this;
}