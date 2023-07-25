#include "s21_string.h"

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.

/**
 * @brief s21_strchr - Выполняет поиск первого вхождения символа
 * @param с (беззнаковый тип)
 * в строке, на которую указывает
 * @param str аргумент строки
 * @return возвращает аргумент
 */

char *s21_strchr(const char *str, int c) {
  char *s = (char *)str;
  unsigned char b = (char)c;
  char *res;
  while (*s != '\0' && *s != b) {
    s++;
  }
  if (*s == '\0' && b != '\0') {
    res = s21_NULL;
  } else {
    res = s;
  }
  return res;
}
