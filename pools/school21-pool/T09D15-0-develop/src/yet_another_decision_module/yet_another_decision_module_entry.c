#include <stdio.h>
#include <stdlib.h>
#include "decision.h"
#include "../data_libs/data_io.h"

int main() {
    double *data;
    int n;
    int c;
    if (scanf("%d", &n) == 1 && (scanf("%c", &c) == 1) && c == '\n') {
    if (((data = malloc(n * sizeof(double))) != NULL) && (input(data, n) != 1)) {
    if (make_decision(data, n))
        printf("YES");
    else
        printf("NO");

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
