#include "data_stat.h"

double max(double *data, int n) {
    double max = data[0];
    for (int i = 0; i < n - 1; i++)
    if (data[i] < data[i + 1]) {
        max = data[i + 1];
}
return max;
}

double min(double *data, int n) {
    double min = data[0];
    for (int i = 0; i < n - 1; i++)
    if (data[i] > data[i + 1]) {
        min = data[i + 1];
}
return min;
}

double mean(double *data, int n) {
    double sum = 0;
    for (double *p = data; p - data < n; p++) {
        sum += *p/n;
    }
    return sum;
}

double variance(double *data, int n) {
    double sum, var = 0;
    sum = mean(data, n);
    for (double *p = data; p - data < n; p++) {
        var = var + (*p - sum) * (*p - sum) / n;
    }
    return var;
}

void sort(double *data, int n) {
    double a;
    for (double *i = data; i - data < n; i++) {
        for (double *j = data; j - data < n - 1; j++) {
            if (*j > *(j + 1)) {
            a = *j;
            *j = *(j + 1);
            *(j + 1) = a;
            }
        }
    }
}
