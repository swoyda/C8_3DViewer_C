#include "parcer.h"

#include <stdio.h>

int parse_obj_file(const char *filename, obj_data *data) {
  int res = OK;
  FILE *file = fopen(filename, "r");
  if (file) {
    data->edges_count = 0;
    count_vertices_and_indices(file, data);
    obj_mem_alloc(data);
    parsing_value(file, data);
    fclose(file);
    
  printf("\n---------------->%ld\n",data->edges_count);
  } else
    res = ERR;
  return res;
}

int count_vertices_and_indices(FILE *file, obj_data *data) {
  int count = 0;
  double x, y, z;
  char line[100];
  int setted = 0;
  while (fgets(line, sizeof(line), file) != NULL) {
    if (strncmp(line, "v ", 2) == 0) {
      data->vertices_count++;
      sscanf(line, "v %lf %lf %lf", &x, &y, &z);
      if (!setted) {
        setted = 1;
        data->max_x = x;
        data->max_y = y;
        data->max_z = z;
        data->min_x = x;
        data->min_y = y;
        data->min_z = z;
      }
      if (data->max_x < x) data->max_x = x;
      if (data->max_y < y) data->max_y = y;
      if (data->max_z < z) data->max_z = z;
      if (data->min_x > x) data->min_x = x;
      if (data->min_y > y) data->min_y = y;
      if (data->min_z > z) data->min_z = z;
    }
    if (strncmp(line, "f ", 2) == 0) {
      char *vertex_index = line + 2;
      int index;
      while (sscanf(vertex_index, "%d", &index) == 1) {
        vertex_index = strchr(vertex_index, ' ');
        data->indices_count++;
        if (vertex_index == NULL) {
          break;
        }
        vertex_index++;
      }
      data->edges_count++;
      data->indices_count++;
    }
  }

  return count;
}

void obj_mem_alloc(obj_data *data) {
  data->vertices_arr = calloc(data->vertices_count * 3, sizeof(size_t));
  data->indices_arr = calloc(data->indices_count * 8, sizeof(size_t));
}
void parsing_value(FILE *file, obj_data *data) {
  size_t count_v = 0;
  size_t count_i = 0;
  char line[1000];
  double x, y, z;
  char *token;

  fseek(file, 0, SEEK_SET);

  while (fgets(line, sizeof(line), file) != NULL) {
    if (strncmp(line, "v ", 2) == 0) {
      sscanf(line, "v %lf %lf %lf", &x, &y, &z);
      data->vertices_arr[count_v++] =
          ((x - data->min_x) * 2 / (data->max_x - data->min_x)) - 1;
      data->vertices_arr[count_v++] =
          ((y - data->min_y) * 2 / (data->max_y - data->min_y)) - 1;
      data->vertices_arr[count_v++] =
          ((z - data->min_z) * 2 / (data->max_z - data->min_z)) - 1;

    } else if (strncmp(line, "f ", 2) == 0) {
      token = strtok(line + 2, " ");

      int index;
      int first_index = -1;
      int prev_index = -1;

      while (token != NULL) {
        sscanf(token, "%d", &index);

        if (first_index == -1) {
          first_index = index - 1;
        }
        if (prev_index != -1) {
          data->indices_arr[count_i++] = prev_index;
          data->indices_arr[count_i++] = index - 1;
        }

        prev_index = index - 1;
        token = strtok(NULL, " \n");
      }

      if (prev_index != -1 && first_index != -1) {
        data->indices_arr[count_i++] = prev_index;
        data->indices_arr[count_i++] = first_index;
      }
    }
  }
}
void clean_mem_obj(obj_data *data) {
  if (data->indices_arr != NULL) free(data->indices_arr);
  data->indices_arr = NULL;
  if (data->vertices_arr != NULL) free(data->vertices_arr);
  data->vertices_arr = NULL;
}