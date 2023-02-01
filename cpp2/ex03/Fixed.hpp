#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
private:
  int value;
  static const int fixed_position = 8;

public:
  Fixed(); // initialize to zero
  ~Fixed();
  Fixed(const Fixed &rhs); // it initialize a new Fixed
  Fixed &
  operator=(const Fixed &); // copy assignement it replace the previous data
  int getRawBits(void) const;
  void setRawBits(int const raw);

  Fixed(const int integer);
  Fixed(const float floating);

  float toFloat(void) const;
  int toInt(void) const;

  // overloading
  bool operator>(Fixed const &rhs);
  bool operator<(Fixed const &rhs);
  bool operator>=(Fixed const &rhs);
  bool operator<=(Fixed const &rhs);
  bool operator==(Fixed const &rhs);
  bool operator!=(Fixed const &rhs);

  Fixed operator+(Fixed const &rhs) const;
  Fixed operator-(Fixed const &rhs) const;
  Fixed operator*(Fixed const &rhs) const;
  Fixed operator/(Fixed const &rhs) const;

  Fixed &operator++();   // prefix increment
  Fixed operator++(int); // postfix increment
  Fixed &operator--();   // prefix decrement
  Fixed operator--(int); // postfix decrement

  // min and max
  static Fixed &min(Fixed &lhs, Fixed &rhs);
  static const Fixed &min(const Fixed &lhs, const Fixed &rhs);
  static Fixed &max(Fixed &lhs, Fixed &rhs);
  static const Fixed &max(const Fixed &lhs, const Fixed &rhs);
};

std::ostream &operator<<(std::ostream &output, const Fixed &fixed);

#endif