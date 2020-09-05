# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include"matrixmath.h"
# include"helper.h"
# include"image.h"
# include"ppm.h"

int main(int argc, char *argv[]) {
    if (argc == 2 || argc == 3) {
        PPMImage *ppm = readPPM("earth.ppm");
        image img = PPMImage2Image(ppm);
        if (argc == 3) {
            if (!strcmp(argv[3], "T1")) {
                imgblur(img);
            }
            else if (!strcmp(argv[3], "T2")) {
                matrix grey = bgr2grey(img);
                ppmgrey(img, grey);
            }
        }
        else {
            imgblur(img);
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
