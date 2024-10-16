#include <check.h>

#include "../affine_transformations.h"
#include "../parcer.h"

#define EPS 1e-07

START_TEST(parser_1) {
  obj_data d = {0};
  char filename[] = "../obj_files/xxx.obj";
  int res = parse_obj_file(filename, &d);
  ck_assert_int_eq(res, ERR);
}
END_TEST

START_TEST(parser_2) {
  obj_data d = {0};
  char *filename = NULL;
  int res = parse_obj_file(filename, &d);
  ck_assert_int_eq(res, ERR);
}
END_TEST

START_TEST(affine_rotate_X_1) {
  obj_data d = {0};
  char filename[] = "obj_files/cube.obj";
  double vertices_arr[24] = {
    -1.000000, -1.000000, -1.000000, 
    -1.000000, -1.000000, 1.000000, 
    -1.000000, 1.000000, -1.000000, 
    -1.000000, 1.000000, 1.000000, 
    1.000000, -1.000000, -1.000000, 
    1.000000, -1.000000, 1.000000, 
    1.000000, 1.000000, -1.000000, 
    1.000000, 1.000000, 1.000000};
  obj_data test_obj = {0};
  test_obj.vertices_count = 8;
  test_obj.vertices_arr = vertices_arr;
  parse_obj_file(filename, &d);
  rotate_X(&d, 30);
  rotate_X(&test_obj, 30);
  printf("\n%ld\n",d.edges_count);
  ck_assert_int_eq(d.edges_count, 10);
  ck_assert_int_eq(d.vertices_count, 8);

  int i = 0;
  while (i < (int)d.vertices_count * 3) {
    ck_assert_double_eq_tol(d.vertices_arr[i], test_obj.vertices_arr[i], EPS);
    i++;
  }
  clean_mem_obj(&d);
}
END_TEST

START_TEST(affine_rotate_X_2) {
  obj_data d = {0};
  char filename[] = "obj_files/cube.obj";
  double vertices_arr[24] = {
    -1.000000, -1.000000, -1.000000, 
    -1.000000, -1.000000, 1.000000, 
    -1.000000, 1.000000, -1.000000, 
    -1.000000, 1.000000, 1.000000, 
    1.000000, -1.000000, -1.000000, 
    1.000000, -1.000000, 1.000000, 
    1.000000, 1.000000, -1.000000, 
    1.000000, 1.000000, 1.000000};
  obj_data test_obj = {0};
  test_obj.vertices_count = 8;
  test_obj.vertices_arr = vertices_arr;
  parse_obj_file(filename, &d);
  rotate_X(&d, -30);
  rotate_X(&test_obj, -30);
  ck_assert_int_eq(d.edges_count, 10);
  ck_assert_int_eq(d.vertices_count, 8);

  int i = 0;
  while (i < (int)d.vertices_count * 3) {
    ck_assert_double_eq_tol(d.vertices_arr[i], test_obj.vertices_arr[i], EPS);
    i++;
  }
  clean_mem_obj(&d);
}
END_TEST

START_TEST(affine_rotate_X_3) {
obj_data d = {0};
  char filename[] = "obj_files/cube.obj";
  double vertices_arr[24] = {
    -1.000000, -1.000000, -1.000000, 
    -1.000000, -1.000000, 1.000000, 
    -1.000000, 1.000000, -1.000000, 
    -1.000000, 1.000000, 1.000000, 
    1.000000, -1.000000, -1.000000, 
    1.000000, -1.000000, 1.000000, 
    1.000000, 1.000000, -1.000000, 
    1.000000, 1.000000, 1.000000};
  obj_data test_obj = {0};
  test_obj.vertices_count = 8;
  test_obj.vertices_arr = vertices_arr;
  parse_obj_file(filename, &d);
  rotate_X(&d, 2000);
  rotate_X(&test_obj, 2000);
  ck_assert_int_eq(d.edges_count, 10);
  ck_assert_int_eq(d.vertices_count, 8);

  int i = 0;
  while (i < (int)d.vertices_count * 3) {
    ck_assert_double_eq_tol(d.vertices_arr[i], test_obj.vertices_arr[i], EPS);
    i++;
  }
  clean_mem_obj(&d);
}
END_TEST

