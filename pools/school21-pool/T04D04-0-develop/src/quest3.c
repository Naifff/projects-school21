#include <stdio.h>

int fibo(int n);

int main() {
  int n;
  char c;
  scanf("%d%c", &n, &c);
  if (c == '\n') {
    printf("%d", fibo(n));
  } else {
    printf("n/a");
  }
  return 0;
}

int fibo(int n) {
  if (n != 0) {
    if (n == 1 || n == 2) {
      return 1;
    } else {
      return fibo(n - 1) + fibo(n - 2);
    }
  } else {
        return 0;
  }
}
