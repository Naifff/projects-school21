#include "s21_decimal.h"
#include "s21_define.h"

/**
 * @brief умножение указанного Decimal на -1
 * @param value число Decimal
 * @param result результат умножения
 * @return int код ошибки
 */
int s21_negate(s21_decimal value, s21_decimal *result) {
  int flag = OK;
  if (s21_scale(value) > MAXEXP) {
    flag = error;
  } else {
    *result = value;
    s21_toggle_bit(result, MAXBIT);
  }
  return flag;
}

/**
 * @brief округление Decimal до ближайшего целого числа
 * @param value число Decimal
 * @param result результат округления
 * @return int код ошибки
 */
int s21_round(s21_decimal value, s21_decimal *result) {
  int flag = OK;
  if (s21_scale(value) > MAXEXP) {
    flag = error;
  } else {
    *result = DECIMAL_ZERO;
    if (s21_scale(value) > 0) {
      int sign = 0;
      if (s21_bit(value, MAXBIT) == 1) {
        sign = 1;
        s21_toggle_bit(&value, MAXBIT);
      }
      s21_set_exp(&value, s21_scale(value) - 1);
      s21_truncate(value, result);
      char res[MAXSTR] = {0};
      s21_init(res);
      s21_mul_two_to_decimal(*result, res);
      s21_decimal tmp = *result, one = {{1, 0, 0, 0}};

      *result = DECIMAL_ZERO;
      s21_set_exp(&tmp, 1);
      s21_truncate(tmp, result);
      char tmp_str[MAXSTR] = {0};
      s21_mul_two_to_decimal(*result, tmp_str);
      if ((strcmp(res, STR_0) != 0) && (sign == 1)) {
        s21_toggle_bit(result, MAXBIT);
        s21_toggle_bit(&one, MAXBIT);
      }
      if (res[strlen(res) - 1] >= 53) {
        tmp = *result;
        s21_add(tmp, one, result);
      }
    } else {
      *result = value;
    }
  }
  return flag;
}

/**
 * @brief Возвращает целые цифры указанного Decimal числа
 * @param value число Decimal
 * @param result результат округления
 * @return int код ошибки
 */
int s21_truncate(s21_decimal value, s21_decimal *result) {
  int flag = OK;
  if (s21_scale(value) > MAXEXP) {
    flag = error;
  } else {
    *result = DECIMAL_ZERO;
    if (s21_scale(value) > 0) {
      int sign = 0;
      char res[MAXSTR] = {0};
      s21_init(res);
      s21_mul_two_to_decimal(value, res);
      s21_shift_scale_str(res, -s21_scale(value));
      if (strcmp(res, STR_0) != 0 && s21_bit(value, MAXBIT) == 1) sign = 1;
      s21_div_decimal_to_two(result, res);
      if (sign == 1) result->bits[SCALE] = MINUS;
    } else {
      *result = value;
    }
  }
  return flag;
}

/**
 * @brief Округляет указанное Decimal число до ближайшего целого числа
 * в сторону отрицательной бесконечности.
 * @param value число Decimal
 * @param result результат округления
 * @return int код ошибки
 */
int s21_floor(s21_decimal value, s21_decimal *result) {
  int flag = OK;
  if (s21_scale(value) > MAXEXP) {
    flag = error;
  } else {
    s21_decimal tmp = {{1, 0, 0, 0}};
    s21_truncate(value, result);
    if (s21_bit(value, MAXBIT) == 1) s21_sub(*result, tmp, result);
  }
  return flag;
}