START_TEST(affine_rotate_Y_1) {
obj_data d = {0};
  char filename[] = "obj_files/cube.obj";
  double vertices_arr[24] = {
    -1.000000, -1.000000, -1.000000, 
    -1.000000, -1.000000, 1.000000, 
    -1.000000, 1.000000, -1.000000, 
    -1.000000, 1.000000, 1.000000, 
    1.000000, -1.000000, -1.000000, 
    1.000000, -1.000000, 1.000000, 
    1.000000, 1.000000, -1.000000, 
    1.000000, 1.000000, 1.000000};
  obj_data test_obj = {0};
  test_obj.vertices_count = 8;
  test_obj.vertices_arr = vertices_arr;
  parse_obj_file(filename, &d);
  rotate_Y(&d, 30);
  rotate_Y(&test_obj, 30);
  ck_assert_int_eq(d.edges_count, 10);
  ck_assert_int_eq(d.vertices_count, 8);

  int i = 0;
  while (i < (int)d.vertices_count * 3) {
    ck_assert_double_eq_tol(d.vertices_arr[i], test_obj.vertices_arr[i], EPS);
    i++;
  }
  clean_mem_obj(&d);
}
END_TEST

START_TEST(affine_rotate_Y_2) {
obj_data d = {0};
  char filename[] = "obj_files/cube.obj";
  double vertices_arr[24] = {
    -1.000000, -1.000000, -1.000000, 
    -1.000000, -1.000000, 1.000000, 
    -1.000000, 1.000000, -1.000000, 
    -1.000000, 1.000000, 1.000000, 
    1.000000, -1.000000, -1.000000, 
    1.000000, -1.000000, 1.000000, 
    1.000000, 1.000000, -1.000000, 
    1.000000, 1.000000, 1.000000};
  obj_data test_obj = {0};
  test_obj.vertices_count = 8;
  test_obj.vertices_arr = vertices_arr;
  parse_obj_file(filename, &d);
  rotate_Y(&d, -30);
  rotate_Y(&test_obj, -30);
  ck_assert_int_eq(d.edges_count, 10);
  ck_assert_int_eq(d.vertices_count, 8);

  int i = 0;
  while (i < (int)d.vertices_count * 3) {
    ck_assert_double_eq_tol(d.vertices_arr[i], test_obj.vertices_arr[i], EPS);
    i++;
  }
  clean_mem_obj(&d);
}
END_TEST

START_TEST(affine_rotate_Y_3) {
obj_data d = {0};
  char filename[] = "obj_files/cube.obj";
  double vertices_arr[24] = {
    -1.000000, -1.000000, -1.000000, 
    -1.000000, -1.000000, 1.000000, 
    -1.000000, 1.000000, -1.000000, 
    -1.000000, 1.000000, 1.000000, 
    1.000000, -1.000000, -1.000000, 
    1.000000, -1.000000, 1.000000, 
    1.000000, 1.000000, -1.000000, 
    1.000000, 1.000000, 1.000000};
  obj_data test_obj = {0};
  test_obj.vertices_count = 8;
  test_obj.vertices_arr = vertices_arr;
  parse_obj_file(filename, &d);
  rotate_Y(&d, 2000000);
  rotate_Y(&test_obj, 2000000);
  ck_assert_int_eq(d.edges_count, 10);
  ck_assert_int_eq(d.vertices_count, 8);

  int i = 0;
  while (i < (int)d.vertices_count * 3) {
    ck_assert_double_eq_tol(d.vertices_arr[i], test_obj.vertices_arr[i], EPS);
    i++;
  }
  clean_mem_obj(&d);
}
END_TEST

