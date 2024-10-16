#include "affine_transformations.h"

void move_X(obj_data *data, const double k) {
  for (size_t i = 0; i < data->vertices_count * 3; i += 3)
    data->vertices_arr[i] += k;
}

void move_Y(obj_data *data, const double k) {
  for (size_t i = 1; i < data->vertices_count * 3; i += 3)
    data->vertices_arr[i] += k;
}

void move_Z(obj_data *data, const double k) {
  for (size_t i = 2; i < data->vertices_count * 3; i += 3)
    data->vertices_arr[i] += k;
}

void rotate_X(obj_data *data, double angle) {
  double y, z;
  angle = angle * M_PI / 180;
  for (size_t i = 0; i < data->vertices_count * 3; i += 3) {
    y = data->vertices_arr[i + 1];
    z = data->vertices_arr[i + 2];
    data->vertices_arr[i + 1] = y * cos(angle) + z * sin(angle);
    data->vertices_arr[i + 2] = -y * sin(angle) + z * cos(angle);
  }
}

void rotate_Y(obj_data *data, double angle) {
  double x, z;
  angle = angle * M_PI / 180;
  for (size_t i = 0; i < data->vertices_count * 3; i += 3) {
    x = data->vertices_arr[i];
    z = data->vertices_arr[i + 2];
    data->vertices_arr[i] = x * cos(angle) + z * sin(angle);
    data->vertices_arr[i + 2] = -x * sin(angle) + z * cos(angle);
  }
}

void rotate_Z(obj_data *data, double angle) {
  double x, y;
  angle = angle * M_PI / 180;
  for (size_t i = 0; i < data->vertices_count * 3; i += 3) {
    x = data->vertices_arr[i];
    y = data->vertices_arr[i + 1];
    data->vertices_arr[i] = x * cos(angle) + y * sin(angle);
    data->vertices_arr[i + 1] = -x * sin(angle) + y * cos(angle);
  }
}

void scale(obj_data *data, const double k) {
  if (k != 0) {
    for (size_t i = 0; i < data->vertices_count * 3; i++)
      data->vertices_arr[i] *= k;
  }
}