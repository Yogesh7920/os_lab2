# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include"matrixmath.h"
# include"helper.h"
# include"image.h"
# include"ppm.h"

int main(int argc, char *argv[]) {
    if (argc == 1 || argc == 2) {
        FILE * fp;
        char in[20], out[20];
        fp = fopen(".config.txt", "r");
        fscanf(fp, "%s %s", in, out);
        PPMImage *ppm = readPPM(in);
        image img = PPMImage2Image(ppm);
        if (argc == 2) {
            if (!strcmp(argv[1], "T1")) {
                imgblur(img);
            }
            else if (!strcmp(argv[1],"T2")) {
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
        writePPM(out, finalppm);
        return 0;
    }
    else if (argc == 3) {
        PPMImage *ppm = readPPM(argv[1]);
        image img = PPMImage2Image(ppm);
        
        imgblur(img);
        matrix grey = bgr2grey(img);
        ppmgrey(img, grey);
        
        PPMImage *finalppm = Image2PPMImage(img);
        writePPM(argv[2], finalppm);
        return 0;
    }
    else {
        print_exit("Invalid Number of arguments");
    }
}