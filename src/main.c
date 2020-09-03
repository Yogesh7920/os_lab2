# include<stdio.h>
# include<stdlib.h>
# include"../include/matrixmath.h"
# include"../include/helper.h"
# include"../include/image.h"
# include"../include/ppm.h"

int main() {
    PPMImage *ppm = readPPM("C:\\Users\\raghu\\CLionProjects\\lab2\\test\\earth.ppm");
    image img = PPMImage2Image(ppm);
    matrix grey = bgr2grey(img);
    img->blue = grey;
    img->green = valassign(matcreate(grey->m, grey->n), 0);
    img->red = valassign(matcreate(grey->m, grey->n), 0);
    PPMImage *finalppm = Image2PPMImage(img);
    writePPM("C:\\Users\\raghu\\CLionProjects\\lab2\\final.ppm", finalppm);
    return 0;
}
