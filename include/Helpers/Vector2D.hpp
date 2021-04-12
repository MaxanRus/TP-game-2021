#pragma once

struct Vector2D {
  float x, y;

  Vector2D();
  //Vector2D(int x, int y);
  Vector2D(float x, float y);

  Vector2D& operator+=(const Vector2D& a);
  Vector2D operator-();

  static float dist(const Vector2D& a, const Vector2D& b);
};