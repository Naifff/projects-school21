#include "s21_string.h"

/**
 * @brief s21_strstr - Находит первое вхождение всей строки
 * @param needle строка
 * не включая завершающий нулевой символ), которая появляется в строке
 * @param haystack строка
 * @return возвращает результат
 */

char* s21_strstr(const char* haystack, const char* needle) {
  char* p = (char*)haystack;
  int size = s21_strlen(needle);
  int flag = 1;
  char* res = s21_NULL;
  while (*p != '\0' && flag == 1) {
    if (s21_strncmp(p, needle, size) == 0) {
      flag = 0;
      res = p;
    } else {
      p++;
    }
  }
  return res;
}
