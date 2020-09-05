
#ifndef LAB2_PPM_H
#define LAB2_PPM_H

typedef struct {
    unsigned char red,green,blue;
} PPMPixel;

typedef struct {
    int x, y;
    PPMPixel *data;
} PPMImage;

PPMImage *readPPM(const char *filename);
void writePPM(const char *filename, PPMImage *img);
void changeColorPPM(PPMImage *img);

#endif //LAB2_PPM_H
