#include <check.h>
#include <stdio.h>

#include "matrix.h"

START_TEST(test_create_matrix) {
  matrix_t A;
  int resultA = create_matrix(5, 5, &A);
  ck_assert_int_eq(resultA, OK);
  remove_matrix(&A);

  resultA = create_matrix(-4, 4, &A);
  ck_assert_int_eq(resultA, INCORRECT);

  resultA = create_matrix(-4, 0, &A);
  ck_assert_int_eq(resultA, INCORRECT);
}
END_TEST

START_TEST(test_eq_matrix) {
  matrix_t A, B;
  create_matrix(5, 5, &A);
  create_matrix(5, 5, &B);
  int ret = eq_matrix(&A, &B);
  ck_assert_int_eq(ret, SUCCESS);
  remove_matrix(&A);
  remove_matrix(&B);

  ret = eq_matrix(&A, &B);
  ck_assert_int_eq(ret, FAILURE);

  create_matrix(3, 3, &A);
  create_matrix(5, 5, &B);
  ret = eq_matrix(&A, &B);
  ck_assert_int_eq(ret, FAILURE);
  remove_matrix(&A);
  remove_matrix(&B);

  create_matrix(5, 5, &A);
  create_matrix(5, 5, &B);
  A.matrix[2][2] = -7;
  ret = eq_matrix(&A, &B);
  ck_assert_int_eq(ret, FAILURE);
  remove_matrix(&A);
  remove_matrix(&B);

  create_matrix(5, 5, &A);
  create_matrix(5, 5, &B);
  A.matrix[2][2] = -7;
  B.matrix[2][2] = -7;
  ret = eq_matrix(&A, &B);
  ck_assert_int_eq(ret, SUCCESS);
  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(test_sum_matrix) {
  matrix_t A, B, res, res_org;
  create_matrix(5, 5, &A);
  create_matrix(5, 5, &B);
  int ret = sum_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, OK);
  remove_matrix(&B);
  remove_matrix(&res);

  create_matrix(6, 6, &B);
  ret = sum_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, CALC_ERR);
  remove_matrix(&A);

  create_matrix(6, 6, &B);
  ret = sum_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, INCORRECT);
  remove_matrix(&A);
  remove_matrix(&B);

  create_matrix(5, 5, &A);
  create_matrix(5, 5, &B);
  create_matrix(5, 5, &res_org);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      A.matrix[i][j] = i + j;
      res_org.matrix[i][j] = i + j;
    }
  }
  ret = sum_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, OK);
  ret = eq_matrix(&res, &res_org);
  ck_assert_int_eq(ret, SUCCESS);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&res);
  remove_matrix(&res_org);
}
END_TEST

START_TEST(test_sub_matrix) {
  matrix_t A, B, res, res_org;
  create_matrix(5, 5, &A);
  create_matrix(5, 5, &B);
  int ret = sub_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, OK);
  remove_matrix(&B);
  remove_matrix(&res);

  create_matrix(6, 6, &B);
  ret = sub_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, CALC_ERR);
  remove_matrix(&A);

  create_matrix(6, 6, &B);
  ret = sub_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, INCORRECT);
  remove_matrix(&A);
  remove_matrix(&B);

  create_matrix(5, 5, &A);
  create_matrix(5, 5, &B);
  create_matrix(5, 5, &res_org);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      A.matrix[i][j] = i - j;
      res_org.matrix[i][j] = i - j;
    }
  }
  ret = sub_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, OK);
  ret = eq_matrix(&res, &res_org);
  ck_assert_int_eq(ret, SUCCESS);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&res);
  remove_matrix(&res_org);
}
END_TEST

