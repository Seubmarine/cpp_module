#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
private:
	int value;
	static const int fixed_position = 8;
public:
	Fixed(); //initialize to zero
	~Fixed();
	Fixed(const Fixed& rhs); //copy it initialize a new Fixed
	Fixed& operator=(const Fixed&); //copy assignement it replace the previous data
	int getRawBits(void) const;
	void setRawBits(int const raw);

	Fixed(const int integer);
	Fixed(const float floating);

	float toFloat( void ) const;
	int toInt( void ) const;

	// std::ostream& operator<< (std::ostream &out);
};

std::ostream &operator<<(std::ostream &output, const Fixed &fixed);

#endif