#include "s21_decimal.h"
#include "s21_define.h"

const s21_decimal dec_null = {{0, 0, 0, 0}};

/**
 * @brief Получение значения бита
 * @param value структура
 * @param num порядковый номер нужного бита
 * @return int 0 или 1 бит
 */
int s21_bit(const s21_decimal value, const int num) {
  return (value.bits[num / SHFbit] >> (num % SHFbit)) & UNSINT;
}

/**
 * @brief Получение показателя степени от 0 до 28, который указывает степень 10
 * для разделения целого числа
 * @param value указатель на число децимал
 * @return int степень
 */
int s21_scale(const s21_decimal value) {
  return (char)(value.bits[SCALE] >> MAXSTP);
}

/**
 * @brief Переключение бита
 * @param value указатель на число децимал
 * @param num порядковый номер бита
 */
void s21_toggle_bit(s21_decimal *value, const int num) {
  value->bits[num / SHFbit] ^= UNSINT << num % SHFbit;
}

/**
 * @brief Приведение числа до нужной степени
 * @param buffer указатель на строку, в которой сохранено число
 * @param num разница между текущей степенью и нужной
 * @return int код ошибки
 */
int s21_shift_scale_str(char *buffer, const int num) {
  int rez = OK;
  if (num >= 0) {
    for (unsigned int j = 0; j < (strlen(buffer) - num); j++)
      buffer[j] = buffer[j + num], buffer[j + num] = '0';
  } else {
    for (int j = (int)strlen(buffer) - 1; j >= -num; j--)
      buffer[j] = buffer[j + num], buffer[j + num] = '0';
  }
  return rez;
}

/**
 * @brief Сложение двух чисел в десятичном виде, хранящееся в строке
 * @param value_1 первое слагаемое
 * @param value_2 второе слагаемое
 * @param result результат сложения
 */
void s21_add_str(const char *val_1, const char *val_2, char *rez) {
  for (int i = MAXSTR - 2, buf = 0; i >= 0; i--) {
    if (val_1[i] != '0' || val_2[i] != '0' || buf != 0) {
      int temp = (val_1[i] - '0') + buf + (val_2[i] - '0');
      buf = (temp >= 10) ? 1 : 0;
      if (temp >= 10) temp -= 10;
      rez[i] = temp + '0';
    }
  }
}

/**
 * @brief Вычитание двух чисел в десятичном виде, хранящееся в строке
 * @param value_1 первое число
 * @param value_2 второе число
 * @param result результат вычитания
 */
void s21_sub_str(const char *val_1, const char *val_2, char *rez) {
  for (int i = MAXSTR - 2, buf = 0; i >= 0; i--) {
    if (val_1[i] != '0' || val_2[i] != '0' || buf != 0) {
      int temp = (val_1[i] - '0') - buf - (val_2[i] - '0');
      buf = (temp < 0) ? 1 : 0;
      if (temp < 0) temp += 10;
      rez[i] = temp + '0';
    }
  }
}

/**
 * @brief Инициализация нулевого массива. Заполнение его нулями и ставит символ
 * конца строки в конце. str[99]='\0'
 * @param val массив символов
 */
void s21_init(char *val) {
  for (int i = 0; i < MAXSTR; i++) val[i] = i < (MAXSTR - 1) ? '0' : '\0';
}

/**
 * @brief Проверка, если число децимал равно нулю, то обнуляется степень и знак
 * @param val указатель на число децимал
 * @return int 1  =  0, 0 != 0
 */
int s21_test_zero(s21_decimal *val) {
  int rez = 0;
  if (val->bits[LOW] == 0 && val->bits[MIDDLE] == 0 && val->bits[HIGH] == 0)
    val->bits[SCALE] = 0, rez = 1;
  return rez;
}

