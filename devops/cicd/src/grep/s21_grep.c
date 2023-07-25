#include "s21_grep.h"

int main(int argc, char *argv[]) {
  flags flag = {0};
  flag.h = 1;
  int count_temp = -1;
  char patternF[buffer_size] = {0};
  char *templates[buffer_size];
  if (parser(argc, argv, &flag, templates, &count_temp, patternF)) {
    if (!flag.f && !flag.e) {
      count_temp += 1;
      templates[0] = argv[optind++];
    }
    if (flag.f) {
      count_temp += 1;
      templates[count_temp] = patternF;
    }
    int i = optind + 1;
    int more_file = 0;
    if (argv[i] != NULL) {
      if (flag.h != 2) flag.h = 0;
      more_file = 1;
    }
    while (argv[optind] != NULL) {
      FILE *file = open_file(argv[optind], &flag);
      if (file) {
        search(file, argv[optind], templates, &count_temp, &flag, more_file);
        fclose(file);
      }
      optind++;
    }
  }
}

int parser(int argc, char *argv[], flags *flag, char **templates,
           int *count_temp, char *pattern) {
  int param;
  int f = 1;
  struct option options[] = {0};
  while ((param = getopt_long(argc, argv, "e:ivclnhsf:o", options, NULL)) !=
         -1) {
    if (param == 'e') {
      *count_temp += 1;
      templates[*count_temp] = optarg;
      flag->e = 1;
    } else if (param == 'i') {
      flag->i = 1;
    } else if (param == 'v') {
      flag->v = 1;
    } else if (param == 'c') {
      flag->c = 1;
    } else if (param == 'l') {
      flag->l = 1;
    } else if (param == 'n') {
      flag->n = 1;
    } else if (param == 'h') {
      flag->h = 2;
    } else if (param == 's') {
      flag->s = 1;
    } else if (param == 'f') {
      f_flag(pattern, optarg);
      flag->f = 1;
    } else if (param == 'o') {
      flag->o = 1;
    } else {
      printf("usage: ./s21_grep [-eivclnhsf:o]\n");  // такого флага нет
    }
  }
  return f;
}

void f_flag(char *pattern, char *filename) {  // обработка f флага
  FILE *file;
  file = fopen(filename, "r");
  int i = 0;
  if (file != NULL) {
    int ch;
    while ((ch = fgetc(file)) != EOF) {
      if (ch == 13 || ch == 10) pattern[i++] = '|';
      if (ch != 13 && ch != 10) pattern[i++] = ch;
    }
  } else {
    fprintf(stderr, "grep: %s: No such file or directory\n", filename);
    i = -1;
  }
  if (pattern[i - 1] == '|') pattern[i - 1] = '\0';
  fclose(file);
}

FILE *open_file(char *filename, flags *flag) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    if (!flag->s) {  // -s
      fprintf(stderr, "grep: %s: No such file or directory\n", filename);
    }
  }
  return file;
}

void search(FILE *file, char *filename, char **templates, const int *count_temp,
            flags *flag, int more_file) {
  int flag_temp = REG_EXTENDED;
  if (flag->i) flag_temp = REG_ICASE;  // -i
  regex_t regex;
  char text[buffer_size] = {0};
  regmatch_t pmatch[1];
  int line_matches = 0, nline = 1;
  while (fgets(text, buffer_size - 1, file) != NULL) {
    int print_str = 0;
    for (int i = 0; i <= *count_temp; i++) {
      if (print_str == 0) {
        regcomp(&regex, templates[i], flag_temp);
        int match = 0;
        int success = regexec(&regex, text, 1, pmatch, 0);
        if (strchr(text, '\n') == NULL) strcat(text, "\n");
        if (success == 0 && !flag->v) match = 1;
        if (success == REG_NOMATCH && flag->v) match = 1;
        if (match && !flag->h && more_file && !flag->c && !flag->l)
          printf("%s:", filename);
        if (match && !flag->l && !flag->c && flag->n) printf("%d:", nline);
        if (match && !flag->l && !flag->c && !flag->o) printf("%s", text);
        if (match && flag->o) {
          for (int j = pmatch[0].rm_so; j < pmatch[0].rm_eo; j++) {
            printf("%c", text[j]);
          }
          printf("\n");
        }
        regfree(&regex);
        line_matches += match;
        nline++;
      }
      print_str = 1;
    }
  }
  if (flag->c) {
    if (flag->l) {
      line_matches = 1;
      printf("%s:", filename);
    }
    if (!flag->h && more_file) printf("%s:", filename);
    printf("%d\n", line_matches);
  }
  if (flag->l && line_matches > 0) printf("%s\n", filename);
}
