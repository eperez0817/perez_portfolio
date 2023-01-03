# Assignment 1
## Image Binarization
The purpose of this assignment was to review tasks in C++ including processing command line arguments, reading/writing files, and manipulating data in arrays.

This assignment revolved around **image binarization**, which is the process of taking a grayscale image and transforming it into a black and white image. The program would read a grayscale image file, which contains pixel values ranging between 0 and 255, and change all pixels to either 0 (black) or 255 (white).

Deciding which pixels to change to 0 or 255 depends on whether or not the program is doing *global* or *local* thresholding. 

*Global* thresholding compares each pixel value to the median value of all pixels from the image. If a given pixel is less than the threshold value, the pixel is changed to 0; otherwise the pixel is changed to 255.

*Local* thresholding base the threshold value for each pixel on the median of the pixels in the surrounding local area of a given pixel.

An example input file is located within this assignment folder.

To compile and run the code, the command line arguments must define whether thresholding will be local or global, the name of the input file, the name of the output file, and the size of the neighborhood if local is selected.
```
 $ ./binarizer global input.img output.img
 $ ./binarizer local input.img output.img 5
```
