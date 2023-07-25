#include <stdio.h>

int sum(int a, int b);
int dif(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int main() {
  float a, b;
    if (!scanf("%f", &a)) {
    printf("n/a\n");
    return 0;
  } else {
    if ((int)(a * 1000000) % 1000000 != 0) {
      printf("n/a\n");
      return 0;
    } else {
      if (!scanf("%f", &b)) {
        printf("n/a\n");
        return 0;
      } else {
        if ((int)(b * 1000000) % 1000000 != 0) {
          printf("n/a\n");
          return 0;
        } else {
          int c = a;
          int d = b;
          if (b == 0) {
            printf("%d %d %d n/a\n", sum(c, d), dif(c, d), mul(c, d));
          } else {
            printf("%d %d %d %d\n", sum(c, d), dif(c, d), mul(c, d), div(c, d));
          }
        }
      }
    }
  }
  printf("%f %f", a, b);
  return 0;
}

int sum(int a, int b) {
  return a+b;
}

int dif(int a, int b) {
  return a-b;
}

int mul(int a, int b) {
  return a*b;
}

int div(int a, int b) {
  return a/b;
}
