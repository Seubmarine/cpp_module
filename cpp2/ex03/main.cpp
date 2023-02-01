#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

void bsp_verbose(Point a, Point b, Point c, Point point) {
  std::cout << "Forming a triangle from :\nA" << a << "\nB" << b << '\n'
            << 'C' << c << "\n\nPoint" << point << "\n\n";
  std::cout << "Is the point inside the triangle: " << bsp(a, b, c, point)
            << std::endl;
}

int main(void) {
  bsp_verbose(Point(101.0f, 103.0f), Point(103.0f, 103.f),
              Point(102.0f, 101.0f), Point(102.0f, 103.0f));
  bsp_verbose(Point(101.0f, 103.0f), Point(103.0f, 103.f),
              Point(102.0f, 101.0f), Point(104.0f, 103.0f));
}