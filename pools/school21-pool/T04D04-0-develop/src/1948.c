#include <stdio.h>

int delit(int n);
int prostoe(int pd);

int main() {
  int n, del;
  char c;
  scanf("%d%c", &n, &c);
  if (c == '\n') {
      del = delit(n);
      if (del == 0)
        printf("n/a");
      else
        printf("%d", del);
  } else {
      printf("n/a");
  }
  return 0;
}

int delit(int n) {
  if (n != 0) {
    if (n != 1) {
      int de;
        if (n > 0) {
          de = n;
        } else {
          de = -n;
        }
        for (int i = de; i > 0; i--) {
          int res = de;
          while (res > 0) {
            res -= i;
          }
          int pd;
          if (res == 0) {
            pd = prostoe(i);
          }
          if (pd == 1) {
            return i;
          }
        }
      } else {
          return 1;
        }
        return 0;
    } else {
      return 0;
    }
}

int prostoe(int pd) {
  if (pd > 1) {
    int pde;
    if (pd > 0) {
      pde = pd;
    } else {
      pde = -pd;
    }
    for (int i = 2; i < pd; i++) {
      int res = pde;

      if (res > 0) {
        while (res > 0) {
          res -= i;
        }
      } else {
        while (res < 0) {
          res += i;
        }
      }
      if (res == 0) {
        return 0;
      }
    }
    return 1;
  } else {
    return 0;
  }
}
