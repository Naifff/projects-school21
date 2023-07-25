#include "s21_string.h"

/**
 * @brief s21_strncat - Добавляет строку, на которую указывает
 * @param src путь
 * в конец строки, на которую указывает
 * @param dest путь
 * @param n размер
 * @return возвращает указатель
 */

char *s21_strncat(char *dest, const char *src, s21_size_t count) {
  char *p = dest + s21_strlen(dest);
  while (*src != '\0' && count--) {
    *p++ = *src++;
  }
  *p = '\0';
  return dest;
}
