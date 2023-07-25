#include "s21_string.h"

/**
 * @brief s21_strcat - Добавляет строку, на которую указывает
 * @param src путь
 * в конец строки, на которую указывает
 * @param dest путь
 * @return возвращает указатель на строку в dest
 */

char *s21_strcat(char *dest, const char *src) {
  char *flag;
  char *strr = dest;
  while (*strr != '\0') {
    strr++;
  }
  while (*src != '\0') {
    *strr++ = *src++;
  }
  *strr = '\0';
  flag = dest;
  return flag;
}