START_TEST(affine_rotate_Z_1) {
obj_data d = {0};
  char filename[] = "obj_files/cube.obj";
  double vertices_arr[24] = {
    -1.000000, -1.000000, -1.000000, 
    -1.000000, -1.000000, 1.000000, 
    -1.000000, 1.000000, -1.000000, 
    -1.000000, 1.000000, 1.000000, 
    1.000000, -1.000000, -1.000000, 
    1.000000, -1.000000, 1.000000, 
    1.000000, 1.000000, -1.000000, 
    1.000000, 1.000000, 1.000000};
  obj_data test_obj = {0};
  test_obj.vertices_count = 8;
  test_obj.vertices_arr = vertices_arr;
  parse_obj_file(filename, &d);
  rotate_Z(&d, 30);
  rotate_Z(&test_obj, 30);
  ck_assert_int_eq(d.edges_count, 10);
  ck_assert_int_eq(d.vertices_count, 8);

  int i = 0;
  while (i < (int)d.vertices_count * 3) {
    ck_assert_double_eq_tol(d.vertices_arr[i], test_obj.vertices_arr[i], EPS);
    i++;
  }
  clean_mem_obj(&d);
}
END_TEST

START_TEST(affine_rotate_Z_2) {
obj_data d = {0};
  char filename[] = "obj_files/cube.obj";
  double vertices_arr[24] = {
    -1.000000, -1.000000, -1.000000, 
    -1.000000, -1.000000, 1.000000, 
    -1.000000, 1.000000, -1.000000, 
    -1.000000, 1.000000, 1.000000, 
    1.000000, -1.000000, -1.000000, 
    1.000000, -1.000000, 1.000000, 
    1.000000, 1.000000, -1.000000, 
    1.000000, 1.000000, 1.000000};
  obj_data test_obj = {0};
  test_obj.vertices_count = 8;
  test_obj.vertices_arr = vertices_arr;
  parse_obj_file(filename, &d);
  rotate_Z(&d, -30);
  rotate_Z(&test_obj, -30);
  ck_assert_int_eq(d.edges_count, 10);
  ck_assert_int_eq(d.vertices_count, 8);

  int i = 0;
  while (i < (int)d.vertices_count * 3) {
    ck_assert_double_eq_tol(d.vertices_arr[i], test_obj.vertices_arr[i], EPS);
    i++;
  }
  clean_mem_obj(&d);
}
END_TEST

START_TEST(affine_rotate_Z_3) {
obj_data d = {0};
  char filename[] = "obj_files/cube.obj";
  double vertices_arr[24] = {
    -1.000000, -1.000000, -1.000000, 
    -1.000000, -1.000000, 1.000000, 
    -1.000000, 1.000000, -1.000000, 
    -1.000000, 1.000000, 1.000000, 
    1.000000, -1.000000, -1.000000, 
    1.000000, -1.000000, 1.000000, 
    1.000000, 1.000000, -1.000000, 
    1.000000, 1.000000, 1.000000};
  obj_data test_obj = {0};
  test_obj.vertices_count = 8;
  test_obj.vertices_arr = vertices_arr;
  parse_obj_file(filename, &d);
  rotate_Z(&d, 2000000);
  rotate_Z(&test_obj, 2000000);
  ck_assert_int_eq(d.edges_count, 10);
  ck_assert_int_eq(d.vertices_count, 8);

  int i = 0;
  while (i < (int)d.vertices_count * 3) {
    ck_assert_double_eq_tol(d.vertices_arr[i], test_obj.vertices_arr[i], EPS);
    i++;
  }
  clean_mem_obj(&d);
}
END_TEST

START_TEST(affine_scale_1) {
obj_data d = {0};
  char filename[] = "obj_files/cube.obj";
  double vertices_arr[24] = {
    -1.000000, -1.000000, -1.000000, 
    -1.000000, -1.000000, 1.000000, 
    -1.000000, 1.000000, -1.000000, 
    -1.000000, 1.000000, 1.000000, 
    1.000000, -1.000000, -1.000000, 
    1.000000, -1.000000, 1.000000, 
    1.000000, 1.000000, -1.000000, 
    1.000000, 1.000000, 1.000000};
  obj_data test_obj = {0};
  test_obj.vertices_count = 8;
  test_obj.vertices_arr = vertices_arr;
  parse_obj_file(filename, &d);
  scale(&d, 30);
  scale(&test_obj, 30);
  ck_assert_int_eq(d.edges_count, 10);
  ck_assert_int_eq(d.vertices_count, 8);

  int i = 0;
  while (i < (int)d.vertices_count * 3) {
    ck_assert_double_eq_tol(d.vertices_arr[i], test_obj.vertices_arr[i], EPS);
    i++;
  }
  clean_mem_obj(&d);
}
END_TEST

