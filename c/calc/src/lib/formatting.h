#ifndef SRC_FORMATTING_H
#define SRC_FORMATTING_H

#include "../lib/defualt.h"

int valid(char *expression);

int check_bracket(char *expression);

long double str_op(char *op);
int get_len_add(char op);
int get_priority(long double op);

#endif  // SRC_FORMATTING_H