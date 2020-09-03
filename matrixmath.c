# include<stdio.h>
# include<stdlib.h>
# include"matrixmath.h"

matrix matcreate(int m, int n) {
    matrix temp = (matrix)malloc(sizeof(struct Matrix));
    temp->m = m;
    temp->n = n;

    float **arr = (float **)malloc(m*sizeof(float *));
    for (int i=0; i<m; i++) {
        arr[i] = (float *)malloc(n * sizeof(float));
    }
    temp->M = arr;
    return temp;
}

matrix matassign(matrix X, int v) {
    for (int i=0;i<X->m;i++) {
        for (int j=0; j<X->n; j++) {
            X->M[i][j] = v;
        }
    }
    return X;
}

int multiply(matrix P, matrix A, matrix B) {

    if (A->m != B->n) {
        printf("Cannot Multiply");
        return 1;
    }
    // for (int i=0; i< A->m; i++) {
    //     for (int j=0; j < B->n; j++) {
    //         for (int k=0; k<A->n; k++) {
    //             P->M[i][j] += A->M[i][k] * B->M[k][j];
    //         }
    //     }
    // }
    P->M[0][0] = A->M[0][0] + B->M[0][0];

    return 0;
}

void showmat(matrix X) {
    for (int i=0;i<X->n;i++) {
        for (int j=0; j<X->m; j++) {
            printf("%d ", (int)X->M[i][j]);
        }
        printf("\n");
    }
}
