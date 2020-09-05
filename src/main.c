# include<stdio.h>
# include<stdlib.h>
# include"../include/matrixmath.h"
# include"../include/helper.h"
# include"../include/image.h"
# include"../include/ppm.h"

int main(int argc, char *argv[]) {
    if (argc == 2 || argc == 3) {
        PPMImage *ppm = readPPM(argv[1]);
        image img = PPMImage2Image(ppm);
        if (argv[3] != 'T2') {
            imgblur(img);
        }
        if (argv[3] != 'T1') {
            matrix grey = bgr2grey(img);
            ppmgrey(img, grey);
        }
        PPMImage *finalppm = Image2PPMImage(img);
        writePPM(argv[2], finalppm);
        return 0;
    }
    else {
        print_exit("Invalid Number of arguments");
    }
}
