#include "s21_math.h"

long double atan_teylor(double x) {
  long double result = x;
  long double temp = x;
  for (int i = 1; s21_fabs(temp) > s21_EPS; i++) {
    temp = -temp;
    temp *= x * x * (2 * i - 1) / (2 * i + 1);
    result += temp;
  }
  return result;
}

long double s21_atan(double x) {
  long double result = x;
  if (x < 1.0 && x > -1.0) {
    result = atan_teylor(x);
  } else if (x == 1) {
    result = s21_P_4;
  } else if (x == -1) {
    result = -s21_P_4;
  } else if (x > 1) {
    result = s21_P_2 - atan_teylor(1 / x);
  } else if (x < -1) {
    result = -s21_P_2 - atan_teylor(1 / x);
  }
  return result;
}
