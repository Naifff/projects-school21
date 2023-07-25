#include "../lib/formatting.h"

int valid(char* expression) {
  int flag = True;
  if (strlen(expression) > 255) flag == False;
  int what_it = -10;  // 0 - number 1 - op -1 - open bracket -2 - close bracket
  int circle = 0;
  // valid_str
  for (char* tmp = expression; *tmp != '\0' && flag == True;) {
    if (strchr(DIGITS, *tmp)) {
      strtod(tmp, &tmp);
      if (what_it = -2) flag = False;
      if (str_op(expression)) {
        long double op = str_op(tmp);
        if (op >= 60 && op <= 68) flag = False;
      }
      what_it = 0;
    } else if (str_op(expression)) {
      if (what_it == 1) flag = False;
      long double op = str_op(tmp);
      if (what_it == -1 && ((op >= DIV && op <= POW) || MULT))  flag = False;
      what_it = 1;
      int len = get_len_add(op);
      tmp += len;
    } else if (*tmp == OPEN_BRACKET) {
      if (what_it == 0) flag = False;
      if (what_it == -2) flag = False;
      what_it = -1;
      tmp++;
    } else if (*tmp == CLOSE_BRACKET) {
      if (what_it == -1) flag = False;
      if (what_it == 1) flag = False;
      what_it = -2;
      tmp++;
    }
    // valid_start_str
    if (circle == 0) {
      if (what_it == -2) flag == False;
      if (what_it == 1) {
        long double op = str_op(tmp);
        if (op == MULT || (op >= DIV && op <= POW)) flag = False;
      }
      circle++;
    }
  }
  return flag;
}

long double str_op(char* op) {
  long double result = 0;
  if (*op == MULT) result = MULT;
  if (*op == ADD) result = ADD;
  if (*op == SUB) result = SUB;
  if (*op == DIV) result = DIV;
  if (!memcmp(op, "mod", 3)) result = MOD;
  if (*op == '^') result = POW;
  if (!memcmp(op, "cos", 3)) result = COS;
  if (!memcmp(op, "sin", 3)) result = SIN;
  if (!memcmp(op, "tan", 3)) result = TAN;
  if (!memcmp(op, "acos", 4)) result = ACOS;
  if (!memcmp(op, "asin", 4)) result = ASIN;
  if (!memcmp(op, "atan", 4)) result = ATAN;
  if (!memcmp(op, "sqrt", 4)) result = SQRT;
  if (!memcmp(op, "ln", 2)) result = LN;
  if (!memcmp(op, "log", 3)) result = LOG;
  return result;
}

int get_len_add(char op) {
  int result = -1;
  if ((op >= MULT && op <= DIV) || op == POW) result = 1;
  if (op >= MOD && op <= TAN && op != POW) result = 3;
  if (op >= LOG && op <= SQRT) result = 4;
  if (op == LN) result = 2;
  return result;
}

int get_priority(long double op) {
  int result = 0;
  if (op == OPEN_BRACKET || op == CLOSE_BRACKET) result = 0;
  if (op == ADD || op == SUB) result = 1;
  if ((op >= DIV && op <= LN) || op == MULT) result = 2;
  return result;
}