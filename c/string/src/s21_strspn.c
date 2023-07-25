#include "s21_string.h"

/**
 * @brief s21_strspn - Вычисляет длину начального сегмента
 * @param str1
 * который полностью состоит из символов
 * @param str2
 * @return возвращает длину
 */

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t i = 0;
  while (str1[i] && s21_strchr(str2, str1[i])) i++;
  return i;
}
