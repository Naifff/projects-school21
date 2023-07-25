#include "s21_sprintf.h"

#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  int len = 0, token = 0, width = 0, rigor = 0;
  char lenght = 0, specif = 0;
  va_list(arg_list);
  va_start(arg_list, format);
  for (int i = 0; format[i] != '\0'; i++) {
    if (format[i] == '%') {
      i++;
      token = i;

      parser(format, token, &i, &width, &rigor, &lenght, &specif, &arg_list);
      if (specif == SPECIFS[0] || specif == SPECIFS[15]) {
        print_char(str, &len, format, token, &width, &rigor, &specif,
                   &arg_list);
      }
      if (specif == SPECIFS[1] || specif == SPECIFS[2] ||
          specif == SPECIFS[8] || specif == SPECIFS[10] ||
          specif == SPECIFS[11] || specif == SPECIFS[12]) {
        print_num(str, &len, format, token, &width, &rigor, &lenght, &specif,
                  &arg_list);
      }
      if (specif == SPECIFS[3] || specif == SPECIFS[4] ||
          specif == SPECIFS[5] || specif == SPECIFS[6] ||
          specif == SPECIFS[7]) {
        print_ratio(str, &len, format, token, &width, &rigor, &lenght, &specif,
                    &arg_list);
      }
      if (specif == SPECIFS[9]) {
        print_str(str, &len, format, token, &width, &rigor, &arg_list);
      }
      if (specif == SPECIFS[13]) {
        print_ptr(str, &len, format, token, &width, &rigor, &arg_list);
      }
      if (specif == SPECIFS[14]) {
        int *to_write_here = 0;
        to_write_here = va_arg(arg_list, int *);
        *to_write_here = len;
      }
    } else {
      str[len] = format[i];
      len++;
    }
  }
  str[len] = '\0';
  va_end(arg_list);
  return len;
}

void parser(const char *format, int token, int *i, int *width, int *rigor,
            char *lenght, char *specif, va_list *arg_list) {
  *i = token;
  *width = get_width(format, token, i);
  if (*width == -2) *width = va_arg(*arg_list, int);
  *i = token;
  *rigor = get_rigor(format, token, i);
  if (*rigor == -2) *rigor = va_arg(*arg_list, int);
  *i = token;
  *lenght = get_lenght(format, token, i);
  *i = token;
  *specif = get_spec(format, token, i);
}

int get_width(const char *format, int token, int *step) {
  char width = skip_step(format, token, 1, 1, step);
  int result = -1;
  if (width == STAR) {
    result = -2;
  }
  if (my_atol(format, *step)) {
    result = my_atol(format, *step);
  }
  return result;
}

int get_rigor(const char *format, int token, int *step) {
  char rigor = skip_step(format, token, 2, 1, step);
  int result = 0;
  result--;
  if (rigor == DOT) {
    *step += 1;
    result = -3;
    if (format[*step] == STAR) {
      result = -2;
    }
    if (my_atol(format, *step)) {
      result = my_atol(format, *step);
    } else if (rigor == '0') {
      result = 0;
    }
  }
  return result;
}

char get_lenght(const char *format, int token, int *step) {
  char lenght = skip_step(format, token, 3, 0, step);
  if (s21_strchr(LENGHT, lenght)) {
    return lenght;
  }
  return '\0';
}

char get_spec(const char *format, int token, int *step) {
  char spec = skip_step(format, token, 4, 1, step);
  if (spec && s21_strchr(SPECIFS, spec)) {
    return spec;
  }
  return '\0';
}

char skip_step(const char *format, int token, unsigned int i, int flag,
               int *step) {
  if (i--) /* flags */ {
    while (format[token] && s21_strchr(FLAGS, format[token])) {
      token++;
    }
  }
  if (i--) { /* width */
    if (format[token] == STAR)
      token++;
    else
      while (format[token] && s21_strchr(DIGITS, format[token])) token++;
  }
  if (i--) { /* precision */
    if (format[token] == DOT) {
      token++;
      if (format[token] == STAR)
        token++;
      else
        while (format[token] && s21_strchr(DIGITS, format[token])) token++;
    }
  }
  if (i--) /* length-specifier */
    if (format[token] && s21_strchr(LENGHT, format[token])) token++;
  if (i) /* specifier */
    if (format[token] && s21_strchr(SPECIFS, format[token])) token++;
  if (flag) *step = token;
  return format[token];
}

