#include "s21_sscanf.h"

/**
 * @brief init_spec - считывает спецификатор
 * @param amt значение
 * @param str_pattern паттерн
 * @param flags флаг
 * @param arg аргументы
 * @param count_f счетчик флагов
 * @return возвращает паттерн
 */

const char* init_spec(int* amt, const char* str_pattern, int* flags,
                      va_list arg, int* count_f) {
  if (flags[3] == 'd' || flags[3] == 'u') {
    str_pattern = spec_d_u(amt, str_pattern, flags, arg, count_f);
  } else if (flags[3] == 'i') {
    str_pattern = spec_i(amt, str_pattern, flags, arg, count_f);
  } else if (flags[3] == 'f' || flags[3] == 'e' || flags[3] == 'E' ||
             flags[3] == 'g' || flags[3] == 'G') {
    str_pattern = spec_f_etc(amt, str_pattern, flags, arg, count_f);
  } else if (flags[3] == 'c') {
    str_pattern = spec_c(amt, str_pattern, flags, arg, count_f);
  } else if (flags[3] == 's') {
    str_pattern = spec_s(amt, str_pattern, flags, arg, count_f);
  } else if (flags[3] == 'o') {
    str_pattern = spec_o_etc(amt, str_pattern, flags, arg, count_f);
  } else if (flags[3] == 'p') {
    str_pattern = spec_p(amt, str_pattern, flags, arg, count_f);
  } else if (flags[3] == '%') {
    str_pattern = spec_percent(str_pattern, count_f);
  } else if (flags[3] == 'x' || flags[3] == 'X') {
    str_pattern = spec_o_etc(amt, str_pattern, flags, arg, count_f);
  }
  return str_pattern;
}

/**
 * @brief spec_c - Спецификатор символ
 * @param amt значение
 * @param str_pattern паттерн
 * @param flags флаг
 * @param arg аргументы
 * @param count_f счетчик флагов
 * @return возвращает паттерн
 */

const char* spec_c(int* amt, const char* str_pattern, const int* flags,
                   va_list arg, int* count_f) {
  if (flags[2] && *str_pattern != '\0') {
    if (flags[0] == 3)
      *va_arg(arg, wchar_t*) = *str_pattern;
    else
      *va_arg(arg, char*) = *str_pattern;
    *amt = *count_f ? *amt + 1 : *amt;
  }
  str_pattern++;
  return str_pattern;
}

/**
 * @brief spec_s - Спецификатор строка символов
 * @param amt значение
 * @param str_pattern паттерн
 * @param flags флаг
 * @param arg аргументы
 * @param count_f счетчик флагов
 * @return возвращает паттерн
 */

const char* spec_s(int* amt, const char* str_pattern, int* flags, va_list arg,
                   int* count_f) {
  if (flags[2] && str_arg_lid(*str_pattern)) {
    str_pattern = get_str(str_pattern, flags, arg);
    *amt = *count_f ? *amt + 1 : *amt;
  } else {
    while (*str_pattern != ' ') str_pattern++;
  }
  return str_pattern;
}

/**
 * @brief spec_o_etc - Беззнаковое восьмеричное число и другие
 * @param amt значение
 * @param str_pattern паттерн
 * @param flags флаг
 * @param arg аргументы
 * @param count_f счетчик флагов
 * @return возвращает паттерн
 */

const char* spec_o_etc(int* amt, const char* str_pattern, int* flags,
                       va_list arg, int* count_f) {
  if (flags[3] == 'o') {
    if (flags[0] == 1 || flags[0] == 0)
      str_pattern = get_arg_num(flags, str_pattern, amt, 8, count_f, arg);
    else
      str_pattern = get_arg_long_num(flags, str_pattern, amt, 8, count_f, arg);
  } else {
    if (flags[0] == 1 || flags[0] == 0)
      str_pattern = get_arg_num(flags, str_pattern, amt, 16, count_f, arg);
    else
      str_pattern = get_arg_long_num(flags, str_pattern, amt, 16, count_f, arg);
  }
  return str_pattern;
}

