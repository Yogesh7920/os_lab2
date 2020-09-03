# include<stdio.h>
# include<stdlib.h>
# include"matrixmath.h"
# include"image.h"
# include"helper.h"

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

matrix maxpool(matrix X) {
    matrix res = matcreate(X->m-2, X->n-2);
    int p=0;
    int q;
    float temp;
    for (int i=1; i<X->n-1; i++) {
        q=0;
        for (int j=1; j<X->m-1; j++) {
            temp = -1;
            for (int a=-1; a<2; a++) {
                for (int b=0; b<3; b++) {
                    temp = max(temp, X->M[i+a][j+b]);
                }
            }
            res->M[p][q] = temp;
            q++;
        }
        p++;
    }
}


