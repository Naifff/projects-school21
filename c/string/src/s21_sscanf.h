#ifndef SRC_S21_SSCANF_H
#define SRC_S21_SSCANF_H
#include "s21_string.h"

// sscanf
int s21_sscanf(const char* str, const char* format, ...);
//

// specifiers
const char* spec_width(const char* format_pattern, int* flags);
const char* spec_percent(const char* str_pattern, int* count_f);
int parser_spec(const char* str, const char* format, va_list arg);
const char* search_flags_len(int* flags, const char* format_pattern);
void run_spec_o_etc(int* flags, const char* str_pattern, int* count,
                    int* flag_in);
const char* spec_s(int* amt, const char* str_pattern, int* flags, va_list arg,
                   int* count_f);
const char* spec_i(int* amt, const char* str_pattern, int* flags, va_list arg,
                   int* count_f);
const char* spec_p(int* amt, const char* str_pattern, int* flags, va_list arg,
                   int* count_f);
const char* spec_d_u(int* amt, const char* str_pattern, int* flags, va_list arg,
                     int* count_f);
const char* init_spec(int* amt, const char* str_pattern, int* flags,
                      va_list arg, int* count_f);
const char* spec_f_etc(int* amt, const char* str_pattern, int* flags,
                       va_list arg, int* count_f);
const char* spec_o_etc(int* amt, const char* str_pattern, int* flags,
                       va_list arg, int* count_f);
const char* spec_c(int* amt, const char* str_pattern, const int* flags,
                   va_list arg, int* count_f);
//

// convert arg
int str_arg_lid(char c);
int convert_calc(int arg_l);
int arg_lid(int num, const char* str_pattern);
const char* if_minus(int* flags, const char* str_pattern);
void count_arg_riable(int count, int* count_f, const int* flags, int* amt);
//

// get arg
const char* get_str(const char* str_pattern, int* flags, va_list arg);
const char* get_fraction_part(const char* str_pattern, int* flags,
                              long double* arg_l);
const char* get_arg_num(int* flags, const char* str_pattern, int* amt, int num,
                        int* count_f, va_list arg);
const char* get_arg_longlong(const char* str_pattern, int* flags,
                             long long* arg_l, int* amt, int* count_f);
const char* get_arg_long_num(int* flags, const char* str_pattern, int* amt,
                             int num, int* count_f, va_list arg);
const char* get_float(int* amt, const char* str_pattern, int* flags,
                      int* count_f, long long int* int_part,
                      long double* fraction, int* exp, int* plus_minus);
//

#endif  // SRC_S21_SSCANF_H