/**
 * @brief spec_d_u - Беззнаковое/Знаковое десятичное целое число
 * @param amt значение
 * @param str_pattern паттерн
 * @param flags флаг
 * @param arg аргументы
 * @param count_f счетчик флагов
 * @return возвращает паттерн
 */

const char* spec_d_u(int* amt, const char* str_pattern, int* flags, va_list arg,
                     int* count_f) {
  long long arg_l = 0;
  str_pattern = get_arg_longlong(str_pattern, flags, &arg_l, amt, count_f);
  if (flags[2]) {
    if (flags[3] == 'd') {
      if (flags[0] == 3) {
        *va_arg(arg, long int*) = (long)arg_l;
      } else if (flags[0] == 4 || (flags[0] == 2)) {
        *va_arg(arg, long long int*) = arg_l;
      } else if (flags[0] == 1) {
        *va_arg(arg, short*) = (short)arg_l;
      } else {
        *va_arg(arg, int*) = (int)arg_l;
      }
    } else if (flags[3] == 'u') {
      if (flags[0] == 3) {
        *va_arg(arg, long unsigned*) = (long unsigned)arg_l;
      } else if (flags[0] == 4 || (flags[0] == 2)) {
        *va_arg(arg, long long unsigned*) = arg_l;
      } else if (flags[0] == 1) {
        *va_arg(arg, unsigned short*) = (unsigned short)arg_l;
      } else {
        *va_arg(arg, unsigned int*) = (unsigned int)arg_l;
      }
    }
  }
  return str_pattern;
}

/**
 * @brief spec_i - Знаковое десятичное целое число
 * @param amt значение
 * @param str_pattern паттерн
 * @param flags флаг
 * @param arg аргументы
 * @param count_f счетчик флагов
 * @return возвращает паттерн
 */

const char* spec_i(int* amt, const char* str_pattern, int* flags, va_list arg,
                   int* count_f) {
  str_pattern = if_minus(flags, str_pattern);
  if (*str_pattern == '0') {
    str_pattern++;
    if (*str_pattern == 'x' || *str_pattern == 'X') {
      flags[3] = 'x';
    } else {
      str_pattern--;
      flags[3] = 'o';
    }
    str_pattern = spec_o_etc(amt, str_pattern, flags, arg, count_f);
  } else {
    flags[3] = 'd';
    str_pattern = spec_d_u(amt, str_pattern, flags, arg, count_f);
  }
  return str_pattern;
}

/**
 * @brief spec_f_etc - Десятичное число с плавающей точкой и другие
 * @param amt значение
 * @param str_pattern паттерн
 * @param flags флаг
 * @param arg аргументы
 * @param count_f счетчик флагов
 * @return возвращает паттерн
 */

const char* spec_f_etc(int* amt, const char* str_pattern, int* flags,
                       va_list arg, int* count_f) {
  long long int int_part = 0;
  long double fraction = 0;
  int exp = 0, plus_minus = -1;  // 1 + 0 -
  str_pattern = get_float(amt, str_pattern, flags, count_f, &int_part,
                          &fraction, &exp, &plus_minus);
  double arg_l = (int_part + fraction);
  if (plus_minus != -1) {
    exp = (plus_minus == 1) ? exp : exp * (-1);
    arg_l *= pow(10, exp);
  }
  if (flags[4]) arg_l *= -1;
  if (flags[2]) {
    if (flags[0] == 3) {
      *va_arg(arg, double*) = (double)arg_l;
    } else if (flags[0] == 2) {
      *va_arg(arg, long double*) = (long double)arg_l;
    } else {
      *va_arg(arg, float*) = (float)arg_l;
    }
  }
  return str_pattern;
}

/**
 * @brief spec_p - Адрес указателя
 * @param amt значение
 * @param str_pattern паттерн
 * @param flags флаг
 * @param arg аргументы
 * @param count_f счетчик флагов
 * @return возвращает паттерн
 */