START_TEST(affine_scale_2) {
obj_data d = {0};
  char filename[] = "obj_files/cube.obj";
  double vertices_arr[24] = {
    -1.000000, -1.000000, -1.000000, 
    -1.000000, -1.000000, 1.000000, 
    -1.000000, 1.000000, -1.000000, 
    -1.000000, 1.000000, 1.000000, 
    1.000000, -1.000000, -1.000000, 
    1.000000, -1.000000, 1.000000, 
    1.000000, 1.000000, -1.000000, 
    1.000000, 1.000000, 1.000000};
  obj_data test_obj = {0};
  test_obj.vertices_count = 8;
  test_obj.vertices_arr = vertices_arr;
  parse_obj_file(filename, &d);
  scale(&d, 0.3);
  scale(&test_obj, 0.3);
  ck_assert_int_eq(d.edges_count, 10);
  ck_assert_int_eq(d.vertices_count, 8);

  int i = 0;
  while (i < (int)d.vertices_count * 3) {
    ck_assert_double_eq_tol(d.vertices_arr[i], test_obj.vertices_arr[i], EPS);
    i++;
  }
  clean_mem_obj(&d);
}
END_TEST

START_TEST(affine_scale_3) {
obj_data d = {0};
  char filename[] = "obj_files/cube.obj";
  double vertices_arr[24] = {
    -1.000000, -1.000000, -1.000000, 
    -1.000000, -1.000000, 1.000000, 
    -1.000000, 1.000000, -1.000000, 
    -1.000000, 1.000000, 1.000000, 
    1.000000, -1.000000, -1.000000, 
    1.000000, -1.000000, 1.000000, 
    1.000000, 1.000000, -1.000000, 
    1.000000, 1.000000, 1.000000};
  obj_data test_obj = {0};
  test_obj.vertices_count = 8;
  test_obj.vertices_arr = vertices_arr;
  parse_obj_file(filename, &d);
  scale(&d, 3333333);
  scale(&test_obj, 3333333);
  ck_assert_int_eq(d.edges_count, 10);
  ck_assert_int_eq(d.vertices_count, 8);

  int i = 0;
  while (i < (int)d.vertices_count * 3) {
    ck_assert_double_eq_tol(d.vertices_arr[i], test_obj.vertices_arr[i], EPS);
    i++;
  }
  clean_mem_obj(&d);
}
END_TEST

START_TEST(affine_move_X_1) {
obj_data d = {0};
  char filename[] = "obj_files/cube.obj";
  double vertices_arr[24] = {
    -1.000000, -1.000000, -1.000000, 
    -1.000000, -1.000000, 1.000000, 
    -1.000000, 1.000000, -1.000000, 
    -1.000000, 1.000000, 1.000000, 
    1.000000, -1.000000, -1.000000, 
    1.000000, -1.000000, 1.000000, 
    1.000000, 1.000000, -1.000000, 
    1.000000, 1.000000, 1.000000};
  obj_data test_obj = {0};
  test_obj.vertices_count = 8;
  test_obj.vertices_arr = vertices_arr;
  parse_obj_file(filename, &d);
  move_X(&d, 3);
  move_X(&test_obj, 3);
  ck_assert_int_eq(d.edges_count, 10);
  ck_assert_int_eq(d.vertices_count, 8);

  int i = 0;
  while (i < (int)d.vertices_count * 3) {
    ck_assert_double_eq_tol(d.vertices_arr[i], test_obj.vertices_arr[i], EPS);
    i++;
  }
  clean_mem_obj(&d);
}
END_TEST

