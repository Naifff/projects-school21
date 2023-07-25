#ifndef SRC_CALCULATE_H
#define SRC_CALCULATE_H

#include "../lib/formatting.h"
#include "../lib/stack.h"

// calculate

char *calculate(char *expression);

long double determinare(char *expression);

long double receive(stack *stack_num, long double op);

// credit_calculate
long double credit_calculate();

// deposit_calculate
long double deposit_calculate();

#endif  // SRC_CALCULATE_H