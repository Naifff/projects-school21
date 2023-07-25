#include "s21_decimal.h"
#include "s21_define.h"

/**
 * @brief Сравнение двух чисел Decimal
 * @param value_1 первое число
 * @param value_2 второе число
 * @return int код ошибки
 */
int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  s21_decimal result;
  s21_sub(value_1, value_2, &result);
  return s21_bit(result, MAXBIT);
}

int s21_is_less_noexp(s21_decimal value_1, s21_decimal value_2) {
  int check = 0;
  for (int i = 95; i >= 0; i--) {
    int b1 = get_bit(value_1, i);
    int b2 = get_bit(value_2, i);
    if (b1 ^ b2) {
      if (b2) check = 1;
      break;
    }
  }
  return check;
}

/**
 * @brief Сравнение двух чисел Decimal
 * @param value_1 первое число
 * @param value_2 второе число
 * @return int код ошибки
 */
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return (s21_is_less(value_1, value_2) || s21_is_equal(value_1, value_2));
}

/**
 * @brief Сравнение двух чисел Decimal
 * @param value_1 первое число
 * @param value_2 второе число
 * @return int код ошибки
 */
int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  s21_decimal result;
  s21_sub(value_2, value_1, &result);
  return s21_bit(result, MAXBIT);
}

/**
 * @brief Сравнение двух чисел Decimal
 * @param value_1 первое число
 * @param value_2 второе число
 * @return int код ошибки
 */
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return (s21_is_greater(value_1, value_2) || s21_is_equal(value_1, value_2));
}

int s21_is_greater_or_equal_noexp(s21_decimal value_1, s21_decimal value_2) {
  return s21_is_less_noexp(value_1, value_2) ? 0 : 1;
}

/**
 * @brief Сравнение двух чисел Decimal
 * @param value_1 первое число
 * @param value_2 второе число
 * @return int код ошибки
 */
int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = FALSE;
  if (value_1.bits[LOW] == value_2.bits[LOW] &&
      value_1.bits[MIDDLE] == value_2.bits[MIDDLE] &&
      value_1.bits[HIGH] == value_2.bits[HIGH] &&
      value_1.bits[SCALE] == value_2.bits[SCALE])
    result = TRUE;
  return result;
}

/**
 * @brief Сравнение двух чисел Decimal
 * @param value_1 первое число
 * @param value_2 второе число
 * @return int код ошибки
 */
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = FALSE;
  if (s21_is_equal(value_1, value_2) == 0) result = TRUE;
  return result;
}
