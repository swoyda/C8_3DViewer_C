#ifndef C8_3DVIEWER_V1_0_1_S21_3DVIEWER_H
#define C8_3DVIEWER_V1_0_1_S21_3DVIEWER_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
  size_t vertices_count;
  double *vertices_arr;
  size_t indices_count;
  size_t edges_count;
  int *indices_arr;
  double min_x, max_x, min_y, max_y, min_z, max_z;
} obj_data;

enum exec_statuses { OK, ERR };

#endif  // C8_3DVIEWER_V1_0_1_S21_3DVIEWER_H
