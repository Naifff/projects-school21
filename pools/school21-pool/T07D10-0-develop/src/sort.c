#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

int inputN(int *length);
int input(int *pbuffer, int length);
void output(int *pbuffer, int length);
void bubble_sort(int *pbuffer, int length);

int main() {
    int *pbuffer = NULL, length;
    if (inputN(&length) == TRUE) {
        pbuffer = (int*) malloc(length * sizeof(int));
        if (pbuffer != NULL) {
            if (input(pbuffer, length) == TRUE) {
                bubble_sort(pbuffer, length);
                output(pbuffer, length);
                free(pbuffer);
                return 0;
            }
        }
    }
    printf("n/a");
    return 0;
}

int inputN(int *length) {
    int p;
    if (scanf("%d", &p) == 1) {
        *length = p;
        return TRUE;
    } else {
        return FALSE;
    }
}

int input(int *pbuffer, int length) {
    for (int i = 0; i < length; i++) {
        if (i != length - 1) {
            if (scanf("%d", &pbuffer[i]) != 1) {
                return FALSE;
            }
        } else {
            if (scanf("%d", &pbuffer[i]) == 1)
                return TRUE;
            else
                return FALSE;
        }
    }
    return FALSE;
}


void bubble_sort(int *pbuffer, int length) {
    for (int i = 0; i < length -1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (pbuffer[j] > pbuffer[j + 1]) {
                int tmp = pbuffer[j];
                pbuffer[j] = pbuffer[j + 1];
                pbuffer[j + 1] = tmp;
            }
        }
    }
}

void output(int *pbuffer, int length) {
    for (int i = 0; i < length; i++) {
        if (i != (length - 1))
            printf("%d ", pbuffer[i]);
        else
            printf("%d", pbuffer[i]);
    }
}
