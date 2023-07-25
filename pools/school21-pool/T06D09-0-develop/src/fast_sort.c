#include <stdio.h>
#include <math.h>
#define NMAX 10
#define FALSE 0
#define TRUE 1


int input(int *a, int *b);
void output(int *a);
void fast_sort(int *a, int first, int last);
void insertion_sort(int *a);

int main() {
    int data[NMAX];
    int data2[NMAX];
    if (input(data, data2) == TRUE) {
        fast_sort(data, 0, NMAX - 1);
        insertion_sort(data2);
        output(data);
        printf("\n");
        output(data2);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *b) {
    char c;
    for (int i = 0; i < NMAX; i++) {
        if (i != NMAX - 1) {
            if (scanf("%d", &a[i]) == 1) {
                b[i] = a[i];
            } else {
                return FALSE;
            }
        } else {
            if (scanf("%d%c", &a[i], &c) == 2 && c == '\n') {
                b[i] = a[i];
                return TRUE;
            } else {
                return FALSE;
            }
        }
    }
    return FALSE;
}

void fast_sort(int *a, int first, int last) {
    if (first < last) {
        int left = first, right = last, middle = a[(left + right) / 2];
        do {
            while (a[left] < middle)
                left++;
            while (a[right] > middle)
                right--;
            if (left <= right) {
                int tmp = a[0 + left];
                a[0 + left] = a[0 + right];
                a[0 + right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        fast_sort(a, first, right);
        fast_sort(a, left, last);
    }
}

void insertion_sort(int *a) {
    for (int i = 1; i < NMAX; i++) {
        int element = a[i], index = i - 1;
        while (index >= 0 && a[index] > element) {
            a[index + 1] = a[index];
            index--;
        }
        a[index + 1] = element;
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


