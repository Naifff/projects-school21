#include "s21_math.h"

long double s21_fabs(double x) {
  long double fabs = x;
  return fabs >= 0 ? fabs : -fabs;
}
