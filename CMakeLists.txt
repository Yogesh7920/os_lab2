cmake_minimum_required(VERSION 3.17)
project(lab2 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab2 src/main.c src/helper.c include/helper.h src/image.c include/image.h src/matrixmath.c include/matrixmath.h src/ppm.c include/ppm.h)