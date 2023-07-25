#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define buffer_size 1024

typedef struct flags {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;  // не выводит название файла
  int s;
  int f;
  int o;
} flags;

int parser(int argc, char *argv[], flags *flag, char **templates,
           int *count_temp, char *pattern);
void f_flag(char *pattern, char *filename);
FILE *open_file(char *filename, flags *flag);
void search(FILE *file, char *filename, char **templates, const int *count_temp,
            flags *flag, int more_file);

#endif  // SRC_GREP_S21_GREP_H_
