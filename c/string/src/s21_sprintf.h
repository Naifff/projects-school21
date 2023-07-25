#ifndef SRC_S21_SPRINTF_H
#define SRC_S21_SPRINTF_H

#include <float.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

#define DOT '.'
#define STAR '*'
#define FLAGS "-+ #0"
#define DIGITS "0123456789"
#define LENGHT "hlL"
#define SPECIFS "cdieEfgGosuxXpn%"
#define BASE16LOW "0123456789abcdef"
#define BASE16UP "0123456789ABCDEF"
#define BASE2 "01"
#define BASE8 "01234567"
#define PTR_LEN 12
#define PTR_LEN_WITH_0X 14
#ifdef __APPLE__
#define PTR_NULL_STR ""
#else
#define PTR_NULL_STR "(nil)"
#endif

int s21_sprintf(char *str, const char *format, ...);
void parser(const char *format, int token, int *i, int *width, int *rigor,
            char *lenght, char *specif, va_list *arg_list);
char get_flag(const char *format, int token);
int get_width(const char *format, int token, int *step);
int get_rigor(const char *format, int token, int *step);
char get_lenght(const char *format, int token, int *step);
char get_spec(const char *format, int token, int *step);
char skip_step(const char *format, int token, unsigned int i, int flag,
               int *step);
int my_atol(const char *str, int i);
void print_char(char *str, int *len, const char *format, int token, int *width,
                int *rigor, char *specif, va_list *arg_list);
void print_num(char *str, int *len, const char *format, int token, int *width,
               int *rigor, char *lenght, char *specif, va_list *arg_list);
void print_ratio(char *str, int *len, const char *format, int token, int *width,
                 int *rigor, char *lenght, char *specif, va_list *arg_list);
void print_str(char *str, int *len, const char *format, int token, int *width,
               int *rigor, va_list *arg_list);
void print_ptr(char *str, int *len, const char *format, int token, int *width,
               int *rigor, va_list *arg_list);
int have_flag(const char *format, int token, char flag);
int print_base_ulong(char *target, int *len, unsigned long n, const char *base);
int e_uratio_get_e(long double ld);
int e_uratio_precis_get_str_len(long double ld, int precis_len);
void e_set(int *e, long double *ld);
int uratio_precis_get_str_len(long double ld, int precis_len);
int trgt_print_e_uldouble(char *target, int *len, long double ld,
                          int precis_len, char e_sign);
int trgt_print_uldouble(char *target, int *len, long double ld, int precis_len);
void trgt_print_ulong(char *target, int *len, unsigned long n);
unsigned long ulong_get_pow(unsigned long n, int pow);
int udecim_get_str_len(unsigned long n);
int base_unum_get_str_len(unsigned long n, char *base);
void memcpy_str(char *dest, int *len, const char *src, s21_size_t n);
void fill_str(char *str, int *len, char fill_symb, int fill_len);
void copy_str(char *dest, int *len, const char *src);
void ncopy_str(char *dest, int *len, const char *src, s21_size_t n);

#endif  // SRC_S21_SPRINTF_H
