#include "s21_math.h"

long double s21_asin(double x) {
  long double result = x;
  if (x < 1.0 && x > -1.0) {
    result = s21_atan(x / s21_sqrt(1 - x * x));
  } else if (x == 1) {
    result = s21_P_2;
  } else if (x == -1) {
    result = -s21_P_2;
  } else if (x > 1 || x < -1) {
    result = s21_NAN;
  }
  return result;
}
