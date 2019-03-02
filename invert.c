/***************************************************
* File to invert allocated memory 
* 
***************************************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

extern char *ptr;
extern int32_t mem_size ;

void invert()
{
    clock_t t; 
    t = clock(); 			//use clock function in time.h
    
    int32_t mem_inverse = 0; //dereferencing 32 bits of memory

    void *inverse_ptr = &mem_inverse; //pointer to the values to invert for copying back into allocated memory
    
    for (int i = 0; (i < (sizeof(int32_t)*mem_size)); (i = i + (sizeof(int32_t))))
    {
        mem_inverse = *((int32_t *)(ptr + i));	//dereference pointer plus i value
        mem_inverse = ~mem_inverse;				//invert dereferenced value
       
        memcpy((ptr+i), inverse_ptr, 4);		//copy inverted value back into pointer plus i location
       printf("\naddress: %x ", (ptr+i));
	    printf("0x%x", *((int32_t *)(ptr+i)));
       
    }
    
    t = clock() - t; 		//end time - start time
    double time_taken = ((double)t)/CLOCKS_PER_SEC*1000; // in microseconds
    
    printf("\nTime taken to flip ya bits = %f milliseconds", time_taken);
}