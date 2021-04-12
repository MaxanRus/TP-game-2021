#include "Helpers/Vector2D.hpp"
#include <cmath>
Vector2D::Vector2D(): x(0.0), y(0.0) {
}
Vector2D::Vector2D(float x, float y): x(x), y(y) {
}
Vector2D& Vector2D::operator+=(const Vector2D& a) {
  x += a.x;
  y += a.y;
  return *this;
}
Vector2D Vector2D::operator-() {
  return Vector2D(-x, -y);
}
float Vector2D::dist(const Vector2D& a, const Vector2D& b) {
  return sqrtf((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
