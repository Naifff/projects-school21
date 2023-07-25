#include "s21_string.h"

/**
 * @brief s21_memset - Копирует символ
 * @param c (беззнаковый тип)
 * в первые
 * @param n символов строки
 * @param str аргумент строки
 * @return возвращает указатель на строку
 */

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *p = str;
  while (n > 0) {
    *p = c;
    p++;
    n--;
  }
  return (str);
}
