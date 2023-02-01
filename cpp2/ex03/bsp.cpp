#include "Fixed.hpp"
#include "Point.hpp"

// Use barycentric coordinate for fast and cheap calculation
bool bsp(Point const a, Point const b, Point const c, Point const p) {
  Fixed s1 = c.getY() - a.getY();
  Fixed s2 = c.getX() - a.getX();
  Fixed s3 = b.getY() - a.getY();
  Fixed s4 = p.getY() - a.getY();

  Fixed w1 = (a.getX() * s1 + s4 * s2 - p.getX() * s1) /
             (s3 * s2 - (b.getX() - a.getX()) * s1);
  Fixed tmp_w2 = (s4 - w1 * s3);
  Fixed w2 = tmp_w2 / s1;

  return w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1;
}