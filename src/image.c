# include<stdio.h>
# include<stdlib.h>
# include"../include/matrixmath.h"
# include"../include/image.h"
# include"../include/helper.h"

image imgcreate(int m, int n) {
    image temp = (image)malloc(sizeof(struct Image));
    temp->red = matcreate(m, n);
    temp->green = matcreate(m, n);
    temp->blue = matcreate(m, n);
    return temp;
}

image PPMImage2Image(PPMImage *img) {
    int i;
    if(img){
        image res = imgcreate(img->y, img->x);
        i = 0;
        for (int a=0; a<img->y; a++) {
            for (int b=0; b<img->x; b++) {
                res->red->M[a][b] = img->data[i].red;
                res->green->M[a][b] = img->data[i].green;
                res->blue->M[a][b] = img->data[i].blue;
                i++;
            }
        }
        return res;
    }
    else {
        print_exit("Not a proper image");
    }
}

PPMImage *Image2PPMImage(image img) {
    PPMImage *ppm = (PPMImage *)malloc(sizeof(PPMImage));
    int m = img->red->m;
    int n = img->red->n;
    ppm->x = n;
    ppm->y = m;
    int c = 0;
    ppm->data = (PPMPixel*)malloc(n * m * sizeof(PPMPixel));
    for (int i=0;i<m;i++) {
        for (int j=0;j<n; j++) {
            ppm->data[c].red = (char)img->red->M[i][j];
            ppm->data[c].green = (char)img->green->M[i][j];
            ppm->data[c].blue = (char)img->blue->M[i][j];
            c++;
        }
    }
    return ppm;
}

void blur(matrix X) {
    matrix kernel = matcreate(3, 3);
    float arr[3][3] = {
            {(float)1/16, (float)1/8, (float)1/16},
            {(float)1/8, (float)1/4, (float)1/8},
            {(float)1/16, (float)1/8, (float)1/16}
    };
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            kernel->M[i][j] = arr[i][j];
        }
    }
    X->m = X->m-2;
    X->n = X->n-2;
    for (int i=1; i<X->m-1; i++) {
        for (int j=1; j<X->n-1; j++) {
            matrix temp = slice(X, i-1, i+2, j-1, j+2);
            matrix prod = matcreate(kernel->m, kernel->n);
            multiply(prod, temp, kernel);
            X->M[i][j] = sum(prod);
        }
    }
}


matrix bgr2grey(image img) { // T2
    matrix R = img->red;
    matrix B = img->blue;
    matrix G = img->green;
    matrix kernel = matcreate(1, 3);
    valassign(kernel, (float)1/3);
    if (R->n == G->n && G->n == B->n && R->m == G->m && G->m == B->m) {
        int n = R->n;
        int m = R->m;
        matrix ans = matcreate(m, n);
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                matrix temp = matcreate(1, 3);
                temp->M[0][0] = R->M[i][j];
                temp->M[0][1] = B->M[i][j];
                temp->M[0][2] = G->M[i][j];
                matrix prod = matcreate(kernel->m, kernel->n);
                multiply(prod, temp, kernel);
                ans->M[i][j] = sum(prod);
            }
        }
        return ans;
    }
    else {
        print_exit("Diminsion of RGB doesn't match!");
    }
}

void imgblur(image X) {
    blur(X->red);
    blur(X->green);
    blur(X->blue);
}

void ppmgrey(image img, matrix grey) {
    img->red = grey;
    img->green = grey;
    img->blue = grey;
}
