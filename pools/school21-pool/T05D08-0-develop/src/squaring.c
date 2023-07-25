#include <stdio.h>
#include <math.h>
#define NMAX 10
#define BREAK 0
#define CONTINUE 1


int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == CONTINUE) {
        squaring(data, n);
        output(data, n);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *n) {
    int p;
    char c;
    scanf("%d%c", &p, &c);
    *n = p;
    if (c == '\n' || c == ' ') {
        if (*n >= 1 && *n <= NMAX) {
            for (int i = 0; i < *n; i++) {
                scanf("%d%c", &a[i], &c);
                if (i != (*n - 1)) {
                    if (c != ' ')
                        return BREAK;
                } else {
                    if (c != '\n')
                        return BREAK;
                    else
                        return CONTINUE;
                }
            }
            return CONTINUE;
        } else {
            return BREAK;
        }
    } else {
        return BREAK;
    }
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i != (n - 1))
            printf("%d ", a[i]);
        else
            printf("%d", a[i]);
    }
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = pow(a[i], 2);
    }
}