/**
 * @brief Функция преобразует Decimal в десятичный вид в строку и выравнивает
 * показатели степени
 * @param value_1 первое число decimal
 * @param value_2 второе число decimal
 * @param val_1 первое число преобразованное в строку
 * @param val_2 второе число преобразованное в строку
 */
void s21_str_scale(s21_decimal *value_1, s21_decimal *value_2, char *val_1,
                   char *val_2) {
  s21_mul_two_to_decimal(*value_1, val_1);
  s21_mul_two_to_decimal(*value_2, val_2);
  int scale1 = s21_scale(*value_1), scale2 = s21_scale(*value_2);
  int scale = scale1 - scale2;
  if (scale > 0) {
    s21_shift_scale_str(val_2, scale);
    value_2->bits[SCALE] |= (s21_scale(*value_1) << MAXSTP);
  }
  if (scale < 0) {
    s21_shift_scale_str(val_1, -scale);
    value_1->bits[SCALE] |= (s21_scale(*value_2) << MAXSTP);
  }
}

/**
 * @brief Функция удаляет не значащие нули в начале строки и после запятой,
 * уменьшая степень
 * @param buffer строка с числом в десятичном виде
 * @param buflen показатель степени
 */
void s21_bank_round_zero(char *buffer, int *buflen) {
  int val_str = strlen(buffer) - 1;
  while ((*buflen) > 0 && val_str > 0 && buffer[val_str] == '0')
    val_str--, (*buflen)--;
  buffer[val_str + 1] = '\0';
  int i = 0;
  while (buffer[i] == '0' && buffer[i + 1] != '\0') i++;
  for (unsigned int j = 0; j < strlen(buffer) - i; j++)
    buffer[j] = buffer[j + i];
  buffer[strlen(buffer) - i] = '\0';
}

/**
 * @brief Функция округляет пока нужно девятку изменить на ноль
 * @param buffer строка с числом в десятичном виде
 * @param buflen показатель степени
 * @param val номер символа в строке, по который нужно обрезать
 */
int s21_bank_round_nine(char *buffer, int *buflen, int val) {
  buffer[val] = '\0';
  val--;
  int res = 0;
  while (buffer[val] == '9' && val > 0) buffer[val--] = '0';
  if (val == 0 && buffer[val] == '9') {
    buffer[0] = '0';
    for (int j = strlen(buffer); j >= 0; j--) buffer[j + 1] = buffer[j];
    buffer[0] = '1';
    res = s21_bank_round(buffer, buflen, 0);
  } else {
    buffer[val]++;
  }
  return res;
}

/**
 * @brief Функция банковского округления, попутно удаляет не значащие нули в
 * начале строки и после запятой, уменьшая степень
 * @param buffer строка с числом в десятичном виде
 * @param buflen показатель степени
 * @param flag 0-банковское огругление; 1-округление до 7 значащих цифр;
 * 2-простое округление
 * @return int код ошибки
 */
int s21_bank_round(char *buffer, int *buflen, int flag) {
  int rez = OK;
  s21_bank_round_zero(buffer, buflen);
  int val = strlen(buffer);
  if (val - *buflen <= MAXDEC && *buflen - val <= MAXEXP) {
    if (*buflen > MAXEXP) val -= *buflen - MAXEXP, *buflen = MAXEXP;
    if (val > MAXDEC) *buflen -= (val - MAXDEC), val = MAXDEC;
    if (val > 0 && *buflen >= 0) {
      if (flag == 1 && val > FLOAT_ROUND) {
        for (int j = FLOAT_ROUND + 1; j < (int)strlen(buffer); j++)
          buffer[j] = '0';
        flag = 0;
        *buflen =
            (*buflen - val + FLOAT_ROUND > 0) ? *buflen - val + FLOAT_ROUND : 0;
        val = FLOAT_ROUND;
        // flag=2; если все таки нужно простое округление на флоате
      }
      if (buffer[val] > '5' ||
          (buffer[val] == '5' &&
           ((buffer[val - 1] % 2 == 1 && flag == 0) || flag == 2))) {
        if (buffer[val - 1] == '9')
          rez = s21_bank_round_nine(buffer, buflen, val);
        else
          buffer[val - 1]++, buffer[val] = '0';
      }
      if (*buflen > 0 || val == MAXDEC) buffer[val] = '\0';
      s21_bank_round_zero(buffer, buflen);
    }
    if (*buflen <= 0 && !rez) {
      val -= *buflen, *buflen = 0;
      if (val > MAXDEC || (val == MAXDEC && strcmp(buffer, DEC_MAX) > 0))
        rez = INF;
    }
  } else {
    rez = val - *buflen > MAXDEC ? INF : NEGATIVE_INF;
  }
  if (rez) {
    buffer[0] = '0';
    buffer[1] = '\0';
    *buflen = 0;
  }
  return rez;
}