const char* spec_p(int* amt, const char* str_pattern, int* flags, va_list arg,
                   int* count_f) {
  void** path = va_arg(arg, void**);
  long adres = 0;
  int point = 1;
  if (arg_lid(16, str_pattern)) {
    while (arg_lid(16, str_pattern) && flags[1] > 0) {
      point = 0;
      adres = adres * 16 + convert_calc(*str_pattern);
      str_pattern++;
      flags[1]--;
    }
  } else {
    flags[2] = 0;
  }
  if (flags[2]) {
    if (point)
      *path = &path;
    else
      *path = (void*)adres;
    *amt = *count_f ? *amt + 1 : *amt;
  }
  return str_pattern;
}

/**
 * @brief spec_percent - Символ %
 * @param str_pattern паттерн
 * @param count_f счетчик флагов
 * @return возвращает паттерн
 */

const char* spec_percent(const char* str_pattern, int* count_f) {
  if (*str_pattern == '%') {
    str_pattern++;
  } else {
    *count_f = 0;
  }
  return str_pattern;
}

/**
 * @brief spec_width - Ширина
 * @param format_pattern формат
 * @param flags флаг
 * @return возвращает формат паттерна
 */

const char* spec_width(const char* format_pattern, int* flags) {
  int res = 0;
  if (*format_pattern == '*') {
    format_pattern++;
    flags[2] = 0;
  } else if (*format_pattern >= '0' && *format_pattern <= '9') {
    while (*format_pattern >= '0' && *format_pattern <= '9') {
      res = res * 10 + (*format_pattern - 48);
      format_pattern++;
    }
    flags[1] = res;
  }
  return format_pattern;
}

/**
 * @brief run_spec_o_etc - запуск беззнакового восьмеричного числа
 * @param flags флаг
 * @param str_pattern паттерн
 * @param count счетчки
 * @param flag_in движение флага
 */

void run_spec_o_etc(int* flags, const char* str_pattern, int* count,
                    int* flag_in) {
  if ((*count == 0 && *str_pattern == '0') ||
      (*count == 0 && (*str_pattern == 'x' || *str_pattern == 'X')))
    *count = 0;
  else
    *count += 1;
  *flag_in = 1;
  flags[1]--;
}

/**
 * @brief search_flags_len - Поиск длинны
 * @param flags флаг
 * @param format_pattern формат
 * @return возвращает формат паттерна
 */

const char* search_flags_len(int* flags, const char* format_pattern) {
  while (*format_pattern) {
    if (*format_pattern == 'h' && !flags[0]) {
      flags[0] = 1;
      format_pattern++;
    } else if (*format_pattern == 'L' && !flags[0]) {
      flags[0] = 2;
      format_pattern++;
    } else if (*format_pattern == 'l') {
      if (flags[0] == 3) {
        flags[0] = 4;
      } else if (flags[0] == 0) {
        flags[0] = 3;
      }
      format_pattern++;
    } else if ((*format_pattern >= '0' && *format_pattern <= '9') ||
               (*format_pattern == '*')) {
      format_pattern = spec_width(format_pattern, flags);
    } else if (s21_strchr("difcsueEgGxXonp%", *format_pattern) != NULL) {
      flags[3] = *format_pattern++;
      break;
    }
  }
  if (!flags[1]) flags[1] = 512;
  return format_pattern;
}

/**
 * @brief parser_spec - Поиск спецификаторов
 * @param str строка
 * @param format формат
 * @param arg аргумент
 * @return возвращает значение
 */

int parser_spec(const char* str, const char* format, va_list arg) {
  const char* str_pattern = str;
  const char* format_pattern = format;
  int amt = *str_pattern ? 0 : -1;
  int count_f = 1;
  while (*format_pattern) {
    if (*format_pattern == '%') {
      int flags[] = {0, 0, 1, 0, 0};
      format_pattern++;
      format_pattern = search_flags_len(flags, format_pattern);
      if (flags[3] == 'n') {
        *va_arg(arg, int*) = (int)(str_pattern - str);
      } else {
        if (flags[3] != 'c')
          while (*str_pattern == ' ') str_pattern++;
        str_pattern = init_spec(&amt, str_pattern, flags, arg, &count_f);
      }
    } else if (*format_pattern == ' ') {
      while (*format_pattern == ' ') format_pattern++;
      while (*str_pattern == ' ') str_pattern++;
    }
    if (!count_f) break;
  }
  return amt;
}
