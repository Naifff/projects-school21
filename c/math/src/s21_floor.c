#include "s21_math.h"

long double s21_floor(double x) {
  int flag = 1;
  double result;
  if (x == s21_INF || x == -s21_INF) {
    result = x;
    flag = 0;
  }
  long long temp = x * 1000000;
  if (((flag == 1) && temp % 1000000 == 0 && (x < 0)) || (x == 0)) {
    flag = 0;
    result = (long long)x;
  }
  if (x != x && flag == 1) {
    flag = 0;
    result = s21_NAN;
  }
  if (x > 0 && flag == 1) {
    result = ((long long)x);
  }
  if (x < 0 && flag == 1) {
    result = ((long long)x) - 1;
  }
  return result;
}
