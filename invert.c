/***************************************************
* File to invert allocated memory 
* 
***************************************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

extern int32_t *ptr;
extern int32_t mem_size;

void invert()
{

   /* Check if memory allocated */
   if (ptr != NULL)	
   {

    clock_t t; 
    t = clock(); 			//use clock function in time.h

    int location, size;
    
    printf("Which of the %d memory words would you like to start at : ", mem_size);
    scanf("%d", &location);
    while (location > mem_size)
	{
		printf("Outside of allocated memory, please enter a location in the %d memory blocks allocated : ", mem_size);
   		scanf("%d", &location);
	}
	printf("check for %d\n", location);

    printf("Enter the number of words to read: ");
    scanf("%d", &size);
    while ((size + location - 1) > mem_size)
	{
		printf("Outside of allocated memory, please enter a number up to %d : ", (mem_size - location + 1));
   		scanf("%d", &size);
		printf("check for %d\n", (size + location - 1));
	}


    int32_t mem_inverse = 0; //dereferencing 32 bits of memory

    void *inverse_ptr = &mem_inverse; //pointer to the values to invert for copying back into allocated memory
    
    void *malloc_step = ptr + (sizeof(uint32_t)*(location-1)); //step @ starting location passed into function
    void *final_location = malloc_step + (sizeof(uint32_t)*(size)); //final location = step + number of words requested


    for (; malloc_step < final_location; (malloc_step += sizeof(int32_t)))
    {
        mem_inverse = *((int32_t *)malloc_step);	//dereference pointer plus i value
        mem_inverse = ~mem_inverse;				//invert dereferenced value
       
        memcpy(malloc_step, inverse_ptr, 4);		//copy inverted value back into pointer plus i location
        printf("\naddress: %x ", (int32_t)(uintptr_t)(malloc_step));
	    printf("0x%x", *((int32_t *)malloc_step));
       
    }
    
    t = clock() - t; 		//end time - start time
    double time_taken = ((double)t)/CLOCKS_PER_SEC*1000; // in microseconds
    
    printf("\nTime taken to flip ya bits = %f milliseconds\n>>", time_taken);
   }
   else
   {
	printf("No memory allocated, please use alloc function to allocate memory before inverting.\n");
   }
}