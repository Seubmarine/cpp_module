#ifndef FIXED_H
#define FIXED_H

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
};


#endif