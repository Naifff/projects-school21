#include "s21_cat.h"

int main(int argc, char *argv[]) {
  flags flag = {0};
  if (parser_flags(argc, argv, &flag)) {
    while (argv[optind] != NULL) {
      reader_file(argv, &flag);
      optind++;
    }
  }
  return 0;
}

int parser_flags(int argc, char *argv[], flags *flag) {
  int param;
  struct option options[] = {
      {"number-nonblank", 0, 0, 'b'},
      {"number", 0, 0, 'n'},
      {"squeeze-blank", 0, 0, 's'},
      {0, 0, 0, 0},
  };
  int f = 1;
  while ((param = getopt_long(argc, argv, "+bEnsTvet", options, NULL)) != -1) {
    if (param == 'b') {
      flag->b = 1;
    } else if (param == 'E') {
      flag->e = 1;
    } else if (param == 'n') {
      flag->n = 1;
    } else if (param == 's') {
      flag->s = 1;
    } else if (param == 'T') {
      flag->t = 1;
    } else if (param == 'v') {
      flag->v = 1;
    } else if (param == 'e') {
      flag->e = 1;
      flag->v = 1;
    } else if (param == 't') {
      flag->t = 1;
      flag->v = 1;
    } else {
      printf("usage: ./s21_cat [-bEnsTvet]\n");  // такого флага нет
      f = 0;
    }
    if (flag->b && flag->n) flag->n = 0;
  }
  return f;
}

void reader_file(char *argv[], flags *flag) {
  FILE *f = fopen(argv[optind], "r");  // optind - переходит к файлу
  if (f) {
    int cur;
    int str_count = 1;
    int emnty_str_count = 0;
    int last = '\n';
    while ((cur = fgetc(f)) != EOF) {
      if (last == '\n' && flag->s && cur == '\n') {
        emnty_str_count++;
        if (emnty_str_count > 1) continue;
      } else {
        emnty_str_count = 0;
      }
      if (last == '\n' && ((flag->b && cur != '\n') || flag->n))
        printf("%6d\t", str_count++);
      if (flag->t && cur == '\t') {
        printf("^");
        cur = 'I';
      }
      if (flag->e && cur == '\n') printf("$");
      if (flag->v) {
        if ((cur >= 0 && cur < 9) || (cur > 10 && cur < 32) ||
            (cur > 126 && cur <= 160)) {
          printf("^");
          if (cur > 126) {
            cur -= 64;
          } else {
            cur += 64;
          }
        }
      }
      printf("%c", cur);
      last = cur;
    }
    fclose(f);
  } else {
    fprintf(stderr, "%s: No such file or directory", argv[optind]);
  }
}
