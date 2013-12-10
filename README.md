2D Image Convolution and Optimization
======
created by Vineet Jain, November 2013 

This project involves the utilization of OpenMP, Intel SSE intrinsics, Loop Unrolling as well as various other optimization techniques to perform 2D Image Convolution using variable kernels on various different images.

Kernel Sizes (odd dimensions only): anywhere from 3-19, not necessarily square
Image sizes: anything, must be 32-bit color image or 8-bit grayscale as well as in .bmp format

###Usage:

The program can be compiled using  
`$ make bench-extra`

and then ran using the default script using  
`$ ./bench-extra`

You can specify the size of an image using  
`$ ./bench-extra WIDTH HEIGHT`

or an actual image using  
`$ ./bench-extra YOUR_IMAGE.bmp`  

The output image can be found as a file called `out_img.bmp` in the same directory as the rest of your code.
