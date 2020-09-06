# include<stdio.h>
# include<stdlib.h>

# include"matrixmath.h"
# include"helper.h"
# include"image.h"
# include"ppm.h"

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

matrix valassign(matrix X, float v) {
    for (int i=0;i<X->m;i++) {
        for (int j=0; j<X->n; j++) {
            X->M[i][j] = (float)v;
        }
    }
    return X;
}

int multiply(matrix P, matrix A, matrix B) {

    if (A->m != B->m && A->n != B->n) {
        printf("Cannot Multiply");
        return 1;
    }
    for (int i=0; i< A->m; i++) {
        for (int j=0; j < B->n; j++) {
            P->M[i][j] =  A->M[i][j] * B->M[i][j];
        }
    }

    return 0;
}

float sum(matrix X) {
    float sum = 0;
    for (int i=0; i<X->m; i++) {
        for (int j=0;j<X->n; j++) {
            sum += X->M[i][j];
        }
    }
    return sum;
}

matrix slice(matrix X, int r1, int r2, int c1, int c2) {
    matrix res = matcreate(r2-r1, c2-c1);
    int a=0;
    int b;
    for (int i=r1; i<r2; i++) {
        b = 0;
        for (int j=c1; j<c2; j++) {
            res->M[a][b] = X->M[i][j];
            b++;
        }
        a++;
    }
    return res;
}

void showmat(matrix X) {
    for (int i=0;i<X->n;i++) {
        for (int j=0; j<X->m; j++) {
            printf("%d ", (int)X->M[i][j]);
        }
        printf("\n");
    }
}
