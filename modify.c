/***************************************************
* File to write data to memory
* write function takes in which memory word to start
* at (location), how many words to write (size)
* and what data (value)
***************************************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

extern char *ptr;
extern int32_t mem_size;

void write(void)
{
	
    /* Check if memory allocated */
   if (ptr != NULL)	
   {

    int location, value, size;
    printf("Which of the %d memory words would you like to start at : ", mem_size);
    scanf("%x", &location);
    while (location > mem_size)
	{
		printf("Outside of allocated memory, please enter a location in the %d memory blocks allocated : ", mem_size);
   		scanf("%x", &location);
	}

    printf("Enter the data to be entered: ");
    scanf("%x", &value);
    printf("Enter the number of words to write: ");
    scanf("%x", &size);
    while ((size + location - 1) > mem_size)
	{
		printf("Outside of allocated memory, please enter a number up to %d : ", (mem_size - location + 1));
   		scanf("%x", &size);
	}

    void *value_ptr = &value; //pointer to user value to write
    void *malloc_step = ptr + (sizeof(uint32_t)*(location-1)); //step @ starting location passed into function
    void *final_location = malloc_step + (sizeof(uint32_t)*size); //final location = step + size of the passed in value

    /* Copy value of passed value to the passed location
    * value of memory pointer + (# of 32-bit words * 4), step malloc_step by 4 bits, until size of passed int
    * Copy 8 bits into malloc_step from value*/
    for (malloc_step; malloc_step < final_location; (malloc_step += sizeof(int32_t)))
    {
        memcpy(malloc_step, value_ptr, 4);
            printf("address: %x ", malloc_step);
            printf("Memory copied = %x\n", *((int32_t *)(malloc_step)));
    }
   }
 else
   {
	printf("No memory allocated, please use alloc function to allocate memory before writing.\n");
   }

}
