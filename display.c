/***************************************************
* File to read data from memory
* write function takes in which memory word to start
* at (location), how many words to read (size)
* 
***************************************************/
#include <stdio.h>
#include <stdint.h>

extern char *ptr;
extern int32_t mem_size;

void read (void)
{
    int location, size;
    printf("Which of the %d memory words would you like to start at : ", mem_size);
    scanf("%x", &location);
    printf("Enter the number of words to read: ");
    scanf("%x", &size);
			
    void *malloc_step = ptr + (sizeof(uint32_t)*(location-1)); //step @ starting location passed into function
    void *final_location = malloc_step + (sizeof(uint32_t)*(size)); //final location = step + number of words requested
	
    //printf("Data at address %x:", malloc_step);

    for (malloc_step; malloc_step < final_location; (malloc_step += sizeof(int32_t)))
    {
        printf("\naddress: %x ", malloc_step);
	    printf("0x%x", *((int32_t *)(malloc_step)));
    }
	
}