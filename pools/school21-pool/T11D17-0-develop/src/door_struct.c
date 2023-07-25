#include "door_struct.h"
#include <stdio.h>
#include <stdlib.h>

void close(struct door *doors, int n) {
    for (int i = 0; i < n; i++)
    doors[i].status = 0;
}

void sort(struct door *doors, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < n - i + 1; j++) {
            if (doors[j].id < doors[j - 1].id) {
                int buf;
                buf = doors[j].id;
                doors[j].id = doors[j - 1].id;
                doors[j - 1].id = buf;
            }
        }
    }
}

void output(struct door *doors, int n) {
    for (int i = 0; i < n; i++) {
    printf("%d, ", doors[i].id);
    printf("%d\n", doors[i].status);
    }
}
