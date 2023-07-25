#include "s21_affine_transform.h"

void moveModel(data_t *data, double step, int coord) {
  int verticesAmount = data->verticesAmount * 3;
  for (int i = 0; i < verticesAmount; i += 3) {
    data->vertices[i + coord] += step;
  }
}

void rotate(data_t *data, double angle, int coord) {
  double sinAngle = sin(angle);
  double cosAngle = cos(angle);
  int verticesAmount = data->verticesAmount * 3;
  for (int i = 0; i < verticesAmount; i += 3) {
    double x1 = data->vertices[i];
    double y1 = data->vertices[i + 1];
    double z1 = data->vertices[i + 2];

    if (coord == 0) {
      data->vertices[i + 1] = y1 * cosAngle - sinAngle * z1;
      data->vertices[i + 2] = y1 * sinAngle + cosAngle * z1;
    } else if (coord == 1) {
      data->vertices[i] = x1 * cosAngle + sinAngle * z1;
      data->vertices[i + 2] = -x1 * sinAngle + cosAngle * z1;
    } else if (coord == 2) {
      data->vertices[i] = x1 * cosAngle - sinAngle * y1;
      data->vertices[i + 1] = x1 * sinAngle + cosAngle * y1;
    }
  }
}

void zoom(data_t *data, double scale) {
  int verticesAmount = data->verticesAmount * 3;
  for (int i = 0; i < verticesAmount; i++) {
    data->vertices[i] *= scale;
  }
}
