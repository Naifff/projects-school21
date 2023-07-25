#include "s21_string.h"

/**
 * @brief s21_strrchr - Выполняет поиск последнего вхождения символа
 * @param c (беззнаковый тип)
 * в строке, на которую указывает аргумент
 * @param str аргумент
 * @return возвращает результат
 */

char *s21_strrchr(const char *str, int c) {
  const char *res = s21_NULL;
  if (str != s21_NULL) {
    do {
      if (*str == (char)c) {
        res = str;
      }
    } while (*str++);
  }
  return (char *)res;
}
