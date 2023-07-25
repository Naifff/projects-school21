#include "s21_sscanf.h"

/**
 * @brief get_str - посик строки
 * @param str_pattern паттерн
 * @param flags флаги
 * @param arg аргумент
 * @return возвращает паттерн
 */

const char* get_str(const char* str_pattern, int* flags, va_list arg) {
  char* temp_ptr = va_arg(arg, char*);
  while (str_arg_lid(*str_pattern) && flags[1] > 0) {
    *temp_ptr = *str_pattern;
    temp_ptr++;
    str_pattern++;
    flags[1]--;
  }
  *temp_ptr = '\0';
  return str_pattern;
}

/**
 * @brief get_arg_num - посик аргументов
 * @param flags флаги
 * @param str_pattern паттерн
 * @param amt значение
 * @param num номер
 * @param count_f счетчик
 * @param arg аргумент
 * @return возвращает паттерн
 */

const char* get_arg_num(int* flags, const char* str_pattern, int* amt, int num,
                        int* count_f, va_list arg) {
  unsigned int arg_l = 0;
  str_pattern = if_minus(flags, str_pattern);
  int flag_in = 0;
  int count = 0;
  if (arg_lid(num, str_pattern)) {
    while (arg_lid(num, str_pattern) && flags[1] > 0) {
      run_spec_o_etc(flags, str_pattern, &count, &flag_in);
      arg_l = arg_l * num + convert_calc(*str_pattern);
      str_pattern++;
    }
  } else {
    flags[2] = 0;
  }
  if ((flags[3] == 'x' || flags[3] == 'X') && count > 16) arg_l = -1;
  count_arg_riable(flag_in, count_f, flags, amt);
  if (flags[4]) arg_l *= -1;
  if (flags[2] && flags[0] == 0)
    *va_arg(arg, unsigned int*) = arg_l;
  else if (flags[2] && flags[0] == 1)
    *va_arg(arg, unsigned short int*) = (unsigned short int)arg_l;
  return str_pattern;
}

/**
 * @brief get_arg_long_num - посик длинных аргументов
 * @param flags флаги
 * @param str_pattern паттерн
 * @param amt значение
 * @param num номер
 * @param count_f счетчик
 * @param arg аргумент
 * @return возвращает паттерн
 */

const char* get_arg_long_num(int* flags, const char* str_pattern, int* amt,
                             int num, int* count_f, va_list arg) {
  unsigned short arg_l = 0;
  str_pattern = if_minus(flags, str_pattern);
  int flag_in = 0;
  int count = 0;
  if (arg_lid(num, str_pattern)) {
    while (arg_lid(num, str_pattern) && flags[1] > 0) {
      run_spec_o_etc(flags, str_pattern, &count, &flag_in);
      arg_l = arg_l * num + convert_calc(*str_pattern);
      str_pattern++;
    }
  } else {
    flags[2] = 0;
  }
  if ((flags[3] == 'x' || flags[3] == 'X') && count > 16) arg_l = -1;
  count_arg_riable(flag_in, count_f, flags, amt);
  if (flags[4]) arg_l *= -1;
  if (flags[2]) *va_arg(arg, unsigned long int*) = arg_l;
  return str_pattern;
}

/**
 * @brief get_arg_longlong - посик длинных длинных аргументов
 * @param flags флаги
 * @param str_pattern паттерн
 * @param amt значение
 * @param arg_l значение длинны
 * @param count_f счетчик
 * @return возвращает паттерн
 */

const char* get_arg_longlong(const char* str_pattern, int* flags,
                             long long* arg_l, int* amt, int* count_f) {
  long long unsigned tempUn = 0;
  str_pattern = if_minus(flags, str_pattern);
  int count = 0;
  if (arg_lid(10, str_pattern)) {
    while (arg_lid(10, str_pattern) && flags[1] > 0) {
      count = 1;
      tempUn = tempUn * 10 + (*str_pattern - 48);
      str_pattern++;
      flags[1]--;
      if (flags[3] == 'd' && tempUn > LLONG_MAX) {
        tempUn = LLONG_MAX;
        break;
      }
    }
  } else {
    flags[2] = 0;
  }
  *arg_l = tempUn;
  count_arg_riable(count, count_f, flags, amt);
  if (flags[4]) *arg_l *= -1;
  return str_pattern;
}

/**
 * @brief get_fraction_part - посик дробной части
 * @param str_pattern паттерн
 * @param flags флаги
 * @param arg_l значение длинны
 * @return возвращает паттерн
 */

const char* get_fraction_part(const char* str_pattern, int* flags,
                              long double* arg_l) {
  int count = 0;
  while ((*str_pattern >= '0' && *str_pattern <= '9') && flags[1] > 0) {
    count++;
    *arg_l = *arg_l + (*str_pattern - 48) / pow(10, count);
    str_pattern++;
    flags[1]--;
  }
  return str_pattern;
}

/**
 * @brief get_float - посик флоата
 * @param amt значение
 * @param str_pattern паттерн
 * @param flags флаги
 * @param count_f счетчик флагов
 * @param int_part значение целой части
 * @param fraction значение дробной части
 * @param exp значение экспоненты
 * @param plus_minus значение числа
 * @return возвращает паттерн
 */

const char* get_float(int* amt, const char* str_pattern, int* flags,
                      int* count_f, long long int* int_part,
                      long double* fraction, int* exp, int* plus_minus) {
  str_pattern = get_arg_longlong(str_pattern, flags, int_part, amt, count_f);
  if (flags[4]) *int_part *= -1;
  if (*str_pattern == '.') {
    flags[1]--;
    str_pattern++;
    str_pattern = get_fraction_part(str_pattern, flags, fraction);
  }
  if ((*str_pattern == 'e' || *str_pattern == 'E') && flags[1] > 1) {
    int flagNumber = 0, flagPlus = 0;
    flags[1]--;
    str_pattern++;
    flagNumber++;
    if (((*str_pattern == '-' || *str_pattern == '+') ||
         (*str_pattern >= '0' && *str_pattern <= '9')) &&
        flags[1] > 0) {
      if (*str_pattern == '-' || *str_pattern == '+') {
        *plus_minus = (*str_pattern == '-') ? 0 : 1;
        str_pattern++;
        flagPlus++;
        flagNumber++;
        flags[1]--;
      }
      *plus_minus = (*plus_minus == 0) ? 0 : 1;
      while ((*str_pattern >= '0' && *str_pattern <= '9') && flags[1] > 0) {
        if (flagPlus) flagNumber++;
        *exp = *exp * 10 + (*str_pattern - 48);
        str_pattern++;
        flags[1]--;
      }
    }
    if (flagNumber == 2 && flagPlus) {
      for (int i = 0; i < 2; i++) str_pattern--;
    }
  }
  return str_pattern;
}