int my_atol(const char *str, int i) {
  int result = 0;
  int is_minus = 0;
  if (str[i] == '-') {
    is_minus = 1;
    i++;
  }
  while (str[i] && s21_strchr(DIGITS, str[i])) {
    result *= 10;
    result += str[i] - '0';
    i++;
  }
  return is_minus ? -result : result;
}

void print_char(char *str, int *len, const char *format, int token, int *width,
                int *rigor, char *specif, va_list *arg_list) {
  int is_prequel = 0;
  char tokn_specif = 0, tokn_c = 0, fill_symb = 0;
  int fill_len = 0;
  is_prequel = have_flag(format, token, FLAGS[0]);
  if (*width == -2) {
    *width = va_arg(*arg_list, int);
  }
  if (*width < 0) {
    is_prequel = 1;
    *width = -*width;
  }

  fill_len = *width - 1;
  if (fill_len < 0) {
    fill_len = 0;
  }

  if (*rigor == -1) {
    *rigor = 6;
  }
  if (*rigor == -2) {
    *rigor = va_arg(*arg_list, int);
  }
  if (*rigor < 0) {
    *rigor = 0;
  }
  tokn_specif = *specif;

  tokn_c = '\0';
  if (tokn_specif == SPECIFS[0]) {
    tokn_c = (char)va_arg(*arg_list, int);
  }
  if (tokn_specif == SPECIFS[15]) {
    tokn_c = SPECIFS[15];
  }

  fill_symb = ' ';

  if (have_flag(format, token, FLAGS[4]) && is_prequel == 0) {
    fill_symb = '0';
  }

  if (is_prequel == 0) {
    fill_str(str, len, fill_symb, fill_len);
  }
  str[*len] = tokn_c;
  *len += 1;
  if (is_prequel) {
    fill_str(str, len, fill_symb, fill_len);
  }
}

