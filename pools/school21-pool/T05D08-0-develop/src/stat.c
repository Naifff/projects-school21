#include <stdio.h>
#include <math.h>
#define NMAX 10
#define BREAK 0
#define CONTINUE 1

int input(int *a, int *n);
void output(int *a, int n);
int max(const int *a, int n);
int min(const int *a, int n);
double mean(const int *a, int n);
double meanInSquare(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == CONTINUE) {
        output(data, n);
        output_result(max(data, n),
                      min(data, n),
                      mean(data, n),
                      variance(data, n));
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
            printf("%d\n", a[i]);
    }
}

int max(const int *a, int n) {
    int max = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}
int min(const int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] < min)
            min = a[i];
    }
    return min;
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

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
