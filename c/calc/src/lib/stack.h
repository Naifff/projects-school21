#ifndef SRC_STACK_H
#define SRC_STACK_H

#include "../lib/defualt.h"

typedef struct stack {
  long double value;
  struct stack *top;
} stack;

int push(stack *root, long double value);
long double pop(stack *root);
long double peak(stack *root);
void destroy(stack *root);
int count_stack(stack *root);
void read(stack *root);

#endif  // SRC_STACK_H