START_TEST(affine_move_X_2) {
obj_data d = {0};
  char filename[] = "obj_files/cube.obj";
  double vertices_arr[24] = {
    -1.000000, -1.000000, -1.000000, 
    -1.000000, -1.000000, 1.000000, 
    -1.000000, 1.000000, -1.000000, 
    -1.000000, 1.000000, 1.000000, 
    1.000000, -1.000000, -1.000000, 
    1.000000, -1.000000, 1.000000, 
    1.000000, 1.000000, -1.000000, 
    1.000000, 1.000000, 1.000000};
  obj_data test_obj = {0};
  test_obj.vertices_count = 8;
  test_obj.vertices_arr = vertices_arr;
  parse_obj_file(filename, &d);
  move_X(&d, -3);
  move_X(&test_obj, -3);
  ck_assert_int_eq(d.edges_count, 10);
  ck_assert_int_eq(d.vertices_count, 8);

  int i = 0;
  while (i < (int)d.vertices_count * 3) {
    ck_assert_double_eq_tol(d.vertices_arr[i], test_obj.vertices_arr[i], EPS);
    i++;
  }
  clean_mem_obj(&d);
}
END_TEST

START_TEST(affine_move_X_3) {
obj_data d = {0};
  char filename[] = "obj_files/cube.obj";
  double vertices_arr[24] = {
    -1.000000, -1.000000, -1.000000, 
    -1.000000, -1.000000, 1.000000, 
    -1.000000, 1.000000, -1.000000, 
    -1.000000, 1.000000, 1.000000, 
    1.000000, -1.000000, -1.000000, 
    1.000000, -1.000000, 1.000000, 
    1.000000, 1.000000, -1.000000, 
    1.000000, 1.000000, 1.000000};
  obj_data test_obj = {0};
  test_obj.vertices_count = 8;
  test_obj.vertices_arr = vertices_arr;
  parse_obj_file(filename, &d);
  move_X(&d, -0.5);
  move_X(&test_obj, -0.5);
  ck_assert_int_eq(d.edges_count, 10);
  ck_assert_int_eq(d.vertices_count, 8);

  int i = 0;
  while (i < (int)d.vertices_count * 3) {
    ck_assert_double_eq_tol(d.vertices_arr[i], test_obj.vertices_arr[i], EPS);
    i++;
  }
  clean_mem_obj(&d);
}
END_TEST

START_TEST(affine_move_Y_1) {
obj_data d = {0};
  char filename[] = "obj_files/cube.obj";
  double vertices_arr[24] = {
    -1.000000, -1.000000, -1.000000, 
    -1.000000, -1.000000, 1.000000, 
    -1.000000, 1.000000, -1.000000, 
    -1.000000, 1.000000, 1.000000, 
    1.000000, -1.000000, -1.000000, 
    1.000000, -1.000000, 1.000000, 
    1.000000, 1.000000, -1.000000, 
    1.000000, 1.000000, 1.000000};
  obj_data test_obj = {0};
  test_obj.vertices_count = 8;
  test_obj.vertices_arr = vertices_arr;
  parse_obj_file(filename, &d);
  move_Y(&d, 3);
  move_Y(&test_obj, 3);
  ck_assert_int_eq(d.edges_count, 10);
  ck_assert_int_eq(d.vertices_count, 8);

  int i = 0;
  while (i < (int)d.vertices_count * 3) {
    ck_assert_double_eq_tol(d.vertices_arr[i], test_obj.vertices_arr[i], EPS);
    i++;
  }
  clean_mem_obj(&d);
}
END_TEST

