#include <stdio.h>
#include <stdlib.h>
#include "../data_libs/data_io.h"
#include "../data_module/data_process.h"
#include "../data_libs/data_stat.h"
#include "../yet_another_decision_module/decision.h"

int main() {
    double *data;
    int n;
    char c;
    if (scanf("%d", &n) == 1 && (scanf("%c", &c) == 1) && c == '\n') {
    printf("LOAD DATA...\n");
    if (((data = malloc(n * sizeof(double))) != NULL) && (input(data, n) != 1)) {
    printf("RAW DATA:\n\t");
    output(data, n);

    printf("\nNORMALIZED DATA:\n\t");
    normalization(data, n);
    output(data, n);

    printf("\nSORTED NORMALIZED DATA:\n\t");
    sort(data, n);
    output(data, n);

    printf("\nFINAL DECISION:\n\t");
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
