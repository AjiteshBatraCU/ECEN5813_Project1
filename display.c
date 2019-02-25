/***************************************************
* File to read data from memory
* write function takes in which memory word to start
* at (location), how many words to read (size)
* 
***************************************************/
#include <stdio.h>
#include <stdint.h>

extern char *ptr;

void write(int location, int size)
{
    void *malloc_step = ptr + 32*(location-1); //step @ starting location passed into function
    void *final_location = malloc_step + 32*(size); //final location = step + number of words requested
	
    printf("Data at address %x:\n", malloc_step);

    count = 0;
    for (malloc_step; malloc_step <= final_location; (malloc_step += sizeof(int32_t)))
    {
        if ( count == 1)
        {
            printf("\n");
            count = 0;
        }
	    printf("0x%x", *((int32_t *)(malloc_step)));
	    count++;
    }
	
}