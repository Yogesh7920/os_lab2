//
// Created by raghu on 9/3/2020.
//

#ifndef LAB2_MATRIXMATH_H
#define LAB2_MATRIXMATH_H

typedef struct Matrix {
    int m, n;
    float **M;
}*matrix;

matrix matcreate(int m, int n);
matrix matassign(matrix X, int v);
int multiply(matrix P, matrix A, matrix B);
void showmat(matrix X);


#endif //LAB2_MATRIXMATH_H
