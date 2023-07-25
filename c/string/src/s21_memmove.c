#include "s21_string.h"

/**
 * @brief s21_memmove - Копирует n символов из
 * @param src путь
 * в
 * @param dest путь
 * @param n размер
 * @return возвращает указатель на папку
 */

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *pd = (char *)dest;
  const char *ps = (const char *)src;
  if (dest < src) {
    while (n-- > 0) {
      *pd++ = *ps++;
    }
  } else {
    pd = pd + n;
    ps = ps + n;
    while (n-- > 0) {
      *--pd = *--ps;
    }
  }
  return dest;
}
