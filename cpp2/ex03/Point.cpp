#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() {}
Point::Point(const float x, const float y) : x(x), y(y) {}
Point::Point(const Point &point) : x(point.x), y(point.y) {}
Point &Point::operator=(const Point &point) {
  *this = point;
  return *this;
}
Point::~Point() {}

const Fixed &Point::getX() const { return this->x; }
const Fixed &Point::getY() const { return this->y; }

std::ostream &operator<<(std::ostream &output, const Point &point) {
  output << '(' << point.getX() << ", " << point.getY() << ')';
  return (output);
}