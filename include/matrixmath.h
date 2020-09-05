
#ifndef LAB2_MATRIXMATH_H
#define LAB2_MATRIXMATH_H

typedef struct Matrix {
    int m, n;
    float **M;
}*matrix;

matrix matcreate(int m, int n);
matrix valassign(matrix X, float v);
int multiply(matrix P, matrix A, matrix B);
void showmat(matrix X);
float sum(matrix X);
matrix slice(matrix X, int r1, int r2, int c1, int c2);

#endif //LAB2_MATRIXMATH_H