START_TEST(test_mult_number) {
  matrix_t A, res, res_org;
  create_matrix(5, 5, &A);
  create_matrix(5, 5, &res);
  create_matrix(5, 5, &res_org);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      A.matrix[i][j] = 1;
      res_org.matrix[i][j] = 1 * 5;
    }
  }
  int ret = mult_number(&A, 5, &res);
  ck_assert_int_eq(ret, OK);
  ret = eq_matrix(&res, &res_org);
  ck_assert_int_eq(ret, SUCCESS);
  remove_matrix(&A);
  ret = mult_number(&A, 5, &res);
  ck_assert_int_eq(ret, INCORRECT);
  remove_matrix(&res);
  remove_matrix(&res_org);
}
END_TEST

START_TEST(test_mult_matrix) {
  matrix_t A, B, res, res_org;
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);
  create_matrix(2, 2, &res_org);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      A.matrix[i][j] = i + j + 1;
      B.matrix[i][j] = i + j + 1;
    }
  }
  res_org.matrix[0][0] = 5;
  res_org.matrix[0][1] = 8;
  res_org.matrix[1][0] = 8;
  res_org.matrix[1][1] = 13;
  int ret = mult_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, OK);
  ret = eq_matrix(&res, &res_org);
  ck_assert_int_eq(ret, SUCCESS);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&res);
  remove_matrix(&res_org);

  create_matrix(3, 2, &A);
  create_matrix(2, 2, &B);
  create_matrix(3, 2, &res_org);
  ret = mult_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, OK);
  ret = eq_matrix(&res, &res_org);
  ck_assert_int_eq(ret, SUCCESS);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&res);
  remove_matrix(&res_org);

  create_matrix(2, 7, &A);
  create_matrix(2, 2, &B);
  ret = mult_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, CALC_ERR);
  remove_matrix(&A);
  remove_matrix(&B);

  ret = mult_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, INCORRECT);
  remove_matrix(&res);
}
END_TEST

START_TEST(test_transpose) {
  matrix_t A, res_my, res_org;

  create_matrix(2, 2, &A);
  create_matrix(2, 2, &res_org);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  res_org.matrix[0][0] = 1;
  res_org.matrix[0][1] = 3;
  res_org.matrix[1][0] = 2;
  res_org.matrix[1][1] = 4;
  int ret = transpose(&A, &res_my);
  ck_assert_int_eq(ret, OK);
  ret = eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, SUCCESS);
  remove_matrix(&A);
  remove_matrix(&res_my);
  remove_matrix(&res_org);

  double matrix[3][2] = {{1, 2}, {3, 4}, {5, 6}};
  double res[2][3] = {{1, 3, 5}, {2, 4, 6}};
  create_matrix(3, 2, &A);
  create_matrix(2, 3, &res_org);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      A.matrix[i][j] = matrix[i][j];
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      res_org.matrix[i][j] = res[i][j];
    }
  }
  ret = transpose(&A, &res_my);
  ck_assert_int_eq(ret, OK);
  ret = eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, SUCCESS);
  remove_matrix(&A);
  remove_matrix(&res_my);
  remove_matrix(&res_org);
  ret = transpose(&A, &res_my);
  ck_assert_int_eq(ret, INCORRECT);
}
END_TEST

START_TEST(test_calc_complements) {
  double m[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
  double r[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};
  matrix_t matrix, res_org, res_my;
  create_matrix(3, 3, &matrix);
  create_matrix(3, 3, &res_org);
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = m[i][j];
    }
  }
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      res_org.matrix[i][j] = r[i][j];
    }
  }
  int ret = calc_complements(&matrix, &res_my);
  ck_assert_int_eq(ret, OK);
  ret = eq_matrix(&res_org, &res_my);
  ck_assert_int_eq(ret, SUCCESS);
  remove_matrix(&matrix);
  remove_matrix(&res_my);
  remove_matrix(&res_org);

  create_matrix(2, 3, &matrix);
  ret = calc_complements(&matrix, &res_my);
  ck_assert_int_eq(ret, CALC_ERR);
  remove_matrix(&matrix);

  ret = calc_complements(&matrix, &res_my);
  ck_assert_int_eq(ret, INCORRECT);
}
END_TEST

