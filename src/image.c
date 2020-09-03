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

matrix bgr2grey(image img) {
    matrix R = img->red;
    matrix B = img->blue;
    matrix G = img->green;
    if (R->n == G->n && G->n == B->n && R->m == G->m && G->m == B->m) {
        int n = R->n;
        int m = R->m;
        matrix ans = matcreate(m, n);
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                ans->M[i][j] = (R->M[i][j] + G->M[i][j] + B->M[i][j])/3;
            }
        }
        return ans;
    }
    else {
        print_exit("Diminsion of RGB doesn't match!");
    }
}

void blur(matrix X) {
    matrix kernel = matcreate(3, 3);
    float arr[3][3] = {
            {1,2,1},
            {2,4,2},
            {1,2,1}
    };
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            kernel->M[i][j] = arr[i][j];
        }
    }
    for (int i=1; i<X->m-1; i++) {
        for (int j=1; j<X->n-1; j++) {
            matrix temp = slice(X, i-1, i+2, j-1, j+2);
            matrix prod = matcreate(kernel->m, kernel->n);
            int flag = multiply(prod, temp, kernel);
            X->M[i][j] = sum(prod);
        }
    }
}



