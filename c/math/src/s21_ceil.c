#include "s21_math.h"

long double s21_ceil(double num) {
  int res = num;
  return res == num  ? res
         : res < num ? (long double)res + 1.0
                     : (long double)res;
}