void print_num(char *str, int *len, const char *format, int token, int *width,
               int *rigor, char *lenght, char *specif, va_list *arg_list) {
  int is_prequel = have_flag(format, token, FLAGS[0]);

  if (*width == -2) {
    *width = va_arg(*arg_list, int);
  }
  if (*width == -1) {
    *width = 0;
  }
  if (*width < 0) {
    is_prequel = 1;
    *width = -*width;
  }

  int is_rigor_provided = 1;
  if (*rigor == -3) {
    *rigor = 0;
  }
  if (*rigor == -1) {
    *rigor = 0;
    is_rigor_provided = 0;
  }
  if (*rigor == -2) {
    *rigor = va_arg(*arg_list, int);
  }

  long tokn_num = va_arg(*arg_list, long);

  if ((*specif == SPECIFS[1] || *specif == SPECIFS[2]) &&
      *lenght != LENGHT[1]) {
    tokn_num = (int)tokn_num;
  }
  if (*lenght == LENGHT[0]) {
    tokn_num = (short)tokn_num;
  }
  if (*lenght == LENGHT[1]) {
    tokn_num = (long)tokn_num;
  }

  char sign = '\0';
  if (have_flag(format, token, FLAGS[1])) {
    sign = '+';
  }
  if (tokn_num < 0 && *specif != SPECIFS[10]) {
    sign = '-';
  }
  if (sign == '\0' && have_flag(format, token, FLAGS[2])) {
    sign = ' ';
  }

  char *base = DIGITS;
  char *prefix_0x = s21_NULL;
  if (*specif == SPECIFS[8]) {
    base = BASE8;
    prefix_0x = "0";
  }
  if (*specif == SPECIFS[11]) {
    base = BASE16LOW;
    prefix_0x = "0x";
  }
  if (*specif == SPECIFS[12]) {
    base = BASE16UP;
    prefix_0x = "0X";
  }
  if (have_flag(format, token, FLAGS[3]) == 0 || tokn_num == 0) {
    prefix_0x = s21_NULL;
  }

  unsigned long tokn_unum;
  if (*specif == SPECIFS[1] || *specif == SPECIFS[2]) {
    tokn_unum = tokn_num >= 0 ? tokn_num : -tokn_num;
  } else {
    tokn_unum = tokn_num;
  }

  int tokn_unum_len = base_unum_get_str_len(tokn_unum, base);
  if (is_rigor_provided && *rigor == 0 && tokn_unum == 0) {
    tokn_unum_len = 0;
  }

  int rigor_prefix_len = *rigor - tokn_unum_len;
  if (rigor_prefix_len < 0) {
    rigor_prefix_len = 0;
  }

  int fill_len = 0;
  if (*width) {
    fill_len = *width - rigor_prefix_len - tokn_unum_len;
  }
  if (sign) {
    fill_len--;
  }
  if (prefix_0x) {
    fill_len -= s21_strlen(prefix_0x);
  }
  if (fill_len < 0) {
    fill_len = 0;
  }
  char fill_symb = ' ';
  if (have_flag(format, token, FLAGS[4]) && is_prequel == 0) {
    fill_symb = '0';
  }
  if (rigor_prefix_len || *rigor > 0) {
    fill_symb = ' ';
  }

  if (is_prequel == 0) {
    if (fill_symb == '0' && sign) {
      str[*len] = sign;
      *len += 1;
    }
    if (fill_symb == ' ' || prefix_0x == s21_NULL) {
      fill_str(str, len, fill_symb, fill_len);
    }
  }
  if (fill_symb == ' ' && sign) {
    if (!((sign && *specif == SPECIFS[10]) ||
          (sign == '-' &&
           (*specif == SPECIFS[11] || *specif == SPECIFS[12])))) {
      str[*len] = sign;
      *len += 1;
    }
  }
  if (prefix_0x) {
    copy_str(str, len, prefix_0x);
    if (fill_symb == '0') {
      fill_str(str, len, fill_symb, fill_len);
    }
  }
  if (rigor_prefix_len) {
    fill_str(str, len, '0', rigor_prefix_len);
  }
  if ((is_rigor_provided && *rigor == 0 && tokn_unum == 0) == 0) {
    print_base_ulong(str, len, tokn_unum, base);
    str[*len] = '\0';
  }
  if (is_prequel) {
    fill_str(str, len, fill_symb, fill_len);
  }
}

