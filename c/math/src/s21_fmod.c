#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res = 0;
  long long int don = x / y;
  if (y == 0.0 || x == s21_INF || x == -s21_INF) {
    res = s21_NAN;
  } else if (y == s21_INF || y == -s21_INF) {
    res = x;
  } else {
    res = x - (don * y);
  }
  return res;
}
