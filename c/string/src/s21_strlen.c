#include "s21_string.h"

/**
 * @brief s21_strlen - Вычисляет длину строки
 * @param str  символов
 * не включая завершающий нулевой символ.
 * @return возвращает длину
 */

s21_size_t s21_strlen(const char *str) {
  s21_size_t size = 0;
  while (str[size]) {
    ++size;
  }
  return size;
}
