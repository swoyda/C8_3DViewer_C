
#include "parcer.h"

int main() {
  const char* fin_path =
      "C:/Users/Dima/source/repos/C8_3DViewer_v1.0-1/cube.obj";
  obj_data data = {0, 0, 0, 0};
  parse_obj_file(fin_path, &data);
  print_obj_data(&data);
  obj_mem_clear(&data);
}