#include "s21_string.h"

/**
 * @brief s21_strncpy - Копирует до
 * @param n  символов
 * из строки, на которую указывает
 * @param src путь
 * в
 * @param dest путь
 * @return возвращает результат
 */

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  while (i < n) {
    dest[i] = '\0';
    i++;
  }
  return dest;
}
