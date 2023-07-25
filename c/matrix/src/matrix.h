#ifndef SRC_MATRIX_H
#define SRC_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

#define SUCCESS 1
#define FAILURE 0

#define OK 0
#define INCORRECT 1
#define CALC_ERR 2
#define MEMBER_ERR 3

// вывод марицы
void print_matrix(matrix_t *result);

// Создание матриц (create_matrix)
int create_matrix(int rows, int columns, matrix_t *result);

// Очистка матриц (remove_matrix)
void remove_matrix(matrix_t *A);

// Сравнение матриц (eq_matrix)
int eq_matrix(matrix_t *A, matrix_t *B);

// Сложение (sum_matrix) и вычитание матриц (sub_matrix)
int sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Умножение матрицы на число (mult_number). Умножение двух матриц (mult_matrix)
int mult_number(matrix_t *A, double number, matrix_t *result);
int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Транспонирование матрицы (transpose)
int transpose(matrix_t *A, matrix_t *result);

// Минор матрицы и матрица алгебраических дополнений (calc_complements)
int calc_complements(matrix_t *A, matrix_t *result);

// Определитель матрицы (determinant)
int determinant(matrix_t *A, double *result);

// Рекурсивное вычисление определителя
double get_determinant(matrix_t *A);

// Получение матрицы без i-й строки и j-го столбца
void get_minor(int row, int col, matrix_t *A, matrix_t *result);

// Обратная матрица (inverse_matrix)
int inverse_matrix(matrix_t *A, matrix_t *result);

// Проверка на пустату
int is_Emty(matrix_t *matrix);

#endif  // SRC_MATRIX_H