START_TEST(test_determinant) {
  matrix_t matrix;
  create_matrix(3, 3, &matrix);
  int count = 1;
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = count++;
    }
  }
  matrix.matrix[2][2] = 10;
  double res;
  int ret = determinant(&matrix, &res);
  ck_assert_uint_eq(res, -3);
  ck_assert_int_eq(ret, OK);
  remove_matrix(&matrix);

  create_matrix(2, 3, &matrix);
  ret = determinant(&matrix, &res);
  ck_assert_int_eq(ret, CALC_ERR);
  remove_matrix(&matrix);

  ret = determinant(&matrix, &res);
  ck_assert_int_eq(ret, INCORRECT);
}
END_TEST

START_TEST(test_inverse_matrix) {
  double m[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  double r[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};
  matrix_t matrix, res_org, res_my;
  create_matrix(3, 3, &matrix);
  create_matrix(3, 3, &res_org);
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = m[i][j];
    }
  }
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      res_org.matrix[i][j] = r[i][j];
    }
  }
  int ret = inverse_matrix(&matrix, &res_my);
  ck_assert_int_eq(ret, OK);
  ret = eq_matrix(&res_org, &res_my);
  ck_assert_int_eq(ret, SUCCESS);

  double m2[3][3] = {{2, 5, 7}, {0, 0, 0}, {5, -2, -3}};
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = m2[i][j];
    }
  }
  ret = inverse_matrix(&matrix, &res_my);
  ck_assert_int_eq(ret, CALC_ERR);
  remove_matrix(&matrix);
  remove_matrix(&res_my);
  remove_matrix(&res_org);
}
END_TEST

Suite *matrix_test(void) {
  Suite *s = suite_create("matrix_test");

  TCase *tc_create_matrix = tcase_create("test_create_matrix");
  suite_add_tcase(s, tc_create_matrix);
  tcase_add_test(tc_create_matrix, test_create_matrix);

  TCase *tc_eq_matrix = tcase_create("test_eq_matrix");
  suite_add_tcase(s, tc_eq_matrix);
  tcase_add_test(tc_eq_matrix, test_eq_matrix);

  TCase *tc_sum_matrix = tcase_create("test_sum_matrix");
  suite_add_tcase(s, tc_sum_matrix);
  tcase_add_test(tc_sum_matrix, test_sum_matrix);

  TCase *tc_sub_matrix = tcase_create("test_sub_matrix");
  suite_add_tcase(s, tc_sub_matrix);
  tcase_add_test(tc_sub_matrix, test_sub_matrix);

  TCase *tc_mult_number = tcase_create("test_mult_number");
  suite_add_tcase(s, tc_mult_number);
  tcase_add_test(tc_mult_number, test_mult_number);

  TCase *tc_mult_matrix = tcase_create("test_mult_matrix");
  suite_add_tcase(s, tc_mult_matrix);
  tcase_add_test(tc_mult_matrix, test_mult_matrix);

  TCase *tc_transpose = tcase_create("test_transpose");
  suite_add_tcase(s, tc_transpose);
  tcase_add_test(tc_transpose, test_transpose);

  TCase *tc_calc_complements = tcase_create("test_calc_complements");
  suite_add_tcase(s, tc_calc_complements);
  tcase_add_test(tc_calc_complements, test_calc_complements);

  TCase *tc_determinant = tcase_create("test_determinant");
  suite_add_tcase(s, tc_determinant);
  tcase_add_test(tc_determinant, test_determinant);

  TCase *tc_inverse_matrix = tcase_create("test_inverse_matrix");
  suite_add_tcase(s, tc_inverse_matrix);
  tcase_add_test(tc_inverse_matrix, test_inverse_matrix);

  return s;
}

int main(void) {
  int number_failed = 0;
  Suite *s = matrix_test();
  SRunner *sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}