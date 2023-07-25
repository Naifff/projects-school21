#include "s21_string.h"

/**
 * @brief s21_to_upper -  Возвращает копию строки
 * @param str строка
 * преобразованной в верхний регистр.
 * В случае какой-либо ошибки следует вернуть значение NULL
 * @return возвращает результат
 */

void* s21_to_upper(const char* str) {
  char* res = NULL;
  if (str) {
    res = (char*)malloc((s21_strlen(str) + 1) * sizeof(char));
    if (res != NULL) {
      s21_strcpy(res, str);
      for (char* tmp_str = res; *tmp_str; tmp_str++) {
        if (*tmp_str >= 'a' && *tmp_str <= 'z') {
          *tmp_str -= 32;
        }
      }
    }
  }
  return res;
}
