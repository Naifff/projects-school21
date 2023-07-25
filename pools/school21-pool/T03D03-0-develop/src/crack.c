#include <stdio.h>

int main() {
  float x, y;

  if (!scanf("%f", &x)) {
    printf("n/a\n");
    return 0;
  } else {
    if (!scanf("%f", &y)) {
      printf("n/a\n");
      return 0;
    } else {
      if (x * x + y * y < 25) {
        printf("GOTCHA");
      } else {
        printf("MISS");
      }
    }
  }
}
