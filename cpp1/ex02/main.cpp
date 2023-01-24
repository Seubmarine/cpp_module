#include <string>
#include <iostream>

int main(void)
{
	std::string original = "HI THIS IS BRAIN";

	std::string *stringPTR = &original;
	std::string &stringREF = original;

	std::cout << "Memory original: " << &original << std::endl;
	std::cout << "Memory ptr     : " << stringPTR << std::endl;
	std::cout << "Memory ref     : " << &stringREF << std::endl;

	std::cout << "Value original: " << original << std::endl;
	std::cout << "Value ptr     : " << *stringPTR << std::endl;
	std::cout << "Value ref     : " << stringREF << std::endl;
	return 0;
}
