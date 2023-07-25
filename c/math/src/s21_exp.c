#include "s21_math.h"

long double s21_exp(double x) {
  long double res = 0;
  if (x < 0) {
    res = 1 / s21_exp((-1) * x);
  } else {
    for (int k = 0; k < 40; ++k) {
      double current = 1;
      for (int j = 1; j <= k; ++j) {
        current *= x;
        current /= j;
      }
      res += current;
    }
  }
  return res;
}
