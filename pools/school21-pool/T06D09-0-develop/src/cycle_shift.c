#include <stdio.h>
#include <math.h>
#define NMAX 10
#define FALSE 0
#define TRUE 1

int input(int *buffer, int *length);
void shift_right(int *buffer, int length, int s);
void shift_left(int *buffer, int length, int s);
void output(int *buffer, int length);

int main() {
    int length, s, data[NMAX];
    if (input(data, &length) == TRUE) {
        char c;
        scanf("%d%c", &s, &c);
         if (c == '\n') {
             if (s > 0)
                 shift_left(data, length, s);
             else if (s < 0)
                 shift_right(data, length, s);
             output(data, length);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *buffer, int *length) {
    int p;
    char c;
    scanf("%d%c", &p, &c);
    *length = p;
    if (c == '\n' || c == ' ') {
        if (*length >= 1 && *length <= NMAX) {
            for (int i = 0; i < *length; i++) {
                if (i != NMAX - 1) {
                    if (scanf("%d", &buffer[i]) != 1) {
                        return FALSE;
                    }
                } else {
                    if (scanf("%d%c", &buffer[i], &c) == 2 && c == '\n') {
                        return TRUE;
                    } else {
                        return FALSE;
                    }
                }
            }
            return TRUE;
        } else {
            return FALSE;
        }
    } else {
        return FALSE;
    }
}

void shift_right(int *buffer, int length, int s) {
    if (s % 10 != 0)
        s = (-s) % 10;
    int tmp;
    for (int i = 1; i <= s; i++) {
        for (int j = 0; j < length; j++) {
            if (j != length - 1) {
                tmp = buffer[0];
                buffer[0] = buffer[j + 1];
                buffer[j + 1] = tmp;
            } else {
                break;
            }
        }
    }
}

void shift_left(int *buffer, int length, int s) {
    if (s % 10 != 0)
        s = s % 10;
    int tmp;
    for (int i = 1; i <= s; i++) {
        for (int j = length - 1; j >= 0; j--) {
            if (j != 0) {
                tmp = buffer[length - 1];
                buffer[length - 1] = buffer[j - 1];
                buffer[j - 1] = tmp;
            } else {
                break;
            }
        }
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