/**
 * @brief Функция деления десятичного числа на 2, для преобразования его в
 * двоичный код
 * @param dst указатель на число децимал для записи результата деления
 * @param buffer строка с десятичным числом
 */
void s21_div_decimal_to_two(s21_decimal *dst, char *buffer) {
  int binar = 0, bit = 0;
  while (strcspn(buffer, MAXLEN) != strlen(buffer)) {
    int binar_val = 0;
    for (unsigned int j = 0; j < strlen(buffer); j++) {
      int q = 0;
      if (binar_val == 1) q = 10;
      binar_val = ((buffer[j] - '0') + q) % 2;
      buffer[j] = (((buffer[j] - '0') + q) / 2) + '0';
    }
    if (binar == SHFbit) binar = 0, bit++;
    if (binar_val) s21_toggle_bit(dst, SHFbit * bit + binar);
    binar++;
  }
}

/**
 * @brief Функция умножения двоичного числа на 2, для преобразования его в
 * десятичное
 * @param src указатель на число децимал
 * @param buffer строка для сохранения десятичного числа
 */
void s21_mul_two_to_decimal(const s21_decimal src, char *buffer) {
  int bit = 2;
  for (int j = SHFbit; bit > -1; j--) {
    for (int i = MAXSTR - 2, one = 0; i > 0; i--) {
      int temp = (buffer[i] - '0') * 2 + one;
      one = (temp > 9) ? 1 : 0;
      if (temp > 9) temp -= 10;
      buffer[i] = temp + '0';
    }
    buffer[MAXSTR - 2] =
        ((buffer[MAXSTR - 2] - '0') + s21_bit(src, SHFbit * bit + j)) + '0';
    if (j == 0) j = SHFbit, bit--;
  }
}

/**
 * @brief Побитовый сдвиг вправо
 * @param value указатель на число децимал
 * @param num количество сдвигаемых битов

 */
void s21_shift_bits_right(s21_decimal *value, const int num) {
  for (int j = 0; j < num; j++) {
    value->bits[LOW] >>= 1;
    if (s21_bit(*value, SHFbit - 1) != s21_bit(*value, SHFbit))
      s21_toggle_bit(value, SHFbit - 1);
    value->bits[MIDDLE] >>= 1;
    if (s21_bit(*value, SHFBIT - 1) != s21_bit(*value, SHFBIT))
      s21_toggle_bit(value, SHFBIT);
    value->bits[HIGH] >>= 1;
    if (s21_bit(*value, BITVAL - 1)) s21_toggle_bit(value, BITVAL - 1);
  }
}

/**
 * @brief Побитовый сдвиг влево
 * @param value указатель на число децимал
 * @param num количество сдвигаемых битов
 * @return int код ошибки
 */
int s21_shift_bits_left(s21_decimal *value, const int num) {
  int rez = OK;
  for (int j = 0; j < num; j++) {
    value->bits[HIGH] <<= 1;
    if (s21_bit(*value, SHFBIT - 1) != s21_bit(*value, SHFBIT))
      s21_toggle_bit(value, SHFBIT);
    value->bits[MIDDLE] <<= 1;
    if (s21_bit(*value, SHFbit - 1) != s21_bit(*value, SHFbit))
      s21_toggle_bit(value, SHFbit);
    value->bits[LOW] <<= 1;
  }
  return rez;
}

