#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& rhs) {
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = rhs.value;
	return (*this);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

Fixed::Fixed(const int integer) {
	std::cout << "Int constructor called" << std::endl;
	this->value = integer << this->fixed_position;
}

Fixed::Fixed(const float floating) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(floating * (float)(1 << this->fixed_position));
}

int Fixed::toInt(void) const {
	return (this->value >> this->fixed_position);
}

float Fixed::toFloat(void) const {
	return ((float)this->value / (float)(1 << this->fixed_position));
}

std::ostream &operator<<( std::ostream &output, const Fixed &fixed ) { 
	output << fixed.toFloat();
    return (output);
}