void print_ratio(char *str, int *len, const char *format, int token, int *width,
                 int *rigor, char *lenght, char *specif, va_list *arg_list) {
  char tokn_specif = *specif;
  char buff[500] = {0};
  int e = 0;
  int actual_precis_len = 0;
  int len2 = 0;
  int len1 = 0;
  int i = 0;
  int actual_e_precis_len = 0;
  int non_precis_part_len = 0;
  int is_e_shorter = 0;
  int is_prequel = 0;
  char sign = 0;
  long double tokn_ratio = 0;
  int precis_len = 0;
  int is_point_forced = 0;
  int is_pre_whitespace = 0;
  int fill_len = 0;
  char fill_symb = 0;
  char e_sign = 0;
  is_prequel = have_flag(format, token, FLAGS[0]);
  if (*width == -2) {
    *width = va_arg(*arg_list, int);
  }
  if (*width < 0) {
    is_prequel = 1;
    *width = -*width;
  }

  precis_len = *rigor;
  if (precis_len == -1) {
    precis_len = 6;
  }
  if (precis_len == -2) {
    precis_len = va_arg(*arg_list, int);
  }
  if (precis_len <= -3) {
    precis_len = 0;
  }
  if (precis_len == 0 &&
      (tokn_specif == SPECIFS[6] || tokn_specif == SPECIFS[7])) {
    precis_len = 1;
  }

  if (*lenght == LENGHT[2]) {
    tokn_ratio = va_arg(*arg_list, long double);
  } else {
    tokn_ratio = va_arg(*arg_list, double);
  }

  sign = '\0';
  if (tokn_ratio >= 0 && have_flag(format, token, FLAGS[1])) {
    sign = '+';
  }
  if (tokn_ratio < 0) {
    sign = '-';
    tokn_ratio = -tokn_ratio;
  }

  is_e_shorter = 0;
  non_precis_part_len = udecim_get_str_len((unsigned long)tokn_ratio);
  if (tokn_specif == SPECIFS[3] || tokn_specif == SPECIFS[4]) {
    non_precis_part_len = 5;
    /*  Числа, наподобие 1.54+e01, имеют 1 символ до запятой и 4 символа
     *      после дробной части
     */
  } else if (tokn_specif == SPECIFS[6] || tokn_specif == SPECIFS[7]) {
    if (have_flag(format, token, FLAGS[3])) {
      e = e_uratio_get_e(tokn_ratio);
      e++;
      precis_len = precis_len - e;
      if (precis_len < 0) {
        precis_len = 0;
      }
    } else {
      actual_precis_len = uratio_precis_get_str_len(tokn_ratio, precis_len);
      actual_e_precis_len = e_uratio_precis_get_str_len(tokn_ratio, precis_len);

      i = 0;
      len1 = trgt_print_uldouble(buff, &i, tokn_ratio, actual_precis_len);
      i = 0;
      len2 =
          trgt_print_e_uldouble(buff, &i, tokn_ratio, actual_e_precis_len, 'e');

      if (len2 < len1 - 1) {
        is_e_shorter = 1;
        precis_len = actual_e_precis_len;
        non_precis_part_len = 5;
      } else {
        e = e_uratio_get_e(tokn_ratio);
        precis_len = precis_len - e - 1;
        precis_len = uratio_precis_get_str_len(tokn_ratio, precis_len);
      }
    }
  }

  is_point_forced = have_flag(format, token, FLAGS[3]);
  is_pre_whitespace = 0;
  if (sign == '\0' && have_flag(format, token, FLAGS[2])) {
    is_pre_whitespace = 1;
  }

  fill_len = *width - precis_len - non_precis_part_len;
  if (is_pre_whitespace) {
    fill_len--;
  }
  if (precis_len || is_point_forced) {
    fill_len--;
  }
  if (sign) {
    fill_len--;
  }
  if (fill_len < 0) {
    fill_len = 0;
  }

  fill_symb = ' ';
  if (have_flag(format, token, FLAGS[4]) && is_prequel == 0) {
    fill_symb = '0';
  }

  e_sign = '\0';
  if (tokn_specif == SPECIFS[3] || tokn_specif == SPECIFS[6]) {
    e_sign = 'e';
  }
  if (tokn_specif == SPECIFS[4] || tokn_specif == SPECIFS[7]) {
    e_sign = 'E';
  }

  if (precis_len == 0 && is_point_forced) {
    precis_len = -1;
  }

  if (is_pre_whitespace) {
    str[*len] = ' ';
    *len += 1;
  }
  if (is_prequel == 0) {
    if (fill_symb == '0' && sign) {
      str[*len] = sign;
      *len += 1;
    }
    fill_str(str, len, fill_symb, fill_len);
  }
  if (fill_symb == ' ' && sign) {
    str[*len] = sign;
    *len += 1;
  }
  if (tokn_specif == SPECIFS[5]) {
    trgt_print_uldouble(str, len, tokn_ratio, precis_len);
  } else if (tokn_specif == SPECIFS[3] || tokn_specif == SPECIFS[4]) {
    trgt_print_e_uldouble(str, len, tokn_ratio, precis_len, e_sign);

  } else if (tokn_specif == SPECIFS[6] || tokn_specif == SPECIFS[7]) {
    if (is_e_shorter) {
      str += trgt_print_e_uldouble(str, len, tokn_ratio, precis_len, e_sign);
    } else {
      str += trgt_print_uldouble(str, len, tokn_ratio, precis_len);
    }
  }
  if (is_prequel) {
    fill_str(str, len, fill_symb, fill_len);
  }
}

