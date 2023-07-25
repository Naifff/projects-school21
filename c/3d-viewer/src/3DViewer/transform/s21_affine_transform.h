#include <math.h>

#include "../parser/s21_parser_file.h"

void zoom(data_t *data, double scale);
void rotate(data_t *data, double angle, int coord);
void moveModel(data_t *data, double step, int coord);