#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
#define NMAX 100

int MODE(int *mode);
int NMatrix(int *lengthY, int *lengthX);
int input(int (*pbuffer)[NMAX], int lengthY, int lengthX);
int inputDinamic(int **pbuffer, int lengthY, int lengthX);
void inputAndOutputMatrix(int **pointer_array, int lengthY, int lengthX);
void MaxStatic(int (*pbuffer)[NMAX], int lengthY, int lengthX);
void MinStatic(int (*pbuffer)[NMAX], int lengthY, int lengthX);
void MaxDinamic(int **pbuffer, int lengthY, int lengthX);
void MinDinamic(int **pbuffer, int lengthY, int lengthX);
int staticMatrix(int lengthY, int lengthX);
int dinamic1Matrix(int lengthY, int lengthX);
int dinamic2Matrix(int lengthY, int lengthX);
int dinamic3Matrix(int lengthY, int lengthX);
void outputStatic(int (*pbuffer)[NMAX], int lengthY, int lengthX);
void outputDinamic(int **pbuffer, int lengthY, int lengthX);
void output(int *pbuffer, int length);

int main() {
    int mode, lengthX, lengthY;
    if (MODE(&mode) == TRUE) {
        NMatrix(&lengthY, &lengthX);
        switch (mode) {
            case 1:
                staticMatrix(lengthY, lengthX);
                return 0;
            case 2:
                dinamic1Matrix(lengthY, lengthX);
                return 0;
            case 3:
                dinamic2Matrix(lengthY, lengthX);
                return 0;
            case 4:
                dinamic3Matrix(lengthY, lengthX);
                return 0;
        }
    }
    printf("n/a");
    return 0;
}

int MODE(int *mode) {
    int p;
    if (scanf("%d", &p) == 1) {
        *mode = p;
        return TRUE;
    } else {
        return FALSE;
    }
}

int NMatrix(int *lengthY, int *lengthX) {
    int n, n2;
    if (scanf("%d%d", &n, &n2) != 2) {
        return FALSE;
    } else {
        *lengthY = n;
        *lengthX = n2;
        return TRUE;
    }
}

int input(int (*pbuffer)[NMAX], int lengthY, int lengthX) {
    int n;
    for (int i = 0; i < lengthY; i++) {
        for (int j = 0; j < lengthX; j++) {
            if (j != lengthX - 1) {
                if (scanf("%d", &n) != 1)
                    return FALSE;
                else
                    pbuffer[i][j] = n;
            } else {
                if (scanf("%d", &n) == 1) {
                    pbuffer[i][j] = n;
                    continue;
                } else {
                    return FALSE;
                }
            }
        }
    }
    return TRUE;
}

int inputDinamic(int **pbuffer, int lengthY, int lengthX) {
    int n;
    for (int i = 0; i < lengthY; i++) {
        for (int j = 0; j < lengthX; j++) {
            if (j != lengthX - 1) {
                if (scanf("%d", &n) != 1)
                    return FALSE;
                else
                    pbuffer[i][j] = n;
            } else {
                if (scanf("%d", &n) == 1) {
                    pbuffer[i][j] = n;
                    continue;
                } else {
                    return FALSE;
                }
            }
        }
    }
    return TRUE;
}

void inputAndOutputMatrix(int **pointer_array, int lengthY, int lengthX) {
    if (inputDinamic(pointer_array, lengthY, lengthX) == TRUE) {
        outputDinamic(pointer_array, lengthY, lengthX);
        MaxDinamic(pointer_array, lengthY, lengthX);
        MinDinamic(pointer_array, lengthY, lengthX);
    } else {
        printf("n/a");
    }
}

void MaxStatic(int (*pbuffer)[NMAX], int lengthY, int lengthX) {
    printf("\n");
    int *buffer = NULL;
    buffer = (int*) malloc(lengthY * sizeof(int));
    if (buffer != NULL) {
        int count = 0;
        for (int i = 0; i < lengthX; i++) {
            int max = pbuffer[i][0];
            for (int j = 0; j < lengthY; j++) {
                int n = pbuffer[i][j];
                if (n > max) {
                    max = n;
                }
            }
            count++;
            buffer[i] = max;
        }
        output(buffer, count);
    }
    free(buffer);
}

