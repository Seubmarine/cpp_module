#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() { this->value = 0; }

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &rhs) { *this = rhs; }

Fixed &Fixed::operator=(const Fixed &rhs) {
  this->value = rhs.value;
  return (*this);
}

int Fixed::getRawBits(void) const { return (this->value); }

void Fixed::setRawBits(int const raw) { this->value = raw; }

Fixed::Fixed(const int integer) {
  this->value = integer << this->fixed_position;
}

Fixed::Fixed(const float floating) {
  this->value = roundf(floating * (float)(1 << this->fixed_position));
}

int Fixed::toInt(void) const { return ((int)this->toFloat()); }

float Fixed::toFloat(void) const {
  return ((float)this->value / (float)(1 << this->fixed_position));
}

std::ostream &operator<<(std::ostream &output, const Fixed &fixed) {
  output << fixed.toFloat();
  return (output);
}

bool Fixed::operator>(Fixed const &rhs) {
  return (this->toFloat() > rhs.toFloat());
}

bool Fixed::operator<(Fixed const &rhs) {
  return (this->toFloat() < rhs.toFloat());
}

bool Fixed::operator>=(Fixed const &rhs) {
  return (this->toFloat() >= rhs.toFloat());
}

bool Fixed::operator<=(Fixed const &rhs) {
  return (this->toFloat() <= rhs.toFloat());
}

bool Fixed::operator==(Fixed const &rhs) { return this->value == rhs.value; }

bool Fixed::operator!=(Fixed const &rhs) { return this->value != rhs.value; }

Fixed Fixed::operator+(Fixed const &rhs) const {
  Fixed tmp;
  tmp.setRawBits(this->value + rhs.value);
  return tmp;
}

Fixed Fixed::operator-(Fixed const &rhs) const {
  Fixed tmp;
  tmp.setRawBits(this->value - rhs.value);
  return (tmp);
}

Fixed Fixed::operator*(Fixed const &rhs) const {
  return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs) const {
  return Fixed(this->toFloat() / rhs.toFloat());
}

// prefix increment
Fixed &Fixed::operator++() {
  this->setRawBits(this->getRawBits() + 1);
  return *this;
}

// postfix increment
Fixed Fixed::operator++(int) {
  Fixed old = *this;
  this->setRawBits(this->getRawBits() + 1);
  return old;
}

// prefix decrement
Fixed &Fixed::operator--() {
  this->setRawBits(this->getRawBits() - 1);
  return *this;
}

// postfix decrement
Fixed Fixed::operator--(int) {
  Fixed old = *this;
  this->setRawBits(this->getRawBits() - 1);
  return old;
}

// min max
Fixed &Fixed::min(Fixed &lhs, Fixed &rhs) {
  return lhs.toFloat() < rhs.toFloat() ? lhs : rhs;
}

const Fixed &Fixed::min(const Fixed &lhs, const Fixed &rhs) {
  return lhs.toFloat() < rhs.toFloat() ? lhs : rhs;
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs) {
  return lhs.toFloat() > rhs.toFloat() ? lhs : rhs;
}

const Fixed &Fixed::max(Fixed const &lhs, Fixed const &rhs) {
  return lhs.toFloat() > rhs.toFloat() ? lhs : rhs;
}