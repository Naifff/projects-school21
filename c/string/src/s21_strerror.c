#include "s21_string.h"

int amountNumber(unsigned long long int n) {
  int count = 0;
  do {
    n /= 10;
    count++;
  } while (n != 0);
  return count;
}

void int_to_string(int nb, char* str) {
  long n;
  int i = 0;
  n = nb;
  if (n < 0) {
    str[0] = '-';
    n = n * -1;
    i++;
  }
  i += amountNumber(n);
  str[i--] = '\0';
  while (n > 0) {
    str[i] = 48 + (n % 10);
    n = n / 10;
    i--;
  }
}

/**
 * @brief s21_strerror - Выполняет поиск во внутреннем массиве номера ошибки
 * @param errnum
 * и возвращает указатель на строку с сообщением об ошибке.
 * @return error
 */

char* s21_strerror(int errnum) {
  char* result_1 = s21_NULL;
  const char* s21_error[] = s21_errors;
  char str[4];
  int flag = 0;
  char* error = s21_NULL;
  if (errnum <= s21_N_error && errnum >= 0) {
    result_1 = (char*)s21_error[errnum];
    flag = 1;
  } else {
    static char result_2[42];
#if defined(__APPLE__) && defined(__MACH__)
    s21_strcpy(result_2, "Unknown error: ");
#elif defined(__linux__)
    s21_strcpy(result_2, "Unknown error ");
#endif
    int_to_string(errnum, str);
    s21_strcat(result_2, str);
    error = result_2;
  }
  return (flag == 1) ? result_1 : error;
}
