#include <stdio.h>
#include <stdlib.h>
void sort_vertical(int **matrix, int n, int m, int **result);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int m, int **result);


void input(int **matrix, int n, int m, int *flag);
void output(int **result, int n, int m);


int main() {
    int n, m, flag = 0;
    if (scanf("%d", &n) != 1)
    flag = 1;
    if (scanf("%d", &m) != 1)
    flag = 1;
    if (n == 0 || m == 0)
    flag = 1;
    int **matrix = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    matrix[i] = malloc(m * sizeof(int));

    int **result = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    result[i] = malloc(m * sizeof(int));

    input(matrix, n, m, &flag);
    if (flag == 1) {
    printf("n/a");
    } else {
    sort_vertical(matrix, n, m, result);
    output(result, n, m);
    printf("\n");
    sort_horizontal(matrix, m, result);
    output(result, n, m);

    for (int i = 0; i < n; i++)
    free(result[i]);
    free(result);
    for (int i = 0; i < n; i++)
    free(matrix[i]);
    free(matrix);
    }
    return 0;
}

void sort_vertical(int **matrix, int n, int m, int **result) {
    for (int count = 0; count < n; count++) {
        if (count % 2 == 0) {
                for (int j = count, i = 0; i < m; i++) {
                    result[j][i] = matrix[j][i];
        }
        } else {
        for (int j = count, i = 0; i < m; i++) {
            result[j][i] = matrix[j][m - 1 - i];
    }
    }
    }
}
void sort_horizontal(int **matrix, int m, int **result) {
    for (int count = 0; count < m; count++) {
        if (count % 2 == 0) {
                for (int i = count, j = 0; j < m; j++) {
                    result[j][i] = matrix[i][j];
        }
        } else {
        for (int i = count, j = 0; j < m; j++) {
            result[m - 1 - j][i] = matrix[i][j];
    }
    }
    }
}

void input(int **matrix, int n, int m, int *flag) {
  int a;
  char c;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
        a = (scanf("%d", &matrix[j][i]));
          if (a != 1)
          *flag = 1;
          scanf("%c", &c);
          if (c == '\n' && i < m - 1)
          *flag = 1;
          if (c != '\n' && i == m - 1)
          *flag = 1;
          if (c == '.')
          *flag = 1;
        }
    }
}

void output(int **result, int n, int m) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
    if (i < m - 1)
    printf("%d ", result[j][i]);
    else
    printf("%d", result[j][i]);
    }
    if (j < n - 1)
    printf("\n");
}
}
