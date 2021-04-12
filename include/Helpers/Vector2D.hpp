#pragma once

struct Vector2D {
  float x, y;

  Vector2D();
  //Vector2D(int x, int y);
  Vector2D(float x, float y);
  Vector2D(const Vector2D&) = default;
  Vector2D& operator=(const Vector2D&) = default;

  Vector2D operator-();
  Vector2D& operator+=(const Vector2D& another);
  Vector2D operator+(const Vector2D& another);
  Vector2D& operator-=(const Vector2D& another);
  Vector2D operator-(const Vector2D& another);
  Vector2D& operator*=(float c);
  Vector2D operator*(float c);
  Vector2D& operator/=(float c);
  Vector2D operator/(float c);

  static float dist(const Vector2D& first, const Vector2D& second);
};