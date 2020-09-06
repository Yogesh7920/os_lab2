# OS_lab2 - Image Processing in C

## Requirements
  - imagemagick: for conversion of different format image to jpeg; taken care by make prepare.

## Important Note
 - Transformations
   - T1: Gaussian Blur with 3x3 kernel. This blur is applied Blur Intensity (default=3) times. Note the output of mxn size image will become (m-6)x(n-6)
   - T2: BGR to Grey with kernel = [1/3, 1/3, 1/3].
   
 - Input and output
   - by default the input file is "test/test1.ppm" and output file is "output.ppm".
   - The default behaviour can be changed by running make prepare.
   - If make clean is executed, it reset to the default input and output file.
  
 - Test Cases
    - There are 10 test cases. Some are HD images so running all test cases will take upto 14 seconds approx.
    - To view the original jpg image: https://drive.google.com/drive/folders/1aP9pWBSvuer_d5Pj4w0eB9do90q-yLUp?usp=sharing
    - If make tests/test([1-10]) is executed the results are test_results directory.

## Additional Features added
 - make buildso: An executable will be made with dynamically linked libraries.
 - Blur Intensity: The blur intensity is set to 3, it can be changed in main.c. Note: More intensity -> More time to run
 
## Basic Working
  - Kernel Convolution: It is the technique used in both the transformations.
    - multiply
    - sum
  - config: The config file handles the appropriate input and output paths.
