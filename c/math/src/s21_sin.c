#include "s21_math.h"

long double s21_sin(double x) {
  long double res;

  if (x == s21_INF || x == -s21_INF || x != x) {
    res = s21_NAN;
  }
  x = s21_fmod(x, 2 * s21_PI);
  while (x > s21_PI) {
    x -= 2 * s21_PI;
  }

  while (x < -s21_PI) {
    x += 2 * s21_PI;
  }
  res = x;
  int fact = 1;
  long double temp = x;
  while (s21_fabs(temp) > s21_EPS) {
    temp = (-temp * x * x) / ((2 * fact + 1) * (2 * fact));
    res += temp;
    fact++;
  }
  return res;
}
