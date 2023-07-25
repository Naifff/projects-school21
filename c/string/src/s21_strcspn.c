#include "s21_string.h"

/**
 * @brief s21_strcspn - Вычисляет длину начального сегмента
 * @param str1  строки
 * который полностью состоит из символов, не входящих в
 * @param str2 строку
 * @return возвращает длинну
 */

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i = 0;
  while (str1[i] && !s21_strchr(str2, str1[i])) i++;
  return i;
}
