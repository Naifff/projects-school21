#include <stdio.h>
#include <math.h>
#define NMAX 10
#define FALSE 0
#define TRUE 1


int input(int *a);
void output(int *a);
void bubble_sort(int *a);

int main() {
    int data[NMAX];
    if (input(data) == TRUE) {
        bubble_sort(data);
        output(data);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a) {
    char c;
    for (int i = 0; i < NMAX; i++) {
        if (i != NMAX - 1) {
            if (scanf("%d", &a[i]) != 1) {
                return FALSE;
            }
        } else {
            if (scanf("%d%c", &a[i], &c) == 2 && c == '\n') {
                return TRUE;
            } else {
                return FALSE;
            }
        }
    }
    return FALSE;
}

void bubble_sort(int *a) {
    for (int i = 0; i < NMAX -1; i++) {
        for (int j = 0; j < NMAX - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void output(int *a) {
    for (int i = 0; i < NMAX; i++) {
        if (i != (NMAX - 1))
            printf("%d ", a[i]);
        else
            printf("%d", a[i]);
    }
}


