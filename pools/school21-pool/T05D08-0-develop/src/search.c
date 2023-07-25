#include <stdio.h>
#include <math.h>
#define NMAX 30
#define BREAK 0
#define CONTINUE 1

int input(int *a, int *n);
double mean(const int *a, int n);
double meanInSquare(int *a, int n);
double variance(int *a, int n);

void output_result(int *a,
                   double mean_v,
                   double variance_v,
                   const int *n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == CONTINUE) {
        output_result(data,
                      mean(data, n),
                      variance(data, n),
                      &n);
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

double mean(const int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return ((double)sum / (double)n);
}

double meanInSquare(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(a[i], 2);
    }
    return ((double)sum / (double)n);
}
double variance(int *a, int n) {
    return  meanInSquare(a, n) - pow(mean(a, n), 2);
}
void output_result(int *a,
                   double mean_v,
                   double variance_v,
                   const int *n) {
    int number = 0;
    int count = 0;
    for (int i = 0; i < *n; i++) {
        if (a[i] % 2 == 0 && a[i] >= mean_v && (double)a[i] <= mean_v + 3 * sqrt(variance_v) && a[i] != 0) {
            number = a[i];
            count++;
        } else {
            number = 0;
        }
        if (number == 0 || count == 0) {
            number = 0;
        }
    }
    printf("%d", number);
}