/**
 * @brief Подсчет количества битов
 * @param value указатель на число децимал
 * @return int количество
 */
int s21_sum_bits(s21_decimal *value) {
  int end = 0;
  for (int i = BITVAL; i >= 0; i--) {
    if (s21_bit(*value, i) == 1) {
      end = i + 1;
      i = -1;
    }
  }
  return end;
}

/**
 * @brief умножение числа на 10
 * @param str указатель на строку, в которой сохранено число
 */
void s21_shift_str(char *str) {
  for (size_t i = 0; i < strlen(str); i++) str[i] = str[i + 1];
  str[strlen(str)] = '0';
}

/**
 * @brief Инициализация нулевого массива.
 * @param value массив символов
 */
int zeroing_dec(s21_decimal *value) {
  value->bits[0] = 0;
  value->bits[1] = 0;
  value->bits[2] = 0;
  return 0;
}

/**
 * @brief устанавливает степень числа децимал
 * @param value указатель на число децимал
 * @param exp степень
 * @return int код ошибки
 */
int s21_set_exp(s21_decimal *value, int exp) {
  int flag = TRUE, sign = s21_bit(*value, MAXBIT);
  if (exp >= 0 && exp <= MAXEXP) {
    value->bits[SCALE] = exp;
    value->bits[SCALE] <<= MAXSTP;
    if (sign == 1) s21_toggle_bit(value, MAXBIT);
  } else {
    flag = FALSE;
  }
  return flag;
}

int get_exp(int bits_3) {
  int exp = 0;
  for (int i = 23; i >= 16; i--) {
    int b1 = (bits_3 >> i) & 1;
    exp <<= 1;
    exp |= b1;
  }
  return exp;
}

int get_bit(const s21_decimal dst, int bit) {
  int res = 0;
  if (bit / 32 < 4) {
    unsigned int mask = 1u << (bit % 32);
    res = dst.bits[bit / 32] & mask;
  }
  return !!res;
}

int get_sign(s21_decimal value) {
  int sign = (value.bits[3] >> 31) & 1;
  if ((value.bits[0] | value.bits[1] | value.bits[2]) == 0) sign = 0;
  return sign;
}

int s21_sub_logic(s21_decimal value_1, s21_decimal value_2,
                  s21_decimal *result) {
  *result = (s21_decimal){0};
  int kel = 0, kel1 = 0;
  for (int i = 0; i < 95; i++) {
    int bit1 = get_bit(value_1, i);
    int bit2 = get_bit(value_2, i);
    if ((bit1 == 0) && kel) kel1 = 1;
    if (bit1 < bit2) kel = 1;
    if (bit1 && kel) {
      bit1 = 0, kel = 0, kel1 = 0;
    }
    if (bit1 < bit2) kel = 1;
    if (bit1 < kel) {
      if (kel1) {
        bit1 = 1;
      } else {
        bit1 = 0;
      }
    }
    result->bits[i / 32 % 4] |= (bit1 ^ bit2) ? 1 << i : 0 << i;
  }
  return 0;
}

s21_decimal s21_div_logic(s21_decimal value_1, s21_decimal value_2,
                          s21_decimal *result) {
  s21_decimal mod = {0};
  zeroing_dec(result);
  for (int i = 95; i >= 0; i--) {
    s21_shift_bits_left(&mod, 1);
    s21_shift_bits_left(result, 1);
    mod.bits[0] |= get_bit(value_1, i);
    if (s21_is_greater_or_equal_noexp(mod, value_2)) {
      s21_sub_logic(mod, value_2, &mod);
      result->bits[0] |= 1;
    }
  }
  return mod;
}