void MinStatic(int (*pbuffer)[NMAX], int lengthY, int lengthX) {
    printf("\n");
    int *buffer = NULL;
    buffer = (int*) malloc(lengthY * sizeof(int));
    if (buffer != NULL) {
        int count = 0;
        for (int i = 0; i < lengthY; i++) {
            int min = pbuffer[0][i];
            for (int j = 0; j < lengthX; j++) {
                int n = pbuffer[j][i];
                if (n < min) {
                    min = n;
                }
            }
            count++;
            buffer[i] = min;
        }
        output(buffer, count);
    }
    free(buffer);
}

void MaxDinamic(int **pbuffer, int lengthY, int lengthX) {
    printf("\n");
    int *buffer = NULL;
    buffer = (int*) malloc(lengthY * sizeof(int));
    if (buffer != NULL) {
        int count = 0;
        for (int i = 0; i < lengthX; i++) {
            int max = pbuffer[i][0];
            for (int j = 0; j < lengthY; j++) {
                int n = pbuffer[i][j];
                if (n > max) {
                    max = n;
                }
            }
            count++;
            buffer[i] = max;
        }
        output(buffer, count);
    }
    free(buffer);
}

void MinDinamic(int **pbuffer, int lengthY, int lengthX) {
    printf("\n");
    int *buffer = NULL;
    buffer = (int*) malloc(lengthY * sizeof(int));
    if (buffer != NULL) {
        int count = 0;
        for (int i = 0; i < lengthY; i++) {
            int min = pbuffer[0][i];
            for (int j = 0; j < lengthX; j++) {
                int n = pbuffer[j][i];
                if (n < min) {
                    min = n;
                }
            }
            count++;
            buffer[i] = min;
        }
        output(buffer, count);
    }
    free(buffer);
}

int staticMatrix(int lengthY, int lengthX) {
    if ((lengthX > 0 && lengthX < NMAX + 1) && (lengthY > 0 && lengthY < 101)) {
        int buffer[lengthY][lengthX];
        if (input(buffer, lengthY, lengthX) == TRUE) {
            outputStatic(buffer, lengthY, lengthX);
            MaxStatic(buffer, lengthY, lengthX);
            MinStatic(buffer, lengthY, lengthX);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int dinamic1Matrix(int lengthY, int lengthX) {
    int** pointer_array = malloc(lengthY * sizeof(int*));
    if (pointer_array != NULL) {
        for (int i = 0; i < lengthY; i++) {
            pointer_array[i] = malloc(lengthX * sizeof(int*));
            if (pointer_array[i] == NULL)
                break;
        }
        inputAndOutputMatrix(pointer_array, lengthY, lengthX);
        for (int i = 0; i < lengthY; i++)
            free(pointer_array[i]);
    }
    free(pointer_array);
    return 0;
}

int dinamic2Matrix(int lengthY, int lengthX) {
    int** pointer_array = malloc(lengthY * sizeof(int*));
    if (pointer_array != NULL) {
        int* values_array = malloc(lengthX * lengthY * sizeof(int*));
        if (values_array != NULL) {
            for (int i = 0; i < lengthY; i++)
                pointer_array[i] = values_array + lengthX * i;
            inputAndOutputMatrix(pointer_array, lengthY, lengthX);
        }
        free(values_array);
    }
    free(pointer_array);
    return 0;
}

int dinamic3Matrix(int lengthY, int lengthX) {
    int** pointer_array = malloc(lengthY * lengthX * sizeof(int*) + lengthY * sizeof(int*));
    if (pointer_array != NULL) {
        int* values_array = (int*)(pointer_array + lengthY);
        if (values_array != NULL) {
            for (int i = 0; i < lengthY; i++)
                pointer_array[i] = values_array + lengthX * i;
            inputAndOutputMatrix(pointer_array, lengthY, lengthX);
        }
    }
    free(pointer_array);
    return 0;
}

void outputDinamic(int **pbuffer, int lengthY, int lengthX) {
    for (int i = 0; i < lengthY; i++) {
        for (int j = 0; j < lengthX; j++) {
            int p = pbuffer[i][j];
            if (j != (lengthX - 1)) {
                printf("%d ", p);
            } else {
                if (i != (lengthY - 1))
                    printf("%d\n", p);
                else
                    printf("%d", p);
            }
        }
    }
}

void outputStatic(int (*pbuffer)[NMAX], int lengthY, int lengthX) {
    for (int i = 0; i < lengthY; i++) {
        for (int j = 0; j < lengthX; j++) {
            int p = pbuffer[i][j];
            if (j != (lengthX - 1)) {
                printf("%d ", p);
            } else {
                if (i != (lengthY - 1))
                    printf("%d\n", p);
                else
                    printf("%d", p);
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