START_TEST(affine_move_Y_2) {
obj_data d = {0};
  char filename[] = "obj_files/cube.obj";
  double vertices_arr[24] = {
    -1.000000, -1.000000, -1.000000, 
    -1.000000, -1.000000, 1.000000, 
    -1.000000, 1.000000, -1.000000, 
    -1.000000, 1.000000, 1.000000, 
    1.000000, -1.000000, -1.000000, 
    1.000000, -1.000000, 1.000000, 
    1.000000, 1.000000, -1.000000, 
    1.000000, 1.000000, 1.000000};
  obj_data test_obj = {0};
  test_obj.vertices_count = 8;
  test_obj.vertices_arr = vertices_arr;
  parse_obj_file(filename, &d);
  move_Y(&d, -3);
  move_Y(&test_obj, -3);
  ck_assert_int_eq(d.edges_count, 10);
  ck_assert_int_eq(d.vertices_count, 8);

  int i = 0;
  while (i < (int)d.vertices_count * 3) {
    ck_assert_double_eq_tol(d.vertices_arr[i], test_obj.vertices_arr[i], EPS);
    i++;
  }
  clean_mem_obj(&d);
}
END_TEST

START_TEST(affine_move_Y_3) {
obj_data d = {0};
  char filename[] = "obj_files/cube.obj";
  double vertices_arr[24] = {
    -1.000000, -1.000000, -1.000000, 
    -1.000000, -1.000000, 1.000000, 
    -1.000000, 1.000000, -1.000000, 
    -1.000000, 1.000000, 1.000000, 
    1.000000, -1.000000, -1.000000, 
    1.000000, -1.000000, 1.000000, 
    1.000000, 1.000000, -1.000000, 
    1.000000, 1.000000, 1.000000};
  obj_data test_obj = {0};
  test_obj.vertices_count = 8;
  test_obj.vertices_arr = vertices_arr;
  parse_obj_file(filename, &d);
  move_Y(&d, -0.3);
  move_Y(&test_obj, -0.3);
  ck_assert_int_eq(d.edges_count, 10);
  ck_assert_int_eq(d.vertices_count, 8);

  int i = 0;
  while (i < (int)d.vertices_count * 3) {
    ck_assert_double_eq_tol(d.vertices_arr[i], test_obj.vertices_arr[i], EPS);
    i++;
  }
  clean_mem_obj(&d);
}
END_TEST

START_TEST(affine_move_Z_1) {
obj_data d = {0};
  char filename[] = "obj_files/cube.obj";
  double vertices_arr[24] = {
    -1.000000, -1.000000, -1.000000, 
    -1.000000, -1.000000, 1.000000, 
    -1.000000, 1.000000, -1.000000, 
    -1.000000, 1.000000, 1.000000, 
    1.000000, -1.000000, -1.000000, 
    1.000000, -1.000000, 1.000000, 
    1.000000, 1.000000, -1.000000, 
    1.000000, 1.000000, 1.000000};
  obj_data test_obj = {0};
  test_obj.vertices_count = 8;
  test_obj.vertices_arr = vertices_arr;
  parse_obj_file(filename, &d);
  move_Z(&d, 3);
  move_Z(&test_obj, 3);
  ck_assert_int_eq(d.edges_count, 10);
  ck_assert_int_eq(d.vertices_count, 8);

  int i = 0;
  while (i < (int)d.vertices_count * 3) {
    ck_assert_double_eq_tol(d.vertices_arr[i], test_obj.vertices_arr[i], EPS);
    i++;
  }
  clean_mem_obj(&d);
}
END_TEST

START_TEST(affine_move_Z_2) {
obj_data d = {0};
  char filename[] = "obj_files/cube.obj";
  double vertices_arr[24] = {
    -1.000000, -1.000000, -1.000000, 
    -1.000000, -1.000000, 1.000000, 
    -1.000000, 1.000000, -1.000000, 
    -1.000000, 1.000000, 1.000000, 
    1.000000, -1.000000, -1.000000, 
    1.000000, -1.000000, 1.000000, 
    1.000000, 1.000000, -1.000000, 
    1.000000, 1.000000, 1.000000};
  obj_data test_obj = {0};
  test_obj.vertices_count = 8;
  test_obj.vertices_arr = vertices_arr;
  parse_obj_file(filename, &d);
  move_Z(&d, -3);
  move_Z(&test_obj, -3);
  ck_assert_int_eq(d.edges_count, 10);
  ck_assert_int_eq(d.vertices_count, 8);

  int i = 0;
  while (i < (int)d.vertices_count * 3) {
    ck_assert_double_eq_tol(d.vertices_arr[i], test_obj.vertices_arr[i], EPS);
    i++;
  }
  clean_mem_obj(&d);
}
END_TEST

