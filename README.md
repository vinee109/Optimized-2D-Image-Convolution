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

To change the kernel, you can define it in `benchmark.c`. If you just change the dimensions a kernel will be randomly generated.

The output image resulted from 2D convolution can be found as a file called `out_img.bmp` in the same directory as the rest of your code.

Your speed output will also look like this  
```
Kernel:
3	7	6	-3	5	2	-9	5	1	
-3	-1	5	5	6	-9	-5	1	-7	
4	-2	8	-4	-0	-4	-0	-0	8	
-9	6	-7	3	-0	9	-4	-2	-5	
-5	-2	8	8	-5	-3	-9	-1	3	
4	-3	3	7	-9	9	4	-5	2	
5	-6	3	0	-7	1	4	-8	3	
3	4	-1	9	9	-7	2	-6	-9	
3	6	-3	-2	3	6	-4	8	6	

Image Dimemsions: x = 400, y = 400 	      Kernel Dimensions: x = 9, y = 9 	 Performance: 113.435 Gflop/s
Image Dimemsions: x = 400, y = 600 	      Kernel Dimensions: x = 9, y = 9 	 Performance: 121.088 Gflop/s
Image Dimemsions: x = 400, y = 800 	      Kernel Dimensions: x = 9, y = 9 	 Performance: 126.516 Gflop/s
Image Dimemsions: x = 400, y = 1000 	    Kernel Dimensions: x = 9, y = 9 	 Performance: 130.183 Gflop/s
Image Dimemsions: x = 400, y = 1200 	    Kernel Dimensions: x = 9, y = 9 	 Performance: 132.63 Gflop/s
Image Dimemsions: x = 600, y = 400 	      Kernel Dimensions: x = 9, y = 9 	 Performance: 135.365 Gflop/s
Image Dimemsions: x = 600, y = 600 	      Kernel Dimensions: x = 9, y = 9 	 Performance: 142.377 Gflop/s
Image Dimemsions: x = 600, y = 800 	      Kernel Dimensions: x = 9, y = 9 	 Performance: 142.217 Gflop/s
Image Dimemsions: x = 600, y = 1000 	    Kernel Dimensions: x = 9, y = 9 	 Performance: 143.209 Gflop/s
Image Dimemsions: x = 600, y = 1200 	    Kernel Dimensions: x = 9, y = 9 	 Performance: 144.962 Gflop/s
Image Dimemsions: x = 800, y = 400 	      Kernel Dimensions: x = 9, y = 9 	 Performance: 147.214 Gflop/s
Image Dimemsions: x = 800, y = 600 	      Kernel Dimensions: x = 9, y = 9 	 Performance: 145.402 Gflop/s
Image Dimemsions: x = 800, y = 800 	      Kernel Dimensions: x = 9, y = 9 	 Performance: 149.751 Gflop/s
Image Dimemsions: x = 800, y = 1000 	    Kernel Dimensions: x = 9, y = 9 	 Performance: 148.588 Gflop/s
Image Dimemsions: x = 800, y = 1200 	    Kernel Dimensions: x = 9, y = 9 	 Performance: 121.484 Gflop/s
Image Dimemsions: x = 1000, y = 400 	    Kernel Dimensions: x = 9, y = 9 	 Performance: 151.922 Gflop/s
Image Dimemsions: x = 1000, y = 600 	    Kernel Dimensions: x = 9, y = 9 	 Performance: 144.144 Gflop/s
Image Dimemsions: x = 1000, y = 800 	    Kernel Dimensions: x = 9, y = 9 	 Performance: 143.407 Gflop/s
Image Dimemsions: x = 1000, y = 1000 	    Kernel Dimensions: x = 9, y = 9 	 Performance: 150.839 Gflop/s
Image Dimemsions: x = 1000, y = 1200 	    Kernel Dimensions: x = 9, y = 9 	 Performance: 155.834 Gflop/s
Image Dimemsions: x = 1200, y = 400 	    Kernel Dimensions: x = 9, y = 9 	 Performance: 154.152 Gflop/s
Image Dimemsions: x = 1200, y = 600 	    Kernel Dimensions: x = 9, y = 9 	 Performance: 154.733 Gflop/s
Image Dimemsions: x = 1200, y = 800 	    Kernel Dimensions: x = 9, y = 9 	 Performance: 153.666 Gflop/s
Image Dimemsions: x = 1200, y = 1000 	    Kernel Dimensions: x = 9, y = 9 	 Performance: 157.075 Gflop/s
Image Dimemsions: x = 1200, y = 1200 	    Kernel Dimensions: x = 9, y = 9 	 Performance: 155.912 Gflop/s
Average Gflop/s = 142.644
```
