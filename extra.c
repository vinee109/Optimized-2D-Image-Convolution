#include <emmintrin.h>
#include <omp.h>

int conv2D(float* in, float* out, const int data_size_X, const int data_size_Y,
                    float* kernel, const int kernel_x, const int kernel_y)
{
    // the x coordinate of the kernel's center
    const int kern_cent_X = (kernel_x - 1)/2;
    // the y coordinate of the kernel's center
    const int kern_cent_Y = (kernel_y - 1)/2;
    const int kern_size = kern_cent_Y * kern_cent_X;
    int offset = 0;
    if ( kernel_x > 5 && kernel_x < 15)
	    offset = 1;
    else if ( kernel_x >= 15)
	    offset = 2;     
    int begin  = kern_cent_X + (data_size_X - kern_cent_X)/4*4 - (4 * offset);
    if ( data_size_X % 4 != 0 ){
    	begin -= 4;
    }
    const int start = begin;   
    
    #pragma omp parallel for firstprivate(in, out, kernel)
    for(int y = 0; y < data_size_Y; y++){
    	// left section from 0 column to kern_cent_X    	
	    for(int x = 0; x < kern_cent_X; x++){
    		for(int j = -kern_cent_Y; j <= kern_cent_Y; j++){
    			for(int i = -kern_cent_X; i <= kern_cent_X; i++) {
    				if(x+i>-1 && x+i<data_size_X && y+j>-1 && y+j<data_size_Y){
						out[x+y*data_size_X] += 
								kernel[(kern_cent_X-i)+(kern_cent_Y-j)*kernel_x] * in[(x+i) + (y+j)*data_size_X];
    				}
   	    		}
		    }
		}
        for(int x = kern_cent_X; x < (start - kern_cent_X)/16*16  + kern_cent_X; x+=16) {
    		__m128 out_vec = _mm_loadu_ps(out+x+y*data_size_X);
    		__m128 out_vec1 = _mm_loadu_ps(out+x+4+y*data_size_X);
            __m128 out_vec2 = _mm_loadu_ps(out+x+8+y*data_size_X);
            __m128 out_vec3 = _mm_loadu_ps(out+x+12+y*data_size_X);
    		for(int j = -kern_cent_Y; j <= kern_cent_Y; j++) {
    			if(y+j<0 || y+j>=data_size_Y) {
    				continue;
    			}
    			for(int i = -kern_cent_X; i <= kern_cent_X; i++) {
    				__m128 in_vec = _mm_loadu_ps(in+x+i+(y+j)*data_size_X);
    				__m128 ker_vec = _mm_load1_ps(kernel + (kern_cent_X-i) + (kern_cent_Y-j)*kernel_x);
    				out_vec = _mm_add_ps(out_vec, _mm_mul_ps(ker_vec, in_vec));

    				__m128 in_vec1 = _mm_loadu_ps(in+x+4+i+(y+j)*data_size_X);
    				out_vec1 = _mm_add_ps(out_vec1, _mm_mul_ps(ker_vec, in_vec1));
                    __m128 in_vec2 = _mm_loadu_ps(in+x+8+i+(y+j)*data_size_X);
                    out_vec2 = _mm_add_ps(out_vec2, _mm_mul_ps(ker_vec, in_vec2));
                    __m128 in_vec3 = _mm_loadu_ps(in+x+12+i+(y+j)*data_size_X);
                    out_vec3 = _mm_add_ps(out_vec3, _mm_mul_ps(ker_vec, in_vec3));
    			}
    		}
    		_mm_storeu_ps(out+x+y*data_size_X, out_vec);
    		_mm_storeu_ps(out+x+4+y*data_size_X, out_vec1);
            _mm_storeu_ps(out+x+8+y*data_size_X, out_vec2);
            _mm_storeu_ps(out+x+12+y*data_size_X, out_vec3);
        }
    	for(int x = (start - kern_cent_X)/16*16 + kern_cent_X; x < start; x+=4){
    		__m128 out_vec = _mm_loadu_ps(out+x+y*data_size_X);
    		for(int j = -kern_cent_Y; j <=kern_cent_Y; j++){
    			if(y+j < 0 || y+j>=data_size_Y){
    				continue;
    			}
    			for(int i = -kern_cent_X; i <= kern_cent_X; i++){
    				__m128 in_vec = _mm_loadu_ps(in+x+i+(y+j)*data_size_X);
    				__m128 ker_vec = _mm_load1_ps(kernel + (kern_cent_X-i) + (kern_cent_Y-j)*kernel_x);
    				out_vec = _mm_add_ps(out_vec, _mm_mul_ps(ker_vec, in_vec));
    			}
    		}
    		_mm_storeu_ps(out+x+y*data_size_X, out_vec);
    	}
    	// right section from the starting to the end of the matrix
	   for(int x = start; x < data_size_X; x++) {
    		for(int j = -kern_cent_Y; j <= kern_cent_Y; j++) {
    			for(int i = -kern_cent_X; i <= kern_cent_X; i++) {
    				if(x+i>-1 && x+i<data_size_X && y+j>-1 && y+j<data_size_Y){
						out[x+y*data_size_X] += 
								kernel[(kern_cent_X-i)+(kern_cent_Y-j)*kernel_x] * in[(x+i) + (y+j)*data_size_X];
    				}
    			}
    		}
    	}
    }
    return 1;
}
