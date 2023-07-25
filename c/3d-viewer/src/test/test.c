#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../3DViewer/transform/s21_affine_transform.h"

START_TEST(Parser_1) {
  data_t data = {0, 0, NULL, NULL, 0};
  int error = parsingFile(&data, "../obj/cube.obj");
  ck_assert_int_eq(error, 2);
}
END_TEST

START_TEST(Parser_2) {
  data_t data = {0, 0, NULL, NULL, 0};
  int error = parsingFile(&data, "obj/cube.obj");
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(Parser_3) {
  data_t data = {0, 0, NULL, NULL, 0};
  int error = parsingFile(&data, "obj/WOLF.OBJ");
  if (error == OK) freeData(&data);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(Parser_4) {
  data_t data = {0, 0, NULL, NULL, 0};
  int error = parsingFile(&data, "obj/skull.obj");
  if (error == OK) freeData(&data);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(Transform_1) {
  data_t data = {0, 0, NULL, NULL, 0};
  int error = parsingFile(&data, "obj/cube.obj");
  if (error == OK) {
    int facets_count_check = 36;
    int vertices_count_check = 8;
    int arr_of_facets_check[36] = {0, 1, 1, 3, 3, 0, 1, 2, 2, 3, 3, 1,
                                   1, 5, 5, 2, 2, 1, 5, 6, 6, 2, 2, 5,
                                   5, 4, 4, 6, 6, 5, 4, 7, 7, 6, 6, 4};
    double arr_of_vertices_check[8] = {-0.5, -0.5, 0.5, 0.5,
                                       -0.5, 0.5,  0.5, 0.5};
    ck_assert_int_eq(facets_count_check, data.facetsAmount);
    ck_assert_int_eq(vertices_count_check, data.verticesAmount);

    for (int i = 0; i < facets_count_check; i++) {
      // printf("check: %d. massiv: %d\n", arr_of_facets_check[i],
      // data.facets[i]);
      ck_assert_int_eq(arr_of_facets_check[i], data.facets[i]);
    }
    for (int i = 0; i < vertices_count_check; i++) {
      // printf("check: %f. massiv: %f\n", arr_of_vertices_check[i],
      // data.vertices[i]);
      ck_assert_int_eq(arr_of_vertices_check[i], data.vertices[i]);
    }

    // // check
    moveModel(&data, 1.0, 1);
    moveModel(&data, 1.0, 2);
    moveModel(&data, 1.0, 3);
    double move_of_vertices_check[8] = {-0.5, 0.5, 1.5, 1.5,
                                        0.5,  1.5, 1.5, 1.5};
    for (int i = 0; i < vertices_count_check; i++) {
      // printf("check: %f. massiv: %f\n", move_of_vertices_check[i],
      //        data.vertices[i]);
      ck_assert_int_eq(move_of_vertices_check[i], data.vertices[i]);
    }

    zoom(&data, 2);
    double scale_of_vertices_check[8] = {-1.0, 1.0, 3.0, 3.0,
                                         1.0,  3.0, 3.0, 3.0};
    for (int i = 0; i < vertices_count_check; i++) {
      // printf("check: %f. massiv: %f\n", scale_of_vertices_check[i],
      //        data.vertices[i]);
      ck_assert_int_eq(scale_of_vertices_check[i], data.vertices[i]);
    }

    rotate(&data, 360, 1);
    rotate(&data, 360, 2);
    rotate(&data, 360, 0);
    double rotate_of_vertices_check[8] = {-1.855504, -0.882684, 2.603454,
                                          -1.533581, 3.104090,  2.648160,
                                          -3.451413, 3.265052};
    for (int i = 0; i < vertices_count_check; i++) {
      // printf("check: %f. massiv: %f\n", rotate_of_vertices_check[i],
      //        data.vertices[i]);
      ck_assert_int_eq(rotate_of_vertices_check[i], data.vertices[i]);
    }
    freeData(&data);
  }
}
END_TEST

Suite* parser_tests_create() {
  Suite* parser = suite_create("Parser");
  TCase* parser_tests = tcase_create("Parser test case");
  tcase_add_test(parser_tests, Parser_1);
  tcase_add_test(parser_tests, Parser_2);
  tcase_add_test(parser_tests, Parser_3);
  tcase_add_test(parser_tests, Parser_4);
  suite_add_tcase(parser, parser_tests);
  return parser;
}

Suite* transform_tests_create() {
  Suite* transform = suite_create("Transform");
  TCase* transform_tests = tcase_create("Transform test case");
  tcase_add_test(transform_tests, Transform_1);
  suite_add_tcase(transform, transform_tests);
  return transform;
}

int main() {
  // Сьют для теста парсера
  Suite* parser = parser_tests_create();
  SRunner* parser_runner = srunner_create(parser);
  int number_failed;
  srunner_run_all(parser_runner, FP_NORMAL);
  number_failed = srunner_ntests_failed(parser_runner);
  srunner_free(parser_runner);

  // Сьют для теста функций трансформации
  Suite* transform = transform_tests_create();
  SRunner* transform_runner = srunner_create(transform);
  srunner_run_all(transform_runner, FP_NORMAL);
  number_failed = number_failed + srunner_ntests_failed(transform_runner);
  srunner_free(transform_runner);

  return number_failed == 0 ? 0 : 1;
}