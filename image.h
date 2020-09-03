//
// Created by raghu on 9/3/2020.
//

#ifndef LAB2_IMAGE_H
#define LAB2_IMAGE_H

# include "matrixmath.h"
# include "ppm.h"

typedef struct Image
{
    matrix red;
    matrix green;
    matrix blue;
}*image;

image imgcreate(int m, int n);
image PPMImage2Image(PPMImage *img);
matrix bgr2grey(image img);
matrix maxpool(matrix X);
PPMImage *Image2PPMImage(image img);

#endif //LAB2_IMAGE_H
