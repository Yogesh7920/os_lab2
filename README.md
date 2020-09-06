# os_lab2 - Image Processing in C

## Requirements
  - imagemagick: for conversion of different format image to jpeg; taken care by make prepare.

## Important Note
 - Transformations
   - T1: Gaussian Blur with 3x3 kernel. Note the output of mxn size image will become m-2xn-2
   - T2: BGR to Grey with kernel = [1/3, 1/3, 1/3].
   
 - Input and output
   - by default the input file is "test/test1.ppm" and output file is "output.ppm".
   - The default behaviour can be changed by running make prepare.
   - If make clean is executed, it reset to the default input and output file.

## Additional Features added
 - make buildso: An executable will be made with dynamically linked libraries.
 
## Basic Working
  - Kernel Convolution: It is the technique used in both the transformations.
    - multiply
    - sum
  - config: The config file handles the appropriate input and output paths.
