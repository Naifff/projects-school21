#include "s21_decimal.h"
#include "s21_define.h"

/**
 * @brief Сложение двух чисел Decimal
 * @param value_1 первое слагаемое
 * @param value_2 второе слагаемое
 * @param result результат сложения
 * @return int код ошибки
 */
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int ret = OK;
  s21_decimal temp_res;
  temp_res.bits[LOW] = temp_res.bits[MIDDLE] = temp_res.bits[HIGH] =
      temp_res.bits[SCALE] = 0;
  int sign1 = s21_bit(value_1, MAXBIT);
  int sign2 = s21_bit(value_2, MAXBIT);
  if (sign1 && sign2) {
    s21_toggle_bit(&temp_res, MAXBIT);
  } else {
    if (sign1 > sign2) {
      s21_toggle_bit(&value_1, MAXBIT);
      ret = s21_sub(value_2, value_1, &temp_res);
    } else {
      if (sign1 < sign2) {
        s21_toggle_bit(&value_2, MAXBIT);
        ret = s21_sub(value_1, value_2, &temp_res);
      }
    }
  }
  if (sign1 == sign2 && !ret) {
    char val_1[MAXSTR], val_2[MAXSTR], rez[MAXSTR];
    s21_init(val_1), s21_init(val_2), s21_init(rez);
    s21_str_scale(&value_1, &value_2, val_1, val_2);
    s21_add_str(val_1, val_2, rez);
    int max_scale = s21_scale(value_1);
    ret = s21_bank_round(rez, &max_scale, 0);
    if (!ret) {
      temp_res.bits[SCALE] ^= (max_scale << MAXSTP);
      s21_div_decimal_to_two(&temp_res, rez);
      s21_test_zero(&temp_res);
    }
    if (ret == 1) ret = (s21_bit(value_1, MAXBIT)) ? NEGATIVE_INF : INF;
  }
  *result = temp_res;
  return ret;
}

/**
 * @brief Вычитание чисел Decimal
 * @param value_1 первое число
 * @param value_2 второе число
 * @param result результат вычитания
 * @return int  код ошибки
 */
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int ret = OK;
  s21_decimal temp_res;
  temp_res.bits[LOW] = temp_res.bits[MIDDLE] = temp_res.bits[HIGH] =
      temp_res.bits[SCALE] = 0;
  int sign1 = s21_bit(value_1, MAXBIT);
  int sign2 = s21_bit(value_2, MAXBIT);
  if (sign1 != sign2) {
    if (sign1)
      s21_toggle_bit(&value_1, MAXBIT);
    else
      s21_toggle_bit(&value_2, MAXBIT);
    ret = s21_add(value_1, value_2, &temp_res);
    if (sign1) s21_toggle_bit(&temp_res, MAXBIT);
  } else {
    char val_1[MAXSTR], val_2[MAXSTR];
    s21_init(val_1), s21_init(val_2);
    s21_str_scale(&value_1, &value_2, val_1, val_2);
    char rez[MAXSTR];
    s21_init(rez);
    if (strcmp(val_1, val_2) >= 0) {
      if (sign1) s21_toggle_bit(&temp_res, MAXBIT);
      s21_sub_str(val_1, val_2, rez);

    } else {
      if (!sign1) s21_toggle_bit(&temp_res, MAXBIT);
      s21_sub_str(val_2, val_1, rez);
    }
    int max_scale = s21_scale(value_1);
    ret = s21_bank_round(rez, &max_scale, 0);
    if (!ret) {
      temp_res.bits[SCALE] ^= (max_scale << MAXSTP);
      s21_div_decimal_to_two(&temp_res, rez);
      s21_test_zero(&temp_res);
    }
  }
  if (ret == 1)
    ret = (s21_bit(temp_res, MAXBIT)) ? NEGATIVE_INF : INF;
  else
    s21_test_zero(&temp_res);

  *result = temp_res;

  return ret;
}

/**
 * @brief Умножение двух чисел Decimal
 * @param value_1 первой множитель
 * @param value_2 второй множитель
 * @param result результат умножения
 * @return int  код ошибки
 */
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int flag = OK;
  char str_1[MAXSTRs] = {0}, str_2[MAXSTR] = {0}, res[MAXSTR] = {0};
  int exp_res = s21_scale(value_1) + s21_scale(value_2);
  s21_init(str_1);
  s21_init(str_2);
  s21_init(res);
  s21_mul_two_to_decimal(value_1, str_1);
  s21_mul_two_to_decimal(value_2, str_2);
  for (int i = strlen(str_2); i > 0; i--) {
    for (int j = str_2[i - 1] - 48; j > 0; j--) s21_add_str(res, str_1, res);
    s21_shift_str(str_1);
  }
  if (s21_bank_round(res, &exp_res, 0) == 1) {
    flag = INF;
  } else {
    *result = DECIMAL_ZERO;
    s21_div_decimal_to_two(result, res);
    s21_set_exp(result, exp_res);
  }
  if ((s21_bit(value_2, MAXBIT) ^ s21_bit(value_1, MAXBIT)) == 1) {
    if (flag == INF)
      flag = NEGATIVE_INF;
    else
      s21_toggle_bit(result, MAXBIT);
  }
  return flag;
}

/**
 * @brief Деление двух чисел Decimal
 * @param value_1 первой делитель
 * @param value_2 второй делитель
 * @param result результат деления
 * @return int  код ошибки
 */

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int div_res = 0;
  if (result) {
    float num1, num2, res;
    s21_from_decimal_to_float(value_1, &num1);
    s21_from_decimal_to_float(value_2, &num2);
    res = num1 / num2;
    if (res == NAN) {  // nan
      div_res = 3;
    } else if (res == (INFin)) {  // +inf
      div_res = 1;
    } else if (res == (mINFin)) {  // -inf
      div_res = 2;
    } else {
      s21_from_float_to_decimal(res, result);
    }
  }
  return div_res;
}

/**
 * @brief Процент от остаткадвух чисел Decimal
 * @param value_1 первой делитель
 * @param value_2 второй делитель
 * @param result результат деления
 * @return int код ошибки
 */

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  s21_decimal div_res;
  if (s21_div(value_1, value_2, &div_res) == 0 && result) {
    s21_truncate(div_res, &div_res);
    s21_mul(div_res, value_2, &div_res);
    s21_sub(value_1, div_res, result);
  } else {
    res = 1;
  }
  return res;
}
