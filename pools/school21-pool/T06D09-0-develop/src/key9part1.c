#include <stdio.h>
#include <math.h>
#define NMAX 10
#define FALSE 0
#define TRUE 1

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(const int *buffer, int length);
void find_numbers(const int* buffer, int length, int number);

int main() {
    int length, data[NMAX];
    if (input(data, &length) == TRUE) {
        int sum = sum_numbers(data, length);
        if (sum != 0) {
            find_numbers(data, length, sum);
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
    if (c == '\n') {
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
            return FALSE;
        } else {
            return FALSE;
        }
    } else {
        return FALSE;
    }
}

int sum_numbers(const int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum += buffer[i];
        }
    }
    return sum;
}

void find_numbers(const int* buffer, int length, int number) {
    int numbers[NMAX];
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0) {
            if (number % buffer[i] == 0) {
                numbers[count] = buffer[i];
                count++;
            }
        }
    }
     if (count > 0) {
        printf("%d\n", number);
        output(numbers, count);
     } else {
         printf("n/a");
     }
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i != (n - 1))
            printf("%d ", a[i]);
        else
            printf("%d\n", a[i]);
    }
}
