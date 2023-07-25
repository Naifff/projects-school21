#include "s21_string.h"

/**
 * @brief s21_strncmp - Сравнивает не более первых
 * @param n  байтов
 * @param str1 строка
 * и
 * @param str2 строка
 * @return возвращает результат
 */

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int flag = 0;
  while (n--) {
    if (*str1 != *str2) {
      flag = *str1 - *str2;
    } else {
      ++str1;
      ++str2;
    }
  }
  return flag;
}
