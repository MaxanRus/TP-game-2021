#include "Helpers/Vector2D.hpp"
#include "../../include/Helpers/Vector2D.hpp"

#include <cmath>

Vector2D::Vector2D() : x(0.0), y(0.0) {}

Vector2D::Vector2D(float x, float y) : x(x), y(y) {}

Vector2D& Vector2D::operator+=(const Vector2D& another) {
  x += another.x;
  y += another.y;
  return *this;
}

Vector2D Vector2D::operator+(const Vector2D& another) {
  Vector2D result(*this);
  result += another;
  return result;
}

Vector2D& Vector2D::operator-=(const Vector2D& another) {
  x -= another.x;
  y -= another.y;
  return *this;
}

Vector2D Vector2D::operator-(const Vector2D& another) {
  Vector2D result(*this);
  result -= another;
  return result;
}

Vector2D Vector2D::operator-() {
  return Vector2D(-x, -y);
}

float Vector2D::dist(const Vector2D& first, const Vector2D& second) {
  return sqrtf((first.x - second.x) * (first.x - second.x) + (first.y - second.y) * (first.y - second.y));
}

Vector2D& Vector2D::operator*=(float c) {
  x *= c;
  y *= c;
  return *this;
}

Vector2D Vector2D::operator*(float c) {
  Vector2D result(*this);
  result *= c;
  return result;
}

Vector2D& Vector2D::operator/=(float c) {
  x /= c;
  y /= c;
  return *this;
}

Vector2D Vector2D::operator/(float c) {
  Vector2D result(*this);
  result /= c;
  return result;
}

Vector2D::Vector2D(const std::pair<float, float>& another) {
  x = another.first;
  y = another.second;
}
