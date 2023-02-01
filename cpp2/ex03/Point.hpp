#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point {
private:
  Fixed const x;
  Fixed const y;

public:
  Point(); // default
  Point(const float x, const float y);
  Point(const Point &point); // it initialize a new Point
  Point &operator=(const Point &point);
  ~Point();
  const Fixed &getY() const;
  const Fixed &getX() const;
};

std::ostream &operator<<(std::ostream &output, const Point &fixed);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif