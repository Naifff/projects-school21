#include <stdio.h>
#include <stdlib.h>
#include "../data_libs/data_stat.h"
#include "../data_libs/data_io.h"
#include "data_process.h"

int main() {
    double *data;
    int n;
    char c;
    if (scanf("%d", &n) == 1 && (scanf("%c", &c) == 1)
    && c == '\n') {
    if (((data = malloc(n * sizeof(double))) != NULL) && (input(data, n) != 1)) {
    if (normalization(data, n))
        output(data, n);
    else
        printf("ERROR");
    free(data);
    } else {
        printf("n/a");
        free(data);
    }
    } else {
        printf("n/a");
    }
    return 0;
}
