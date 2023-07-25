#include "../lib/calculate.h"

char *calculate(char *expression) {
  char *result = calloc(256, sizeof(char));
  char error_str[3] = "n/a";
  long double result_exp = 0;
  if (valid(expression)) {
    result_exp = determinare(expression);
    sprintf(result, "%f\n", result_exp);
  } else
    strcpy(result, error_str);
  return result;
}

long double determinare(char *expression) {
  long double result = 0;
  stack *stack_op = calloc(1, sizeof(struct stack));
  stack *stack_num = calloc(1, sizeof(struct stack));
  int flag = 0;
  if (*expression == '-' && flag != True) flag = push(stack_num, 0);
  for (char *tmp = expression; *tmp != '\0' && flag != True;) {
    if (strchr(DIGITS, *tmp) && flag != True) {
      flag = push(stack_num, strtod(tmp, &tmp));
    } else if (str_op(tmp)) {
      long double op = str_op(tmp);
      if (get_priority(op) > get_priority(peak(stack_op)) && flag != True) {
        int len = get_len_add(op);
        push(stack_op, op);
        tmp += len;
      } else {
        while (get_priority(op) <= get_priority(peak(stack_op)) && op != POW &&
               peak(stack_op) != POW && flag != True) {
          flag = push(stack_num, receive(stack_num, pop(stack_op)));
        }
        int len = get_len_add(op);
        if (flag != True) flag = push(stack_op, op);
        tmp += len;
      }
    } else if (*tmp == OPEN_BRACKET && flag != True) {
      flag = push(stack_op, *tmp);
      tmp++;
      if (*tmp == '-' && flag != True) flag = push(stack_num, 0);
    } else if (*tmp == CLOSE_BRACKET && flag != True) {
      while (peak(stack_op) != OPEN_BRACKET && flag != True) {
        flag = push(stack_num, receive(stack_num, pop(stack_op)));
      }
      pop(stack_op);
      // выкидываем открывающую скобку из стека
      if (peak(stack_op) >= 60 && peak(stack_op) <= 68 &&
          flag != True)  // если встретили функцию перед открывающей скобкой
        flag = push(stack_num, receive(stack_num, pop(stack_op)));

      tmp++;
    } else if (*tmp == ' ') {
      tmp++;
    }
  }
  while (count_stack(stack_num) != 1 && flag != True) {
    flag = push(stack_num, receive(stack_num, pop(stack_op)));
  }
  if (count_stack(stack_op) == 1 && count_stack(stack_num) == 1 && flag != True)
    flag = push(stack_num, receive(stack_num, pop(stack_op)));
  if (flag != True) result = pop(stack_num);
  destroy(stack_num);
  destroy(stack_op);
  return result;
}

long double receive(stack *stack_num, long double op) {
  long double result = 0;
  long double num_b = pop(stack_num);
  if (op >= 42 && op <= 59) {
    long double num_a = pop(stack_num);
    if (op == MULT) result = num_a * num_b;
    if (op == ADD) result = num_a + num_b;
    if (op == SUB) result = num_a - num_b;

    if (op == DIV) result = num_a / num_b;
    if (op == MOD) result = fmodf(num_a, num_b);
    if (op == POW) result = pow(num_a, num_b);
  } else {
    if (op == COS) result = cos(num_b);
    if (op == SIN) result = sin(num_b);
    if (op == TAN) result = tan(num_b);
    if (op == ACOS) result = acos(num_b);
    if (op == ASIN) result = asin(num_b);
    if (op == ATAN) result = atan(num_b);
    if (op == SQRT) result = sqrt(num_b);
    if (op == LN) result = log10(num_b);
    if (op == LOG) result = log(num_b);
  }
  return result;
}