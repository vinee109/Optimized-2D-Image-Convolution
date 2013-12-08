//========================================================================================================================
//==============================DO NOT MODIFY THIS FILE OR YOU WILL RISK MESSING UP YOUR PROJECT!=========================
//========================================================================================================================
int reference(float* in, float* out, int data_size_X, int data_size_Y,
                    float* kernel, int kernel_x, int kernel_y)
{
    // the x coordinate of the kernel's center
    int kern_cent_X = (kernel_x - 1)/2;
    // the y coordinate of the kernel's center
    int kern_cent_Y = (kernel_y - 1)/2;
    
    // main convolution loop
	for(int x = 0; x < data_size_X; x++){ // the x coordinate of the output location we're focusing on
		for(int y = 0; y < data_size_Y; y++){ // the y coordinate of theoutput location we're focusing on
			for(int i = -kern_cent_X; i <= kern_cent_X; i++){ // kernel unflipped x coordinate
				for(int j = -kern_cent_Y; j <= kern_cent_Y; j++){ // kernel unflipped y coordinate
					// only do the operation if not out of bounds
					if(x+i>-1 && x+i<data_size_X && y+j>-1 && y+j<data_size_Y){
						//Note that the kernel is flipped
						out[x+y*data_size_X] += 
								kernel[(kern_cent_X-i)+(kern_cent_Y-j)*kernel_x] * in[(x+i) + (y+j)*data_size_X];
					}
				}
			}
		}
	}
	return 1;
}
