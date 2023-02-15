#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	{
		Fixed test;
		test.setRawBits(42);
		std::cout << test.getRawBits() << std::endl;
	}

	return 0;
}