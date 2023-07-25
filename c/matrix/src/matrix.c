#include "matrix.h"

void print_matrix(matrix_t *result) {
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      printf("%f ", result->matrix[i][j]);
    }
    printf("\n");
  }
}

int create_matrix(int rows, int columns, matrix_t *result) {
  int ret = OK;
  if (rows < 1 || columns < 1) {
    ret = INCORRECT;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double));
    if (result->matrix != NULL) {
      for (int i = 0; i < rows; i++) {
        *(result->matrix + i) = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          remove_matrix(result);
          ret = MEMBER_ERR;
        }
      }
    } else {
      remove_matrix(result);
      ret = MEMBER_ERR;
    }
  }
  return ret;
}

void remove_matrix(matrix_t *A) {
  if (A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      free(*(A->matrix + i));
      *(A->matrix + i) = NULL;
    }
    free(A->matrix);
  }
  A->rows = 0;
  A->columns = 0;
  A->matrix = NULL;
}

int eq_matrix(matrix_t *A, matrix_t *B) {
  int ret = SUCCESS;
  if (is_Emty(A) && is_Emty(B) && (A->rows == B->rows) &&
      (A->columns == B->columns)) {
    double eps = 1e-7;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= eps) {
          ret = FAILURE;
          break;
        }
        if (!ret) {
          break;
        }
      }
    }
  } else {
    ret = FAILURE;
  }
  return ret;
}

int sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ret = OK;
  if (is_Emty(A) && is_Emty(B)) {
    if (A->rows == B->rows && A->columns == B->columns) {
      ret = create_matrix(A->rows, A->columns,
                              result);  // добавлена строчка Попытка 2
      if (ret != MEMBER_ERR) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
          }
        }
      }
    } else {
      ret = CALC_ERR;
    }
  } else {
    ret = INCORRECT;
  }
  return ret;
}

int sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ret = OK;
  if (is_Emty(A) && is_Emty(B)) {
    if (A->rows == B->rows && A->columns == B->columns) {
      ret = create_matrix(A->rows, A->columns,
                              result);  // добавлена строчка Попытка 2
      if (ret != MEMBER_ERR) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
          }
        }
      }
    } else {
      ret = CALC_ERR;
    }
  } else {
    ret = INCORRECT;
  }
  return ret;
}

int mult_number(matrix_t *A, double number, matrix_t *result) {
  int ret = OK;
  if (is_Emty(A)) {
    ret = create_matrix(A->rows, A->columns, result);
    if (ret != MEMBER_ERR) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  } else {
    ret = INCORRECT;
  }
  return ret;
}

int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ret = OK;
  if (is_Emty(A) && is_Emty(B)) {
    if (A->columns != B->rows) {
      ret = CALC_ERR;
    } else {
      ret = create_matrix(A->rows, B->columns, result);
      if (ret != MEMBER_ERR) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->columns; j++) {
            result->matrix[i][j] = 0;
            for (int k = 0; k < A->columns; k++) {
              result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
          }
        }
      }
    }
  } else {
    ret = INCORRECT;
  }
  return ret;
}

int transpose(matrix_t *A, matrix_t *result) {
  int ret = OK;
  if (is_Emty(A)) {
    ret = create_matrix(A->columns, A->rows, result);
    if (ret != MEMBER_ERR) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    }
  } else {
    ret = INCORRECT;
  }
  return ret;
}

int calc_complements(matrix_t *A, matrix_t *result) {
  int ret = OK;
  if (is_Emty(A)) {
    if (A->rows != A->columns) {
      ret = CALC_ERR;
    } else {
      ret = create_matrix(A->rows, A->columns, result);
      if (ret != MEMBER_ERR) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            matrix_t tmp;
            create_matrix(A->rows - 1, A->columns - 1, &tmp);
            get_minor(i, j, A, &tmp);
            result->matrix[i][j] = get_determinant(&tmp);
            if ((j + i) % 2) {
              result->matrix[i][j] *= (-1);
            }
            remove_matrix(&tmp);
          }
        }
      }
    }
  } else {
    ret = INCORRECT;
  }
  return ret;
}

int determinant(matrix_t *A, double *result) {
  int ret = OK;
  if (is_Emty(A)) {
    if (A->rows != A->columns) {
      ret = CALC_ERR;
    } else {
      *result = get_determinant(A);
    }
  } else {
    ret = INCORRECT;
  }
  return ret;
}

double get_determinant(matrix_t *A) {
  double det = 0;
  if (A->rows == 1) {
    det = A->matrix[0][0];
  } else {
    double sign = 1;
    matrix_t tmp;
    int ret = create_matrix(A->rows - 1, A->columns - 1, &tmp);
    if (ret != MEMBER_ERR) {
      for (int i = 0; i < A->rows; i++) {
        get_minor(0, i, A, &tmp);
        det += A->matrix[0][i] * sign * get_determinant(&tmp);
        sign *= -1;
      }
      remove_matrix(&tmp);
    } else {
      det = 0;
    }
  }
  return det;
}

void get_minor(int row, int col, matrix_t *A, matrix_t *result) {
  int act_row = 0, act_col = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) continue;
    act_col = 0;
    for (int j = 0; j < A->rows; j++) {
      if (j == col) continue;
      result->matrix[act_row][act_col] = A->matrix[i][j];
      act_col++;
    }
    act_row++;
  }
}

int inverse_matrix(matrix_t *A, matrix_t *result) {
  double det;
  int ret = determinant(A, &det);
  if (!ret) {
    double eps = pow(10, -7);
    if (fabs(det - 0) < eps) {
      ret = CALC_ERR;
    } else {
      matrix_t comp_mat;
      ret = calc_complements(A, &comp_mat);
      if (ret != MEMBER_ERR) {
        matrix_t trans_mat;
        ret = transpose(&comp_mat, &trans_mat);
        if (ret != MEMBER_ERR) {
          mult_number(&trans_mat, 1 / det, result);
          remove_matrix(&trans_mat);
        }
        remove_matrix(&comp_mat);
      }
    }
  }
  return ret;
}

int is_Emty(matrix_t *matrix) {
  int ret = 0;
  if (matrix != NULL && matrix->matrix != NULL && matrix->rows >= 1 &&
      matrix->columns >= 1) {
    ret = 1;
  } else {
    ret = 0;
  }
  return ret;
}