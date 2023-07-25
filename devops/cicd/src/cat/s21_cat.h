#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct flags {
  int b;
  int e;
  int v;
  int n;
  int s;
  int t;
} flags;

int parser_flags(int argc, char *argv[], flags *flag);
void reader_file(char *argv[], flags *flag);

#endif  // SRC_CAT_S21_CAT_H_
