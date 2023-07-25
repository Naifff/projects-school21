#include "s21_string.h"

/**
 * @brief s21_memcpy - Копирует
 * @param n размер
 * из
 * @param src путь
 * в
 * @param dest путь
 * @return возвращает указатель
 */

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  s21_size_t i = 0;
  char *char_dest = (char *)dest;
  char *char_src = (char *)src;
  for (i = 0; i < n; i++) {
    char_dest[i] = char_src[i];
  }
  return dest;
}
