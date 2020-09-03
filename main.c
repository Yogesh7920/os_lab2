# include<stdio.h>
# include<stdlib.h>
# include"matrixmath.h"
# include"helper.h"
# include"image.h"
# include"ppm.h"

int main() {
    PPMImage *ppm = readPPM("C:\\Users\\raghu\\CLionProjects\\lab2\\test\\earth.ppm");
    image img = PPMImage2Image(ppm);
    matrix grey = bgr2grey(img);
    img->blue = grey;
    img->green = matassign(matcreate(grey->m, grey->n), 0);
    img->red = matassign(matcreate(grey->m, grey->n), 0);
    PPMImage *finalppm = Image2PPMImage(img);
    writePPM("C:\\Users\\raghu\\CLionProjects\\lab2\\final.ppm", finalppm);
    return 0;
}
