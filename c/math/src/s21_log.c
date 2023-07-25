#include "s21_math.h"

long double s21_log(double x) {
  double result;
  if (x < 0 || x == -s21_INF || x != x) {
    result = s21_NAN;
  } else if (x == 0) {
    result = -s21_INF;
  } else if (x == s21_INF) {
    result = s21_INF;
  } else if (x == 1) {
    result = 0;
  }
  double num, pop, arr;
  arr = 0.0;
  pop = x;
  num = 0.0;
  while (pop >= s21_e) {
    pop /= s21_e;
    num++;
  }
  num += (pop / s21_e);
  pop = x;
  int j = 0;
  while (num != arr && j < 10) {
    double len, red;
    arr = num;
    len = (pop / (s21_exp(num - 1.0)));
    red = ((num - 1.0) * s21_e);
    num = ((len + red) / s21_e);
    j++;
  }
  return x > 0 ? num : result;
}
