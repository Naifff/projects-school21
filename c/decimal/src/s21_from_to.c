#include "s21_decimal.h"
#include "s21_define.h"

/**
 * @brief Подсчет количества битов
 * @param dst указатель на число децимал
 * @param src десятичное целое число
 * @return int код ошибки
 */

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  enum error error_status;
  error_status = ok;
  for (int i = 0; i <= 3; i++) {
    dst->bits[i] = 0;
  }
  if (src < 0) {
    src = -src;
    dst->bits[SCALE] = 1;
    dst->bits[SCALE] = dst->bits[SCALE] << (SHFbit - 1);
  }
  dst->bits[LOW] = src;
  if (dst->bits[LOW] != src) {
    error_status = error;
  }
  return error_status;
}
/**
 * @brief Функция преобразования из типа float в тип Decimal
 * @param src исходное число float
 * @param dst указатель на число decimal, в которое сохраняем результат
 * @return int код ошибки
 */
int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int rezult = OK;
  dst->bits[LOW] = dst->bits[MIDDLE] = dst->bits[HIGH] = dst->bits[SCALE] = 0;
  if (fabs(src) < FLOAT_MIN || isnan(src) || isinf(src)) {
    rezult = error;
  } else {
    int fl = 0;
    memcpy(&fl, &src, sizeof(UNSINT));
    if ((fl >> (SHFbit - 1)) & UNSINT) s21_toggle_bit(dst, MAXBIT);
    int exp = (int)((unsigned char)(fl >> MINFLT)) - MAXBIT;
    float mantisa = 1.0;
    if (exp == -MAXBIT) mantisa = 0.0, exp += MAXBIT;
    for (int i = (MINFLT - 1); i >= 0; i--)
      if ((fl >> i) & UNSINT) mantisa += pow(2, -(MINFLT - i));
    mantisa *= pow(2, exp);
    char buffer[MAXSTR];
    s21_init(buffer);
    snprintf(buffer, MAXSTR, MAXFLT, mantisa);
    int val = strlen(buffer) - 1;
    char *ach;
    ach = strchr(buffer, '.');
    if (ach != NULL) {  // считаем коэффициент масштабирования
      int buflen = 0;
      buflen = ach - buffer + 1;
      for (unsigned int j = buflen - 1; j < strlen(buffer); j++)
        buffer[j] = buffer[j + 1];
      buflen = strlen(buffer) - buflen + 1;
      buffer[val--] = '\0';
      rezult = s21_bank_round(buffer, &buflen, 1);
      if (buflen) dst->bits[SCALE] ^= (buflen << MAXSTP);
    }
    s21_div_decimal_to_two(dst, buffer);
  }
  return rezult;
}

/**
 * @brief Функция преобразование из типа Decimal в тип Float
 * @param src число Decimal, которое нужно преобразовать
 * @param dst указатель на число float, куда сохранить результат
 * преобразования
 * @return int код ошибки
 */

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int res = 0;
  if (!dst || get_exp(src.bits[3]) > 28) {
    res = 1;
  } else {
    *dst = 0.0;
    int scale = get_exp(src.bits[3]);
    int sign = get_bit(src, 127);
    double tmp = *dst;
    unsigned long base = 1;
    for (int i = 0; i < 96; i++) {
      tmp += get_bit(src, i) * base;
      base = base * 2;
    }
    while (scale != 0) {
      tmp = tmp / 10;
      scale--;
    }
    if (sign) tmp *= -1;
    *dst = tmp;
  }
  return res;
}

/**
 * @brief Из децимал в int
 * @param dst указатель на десятичное целое число
 * @param src число децимал
 * @return int код ошибки
 */

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  *dst = 0;
  int error = 0;
  int sign = get_sign(src);
  int exp = get_exp(src.bits[3]);
  while (exp) {
    s21_div_logic(src, (s21_decimal){{10, 0, 0, 0}}, &src);
    exp--;
  }
  if (src.bits[1] == 0 && src.bits[2] == 0 && src.bits[0] <= INT_MAX) {
    *dst = src.bits[0];
    if (sign == 1) *dst = -*dst;
  } else {
    error = 1;
  }
  return error;
}