START_TEST(affine_move_Z_3) {
obj_data d = {0};
  char filename[] = "obj_files/cube.obj";
  double vertices_arr[24] = {
    -1.000000, -1.000000, -1.000000, 
    -1.000000, -1.000000, 1.000000, 
    -1.000000, 1.000000, -1.000000, 
    -1.000000, 1.000000, 1.000000, 
    1.000000, -1.000000, -1.000000, 
    1.000000, -1.000000, 1.000000, 
    1.000000, 1.000000, -1.000000, 
    1.000000, 1.000000, 1.000000};
  obj_data test_obj = {0};
  test_obj.vertices_count = 8;
  test_obj.vertices_arr = vertices_arr;
  parse_obj_file(filename, &d);
  move_Z(&d, -0.3);
  move_Z(&test_obj, -0.3);
  ck_assert_int_eq(d.edges_count, 10);
  ck_assert_int_eq(d.vertices_count, 8);

  int i = 0;
  while (i < (int)d.vertices_count * 3) {
    ck_assert_double_eq_tol(d.vertices_arr[i], test_obj.vertices_arr[i], EPS);
    i++;
  }
  clean_mem_obj(&d);
}
END_TEST

Suite *lib_suite(void) {
  Suite *s;
  s = suite_create("Check");
  TCase *tc_parser_1;
  tc_parser_1 = tcase_create("parser_1");
  suite_add_tcase(s, tc_parser_1);
  tcase_add_test(tc_parser_1, parser_1);

  TCase *tc_parser_2;
  tc_parser_2 = tcase_create("parser_2");
  suite_add_tcase(s, tc_parser_2);
  tcase_add_test(tc_parser_2, parser_2);

  TCase *tc_affine_rotate_X_1;
  tc_affine_rotate_X_1 = tcase_create("affine_rotate_X_1");
  suite_add_tcase(s, tc_affine_rotate_X_1);
  tcase_add_test(tc_affine_rotate_X_1, affine_rotate_X_1);

  TCase *tc_affine_rotate_X_2;
  tc_affine_rotate_X_2 = tcase_create("affine_rotate_X_2");
  suite_add_tcase(s, tc_affine_rotate_X_2);
  tcase_add_test(tc_affine_rotate_X_2, affine_rotate_X_2);

  TCase *tc_affine_rotate_X_3;
  tc_affine_rotate_X_3 = tcase_create("affine_rotate_X_3");
  suite_add_tcase(s, tc_affine_rotate_X_3);
  tcase_add_test(tc_affine_rotate_X_3, affine_rotate_X_3);

  TCase *tc_affine_rotate_Y_1;
  tc_affine_rotate_Y_1 = tcase_create("affine_rotate_Y_1");
  suite_add_tcase(s, tc_affine_rotate_Y_1);
  tcase_add_test(tc_affine_rotate_Y_1, affine_rotate_Y_1);

  TCase *tc_affine_rotate_Y_2;
  tc_affine_rotate_Y_2 = tcase_create("affine_rotate_Y_2");
  suite_add_tcase(s, tc_affine_rotate_Y_2);
  tcase_add_test(tc_affine_rotate_Y_2, affine_rotate_Y_2);

  TCase *tc_affine_rotate_Y_3;
  tc_affine_rotate_Y_3 = tcase_create("affine_rotate_Y_3");
  suite_add_tcase(s, tc_affine_rotate_Y_3);
  tcase_add_test(tc_affine_rotate_Y_3, affine_rotate_Y_3);

  TCase *tc_affine_rotate_Z_1;
  tc_affine_rotate_Z_1 = tcase_create("affine_rotate_Z_1");
  suite_add_tcase(s, tc_affine_rotate_Z_1);
  tcase_add_test(tc_affine_rotate_Z_1, affine_rotate_Z_1);

  TCase *tc_affine_rotate_Z_2;
  tc_affine_rotate_Z_2 = tcase_create("affine_rotate_Z_2");
  suite_add_tcase(s, tc_affine_rotate_Z_2);
  tcase_add_test(tc_affine_rotate_Z_2, affine_rotate_Z_2);

  TCase *tc_affine_rotate_Z_3;
  tc_affine_rotate_Z_3 = tcase_create("affine_rotate_Z_3");
  suite_add_tcase(s, tc_affine_rotate_Z_3);
  tcase_add_test(tc_affine_rotate_Z_3, affine_rotate_Z_3);

  TCase *tc_affine_scale_1;
  tc_affine_scale_1 = tcase_create("affine_scale_1");
  suite_add_tcase(s, tc_affine_scale_1);
  tcase_add_test(tc_affine_scale_1, affine_scale_1);

  TCase *tc_affine_scale_2;
  tc_affine_scale_2 = tcase_create("affine_scale_2");
  suite_add_tcase(s, tc_affine_scale_2);
  tcase_add_test(tc_affine_scale_2, affine_scale_2);

  TCase *tc_affine_scale_3;
  tc_affine_scale_3 = tcase_create("affine_scale_3");
  suite_add_tcase(s, tc_affine_scale_3);
  tcase_add_test(tc_affine_scale_3, affine_scale_3);

  TCase *tc_affine_move_X_1;
  tc_affine_move_X_1 = tcase_create("affine_move_X_1");
  suite_add_tcase(s, tc_affine_move_X_1);
  tcase_add_test(tc_affine_move_X_1, affine_move_X_1);

  TCase *tc_affine_move_X_2;
  tc_affine_move_X_2 = tcase_create("affine_move_X_2");
  suite_add_tcase(s, tc_affine_move_X_2);
  tcase_add_test(tc_affine_move_X_2, affine_move_X_2);

  TCase *tc_affine_move_X_3;
  tc_affine_move_X_3 = tcase_create("affine_move_X_3");
  suite_add_tcase(s, tc_affine_move_X_3);
  tcase_add_test(tc_affine_move_X_3, affine_move_X_3);

  TCase *tc_affine_move_Y_1;
  tc_affine_move_Y_1 = tcase_create("affine_move_Y_1");
  suite_add_tcase(s, tc_affine_move_Y_1);
  tcase_add_test(tc_affine_move_Y_1, affine_move_Y_1);

  TCase *tc_affine_move_Y_2;
  tc_affine_move_Y_2 = tcase_create("affine_move_Y_2");
  suite_add_tcase(s, tc_affine_move_Y_2);
  tcase_add_test(tc_affine_move_Y_2, affine_move_Y_2);

  TCase *tc_affine_move_Y_3;
  tc_affine_move_Y_3 = tcase_create("affine_move_Y_3");
  suite_add_tcase(s, tc_affine_move_Y_3);
  tcase_add_test(tc_affine_move_Y_3, affine_move_Y_3);

  TCase *tc_affine_move_Z_1;
  tc_affine_move_Z_1 = tcase_create("affine_move_Z_1");
  suite_add_tcase(s, tc_affine_move_Z_1);
  tcase_add_test(tc_affine_move_Z_1, affine_move_Z_1);

  TCase *tc_affine_move_Z_2;
  tc_affine_move_Z_2 = tcase_create("affine_move_Z_2");
  suite_add_tcase(s, tc_affine_move_Z_2);
  tcase_add_test(tc_affine_move_Z_2, affine_move_Z_2);

  TCase *tc_affine_move_Z_3;
  tc_affine_move_Z_3 = tcase_create("affine_move_Z_3");
  suite_add_tcase(s, tc_affine_move_Z_3);
  tcase_add_test(tc_affine_move_Z_3, affine_move_Z_3);

  return s;
}

int main(void) {
  Suite *s;
  SRunner *sr;
  s = lib_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
  return 0;
}