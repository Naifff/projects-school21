#include "s21_math.h"

long double s21_sqrt(double x) { return s21_exp(0.5 * s21_log(x)); }
