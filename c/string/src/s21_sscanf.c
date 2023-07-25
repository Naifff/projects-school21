#include "s21_sscanf.h"

int s21_sscanf(const char* str, const char* format, ...) {
  va_list arg;
  va_start(arg, format);
  int ret = parser_spec(str, format, arg);
  va_end(arg);
  return ret;
}
