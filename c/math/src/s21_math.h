#ifndef SRC_S21_MATH_H
#define SRC_S21_MATH_H
#include <stdio.h>
#include <stdlib.h>

#define s21_EPS 1e-25
#define s21_PI 3.1415926535897932
#define s21_P_2 1.570796326794897
#define s21_P_4 0.785398163397448
#define s21_NAN 0.0 / 0.0
#define s21_NEGZERO -1e-20
#define s21_INF 1.0 / 0.0
#define s21_DBL_MAX 1.7976931348623158e+308
#define s21_e 2.71828182845904523536

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_tan(double x);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_pow(double base, double exp);
long double atan_teylor(double x);

#endif  // SRC_S21_MATH_H
