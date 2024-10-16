CC = gcc
DOXYFILE := Doxyfile
GCOV = -fprofile-arcs -ftest-coverage
OS = $(shell uname)
QMAKE = /usr/lib/qt6/bin/qmake
INSTALL_DIR = 3DViewer
ifeq ($(OS), Linux)
  BUILD_DIR = 3Dwiew/build/Desktop_Qt_6_6_3_MinGW_64_bit-Debug
  APP_DIR=
  LIBS = -lcheck -lm -lpthread -lsubunit -lrt
  OPEN = xdg-open
else
  BUILD_DIR = 3Dwiew/build/Desktop_Qt_6_6_3_MinGW_64_bit-Debug
  APP_DIR=3D_Viewer_v1.app/Contents/MacOS
  LIBS = -lcheck
  OPEN = open
endif

all: clean build

build:
	$(QMAKE) -o $(BUILD_DIR)/Makefile ./3Dwiew/3Dwiew.pro
	make -C $(BUILD_DIR)/

rebuild: clean all

install:
	mkdir $(INSTALL_DIR)
	install $(BUILD_DIR)$(APP_DIR)/3D_Viewer_v1 $(INSTALL_DIR)/3D_Viewer_v1

uninstall:
	rm -rf $(INSTALL_DIR)

dvi: 3Dwiew/$(DOXYFILE)
	@doxygen 3Dwiew/$(DOXYFILE)

dist:
	tar -cf 3D_Viewer_v1.tar Readme.md 3Dwiew Makefile 

tests: 3d_viewer.a
	cd 3Dwiew && $(CC) $(GCOV) tests/test.c 3d_viewer.a $(LIBS) -o test

3d_viewer.a: 
	cd 3Dwiew && $(CC) $(GCOV) -c parcer.c affine_transformations.c && \
	ar rcs 3d_viewer.a affine_transformations.o parcer.o && rm *.o

gcov_report: tests
	cd 3Dwiew && lcov -t "gcov_report" -o ../gcov_report.info -c -d . && \
	genhtml -o ../report ../gcov_report.info && $(OPEN) ../report/index.html

clang:
	clang-format --style=Google -i 3Dwiew/*.c 3Dwiew/*.cpp
clean:
	rm -rf ./report build* $(INSTALL_DIR)
	rm -rf 3Dwiew/build/Desktop_Qt_6_6_3_MinGW_64_bit-Debug/3Dwiew
	rm -f *.info  *.tar 3Dwiew/build/Desktop_Qt_6_6_3_MinGW_64_bit-Debug/*.o
	cd 3Dwiew && rm -f *.gcno *.gcda gcov_report *.o *.a test
	cd ..