void print_str(char *str, int *len, const char *format, int token, int *width,
               int *rigor, va_list *arg_list) {
  int is_prequel = have_flag(format, token, FLAGS[0]);

  int tokn_width = *width;
  if (tokn_width == -2) {
    tokn_width = va_arg(*arg_list, int);
  }
  if (tokn_width == -1) {
    tokn_width = 0;
  }
  if (tokn_width < 0) {
    is_prequel = 1;
    tokn_width = -tokn_width;
  }

  int tokn_precis = *rigor;
  if (tokn_precis == -2) {
    tokn_precis = va_arg(*arg_list, int);
  }

  char *tokn_str = va_arg(*arg_list, char *);
  if (tokn_precis == -1 || tokn_precis > (int)s21_strlen(tokn_str)) {
    tokn_precis = s21_strlen(tokn_str);
  }
  if (tokn_precis < 0) {
    tokn_precis = 0;
  }

  int fill_len = tokn_width - tokn_precis;
  if (fill_len < 0) {
    fill_len = 0;
  }

  if (is_prequel == 0) {
    fill_str(str, len, ' ', fill_len);
  }

  ncopy_str(str, len, tokn_str, tokn_precis);

  if (is_prequel) {
    fill_str(str, len, ' ', fill_len);
  }
}

void print_ptr(char *str, int *len, const char *format, int token, int *width,
               int *rigor, va_list *arg_list) {
  int is_prequel = have_flag(format, token, FLAGS[0]);

  if (*width == -2) {
    *width = va_arg(*arg_list, int);
  }
  if (*width == -1) {
    *width = 0;
  }
  if (*width < 0) {
    is_prequel = 1;
    *width = -*width;
  }

  if (*rigor == -3) {
    *rigor = 0;
  }
  if (*rigor == -2) {
    *rigor = va_arg(*arg_list, int);
  }
  if (*rigor == -1) {
    *rigor = 0;
  }
  if (*rigor < 0) {
    *rigor = 0;
  }

  s21_size_t p = va_arg(*arg_list, s21_size_t);

  int is_null = 0;
  if (p == 0) {
    is_null = 1;
    // #ifdef __APPLE__
    *rigor = 1;
    // #endif
  }

  int p_len = base_unum_get_str_len(p, BASE16LOW);
  if (is_null) {
    p_len = 0;
  }

  int zero_prefix_len = PTR_LEN - p_len;
  if (zero_prefix_len < 0) {
    zero_prefix_len = 0;
  }
  // #if defined(__APPLE__) || defined(__MUSL__)
  zero_prefix_len = 0;
  // #endif

  int fill_len = *width - 2 - zero_prefix_len - p_len;
  if (is_null) {
    // #ifndef __APPLE__  // If NOT __APPLE__
    fill_len = *width - s21_strlen(PTR_NULL_STR);
    // #endif
    //     fill_len -= *rigor;
  }
  if (fill_len < 0) {
    fill_len = 0;
  }

  if (is_prequel == 0) {
    fill_str(str, len, ' ', fill_len);
  }
  if (is_null) {
    copy_str(str, len, PTR_NULL_STR);
#ifdef __APPLE__
    str[*len] = '0';
    *len += 1;
    str[*len] = 'x';
    *len += 1;
    fill_str(str, len, '0', *rigor);
#endif
  } else {
    str[*len] = '0';
    *len += 1;
    str[*len] = 'x';
    *len += 1;
    fill_str(str, len, '0', zero_prefix_len);
    print_base_ulong(str, len, p, BASE16LOW);
  }
  if (is_prequel) {
    fill_str(str, len, ' ', fill_len);
  }
}

int have_flag(const char *format, int token, char flag) {
  while (s21_strchr(FLAGS, format[token])) {
    if (format[token] == flag) return 1;
    token++;
  }
  return 0;
}

int base_unum_get_str_len(unsigned long n, char *base) {
  int result = 0;
  while (n >= (unsigned long)s21_strlen(base)) {
    result++;
    n /= (unsigned long)s21_strlen(base);
  }
  result++;
  return result;
}

int print_base_ulong(char *target, int *len, unsigned long n,
                     const char *base) {
  const char *target_saved = target;
  int base_n = s21_strlen(base);
  if (n / base_n) {
    target[*len] += print_base_ulong(target, len, n / base_n, base);
  }
  target[*len] = base[n % base_n];
  *len += 1;
  return target - target_saved;
}

int e_uratio_get_e(long double ld) {
  int e = 0;
  if (ld != 0) {
    e_set(&e, &ld);
  }
  return e;
}

int e_uratio_precis_get_str_len(long double ld, int precis_len) {
  int e = 0;
  ld += LDBL_EPSILON;
  e_set(&e, &ld);
  return uratio_precis_get_str_len(ld, precis_len);
}

