#pragma once

#include <utility>
#include <cmath>

template<class T>
struct Vector2D {
  T x, y;

  Vector2D();
  Vector2D(const T& x, const T& y);
  Vector2D(const Vector2D&) = default;
  explicit Vector2D(const std::pair<T, T>& another);
  Vector2D& operator=(const Vector2D&) = default;

  Vector2D operator-();
  Vector2D& operator+=(const Vector2D& another);
  Vector2D& operator-=(const Vector2D& another);
  Vector2D& operator*=(T c);
  Vector2D operator*(T c);
  Vector2D& operator/=(T c);
  Vector2D operator/(T c);

  static float dist(const Vector2D& first, const Vector2D& second);
};

template<class T>
Vector2D<T>::Vector2D(const std::pair<T, T>& another) : x(another.first), y(another.second) {}

template<class T>
Vector2D<T>::Vector2D() : x(), y() {}

template<class T>
Vector2D<T>::Vector2D(const T& x, const T& y) : x(x), y(y) {}

template<class T>
Vector2D<T> Vector2D<T>::operator-() {
  return Vector2D(-x, -y);
}

template<class T>
Vector2D<T>& Vector2D<T>::operator+=(const Vector2D<T>& another) {
  x += another.x;
  y += another.y;
  return *this;
}

template<class T>
Vector2D<T> operator+(const Vector2D<T>& first, const Vector2D<T>& second) {
  Vector2D<T> result(first);
  result += second;
  return result;
}

template<class T>
Vector2D<T>& Vector2D<T>::operator-=(const Vector2D& another) {
  x -= another.x;
  y -= another.y;
  return *this;
}

template<class T>
Vector2D<T> operator-(const Vector2D<T>& first, const Vector2D<T>& second) {
  Vector2D<T> result(first);
  result -= second;
  return result;
}

template<class T>
Vector2D<T>& Vector2D<T>::operator*=(T c) {
  x *= c;
  y *= c;
  return *this;
}

template<class T>
Vector2D<T> Vector2D<T>::operator*(T c) {
  return Vector2D(*this) *= c;
}

template<class T>
Vector2D<T>& Vector2D<T>::operator/=(T c) {
  x /= c;
  y /= c;
  return *this;
}

template<class T>
Vector2D<T> Vector2D<T>::operator/(T c) {
  return Vector2D(*this) /= c;
}

template<class T>
float Vector2D<T>::dist(const Vector2D& first, const Vector2D& second) {
  return std::sqrt((first.x - second.x) * (first.x - second.x) + (first.y - second.y) * (first.y - second.y));
}

using Vector2Df = Vector2D<float>;
