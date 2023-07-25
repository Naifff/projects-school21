#ifndef MY_STRING_S21_S21_DECIMAL_H
#define MY_STRING_S21_S21_DECIMAL_H

#include <math.h>
#include <stdio.h>
#include <string.h>

#include "s21_define.h"

// Arithmetic Operators
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
// 0 - OK, 1 - число слишком велико или равно бесконечности,
// 2 - число слишком мало или равно отрицательной бесконечности, 3 - деление на
// 0

// Comparison Operators
int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);

// Convertors and parsers
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
// 0 - OK
// 1 - ошибка конвертации

// Another functions
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
//  0 - OK
//  1 - ошибка вычисления

// Support
int s21_shift_bits_left(s21_decimal *value, const int num);
void s21_shift_bits_right(s21_decimal *value, const int num);
void s21_add_str(const char *val_1, const char *val_2, char *rez);
void s21_sub_str(const char *val_1, const char *val_2, char *rez);
void s21_toggle_bit(s21_decimal *value, const int num);
int s21_bit(const s21_decimal value, const int num);
int s21_scale(const s21_decimal value);
void s21_mul_two_to_decimal(const s21_decimal src, char *buffer);
void s21_div_decimal_to_two(s21_decimal *src, char *buffer);
void s21_bank_round_zero(char *buffer, int *buflen);
int s21_bank_round_nine(char *buffer, int *buflen, int val);
int s21_bank_round(char *buffer, int *buflen, int flag);
void s21_str_scale(s21_decimal *value_1, s21_decimal *value_2, char *val_1,
                   char *val_2);
int s21_shift_scale_str(char *buffer, const int num);
void s21_init(char *val);
int s21_test_zero(s21_decimal *val);
int s21_sum_bits(s21_decimal *value);
int s21_set_exp(s21_decimal *value, int num);
void s21_shift_str(char *str);
int s21_is_greater_or_equal_noexp(s21_decimal value_1, s21_decimal value_2);
int get_exp(int bits_3);
int get_bit(const s21_decimal dst, int bit);
int get_sign(s21_decimal value);
int s21_sub_logic(s21_decimal value_1, s21_decimal value_2,
                  s21_decimal *result);
s21_decimal s21_div_logic(s21_decimal value_1, s21_decimal value_2,
                          s21_decimal *result);
int s21_is_less_noexp(s21_decimal value_1, s21_decimal value_2);
int zeroing_dec(s21_decimal *value);

#endif  // MY_STRING_S21_S21_DECIMAL_H