void e_set(int *e, long double *ld) {
  while (*ld < 1) {
    *e -= 1;
    *ld *= 10;
  }
  while (*ld > 10) {
    *e += 1;
    *ld /= 10;
  }
}

int uratio_precis_get_str_len(long double ld, int precis_len) {
  ld -= (long)ld;

  char buff[500] = {0};
  int j = 0;
  trgt_print_uldouble(buff, &j, ld, precis_len);

  int i = precis_len - 1;
  while (buff[2 + i] == '0') {
    i--;
  }

  return i + 1;
}

int trgt_print_e_uldouble(char *target, int *len, long double ld,
                          int precis_len, char e_sign) {
  int e = 0;
  ld += LDBL_EPSILON;
  e_set(&e, &ld);

  trgt_print_uldouble(target, len, ld, precis_len);

  target[*len] = e_sign;
  *len += 1;
  if (e < 0) {
    target[*len] = '-';
    *len += 1;
    e = -e;
  } else {
    target[*len] = '+';
    *len += 1;
  }
  target[*len] = '0' + e / 10;
  *len += 1;
  target[*len] = '0' + e % 10;
  *len += 1;
  target[*len] = '\0';
  return (*len + 1);
}

int trgt_print_uldouble(char *target, int *len, long double ld,
                        int precis_len) {
  int zeros_count = 0;
  int after_part_len = 0;
  long double after_part = 0;
  unsigned long decim_part = 0;
  if (isnan(ld)) {
    memcpy_str(target, len, "nan", 3);
    return 3;
  }
  if (ld == INFINITY) {
    memcpy_str(target, len, "inf", 3);
    return 3;
  }
  if (precis_len == 0) {
    if ((int)(ld * 10) % 10 >= 5) {
      ld += 1;
    }
  }
  decim_part = (long)ld;
  trgt_print_ulong(target, len, decim_part);
  ld -= decim_part;
  if (precis_len == -1) {
    target[*len] = '.';
    *len += 1;
  }
  if (precis_len > 0) {
    target[*len] = '.';
    *len += 1;
    after_part = ld * ulong_get_pow(10, precis_len);
    after_part = round(after_part);
    after_part_len = udecim_get_str_len((unsigned long)after_part);
    zeros_count = precis_len - after_part_len;
    if (zeros_count < 0) {
      zeros_count = 0;
    }
    fill_str(target, len, '0', zeros_count);
    trgt_print_ulong(target, len, (unsigned long)after_part);
  }
  return (*len + 1);
}

void trgt_print_ulong(char *target, int *len, unsigned long n) {
  int n_len = udecim_get_str_len(n);
  char curr_c = 0;
  unsigned long curr_d = 0;
  unsigned long divisor = 0;
  while (n_len > 0) {
    divisor = ulong_get_pow(10, n_len - 1);
    curr_d = n / divisor;
    curr_c = '0' + curr_d;
    target[*len] = curr_c;
    *len += 1;
    n %= divisor;
    n_len--;
  }
}

unsigned long ulong_get_pow(unsigned long n, int pow) {
  unsigned long result = 0;
  if (pow == 0) {
    result = 1;
  }
  if (pow) {
    result = n;
    pow--;
  }
  while (pow) {
    result *= n;
    pow--;
  }
  return result;
}

int udecim_get_str_len(unsigned long n) {
  return base_unum_get_str_len(n, DIGITS);
}

void memcpy_str(char *dest, int *len, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  for (i = 0; i < n; i++) {
    dest[*len] = src[i];
    *len += 1;
  }
}

void fill_str(char *str, int *len, char fill_symb, int fill_len) {
  while (fill_len > 0) {
    str[*len] = fill_symb;
    fill_len--;
    *len += 1;
  }
}

void copy_str(char *dest, int *len, const char *src) {
  int i = 0;
  while (src[i] != '\0') {
    dest[*len] = src[i];
    i++;
    *len += 1;
  }
  dest[*len] = '\0';
}

void ncopy_str(char *dest, int *len, const char *src, s21_size_t n) {
  s21_size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[*len] = src[i];
    *len += 1;
  }
}
