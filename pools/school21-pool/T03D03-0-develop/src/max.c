#include <stdio.h>

int max(int a, int b);

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
          printf("%d\n", max((int)a, (int)b));
        }
      }
    }
  }
  return 0;
}

int max(int a, int b) {
  int m = a;
  if (b > a)
    m = b;
  return m;
}
