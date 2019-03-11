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
    /* Check if memory allocated */
   if (ptr != NULL)	
   {

    int location, size;

    printf("Which of the %d memory words would you like to start at : ", mem_size);
    scanf("%d", &location);
    while (location > mem_size)
	{
		printf("Outside of allocated memory, please enter a location in the %d memory blocks allocated : ", mem_size);
   		scanf("%d", &location);
	}

    printf("Enter the number of words to read: ");
    scanf("%d", &size);
    while ((size + location - 1) > mem_size)
	{
		printf("Outside of allocated memory, please enter a number up to %d : ", (mem_size - location + 1));
   		scanf("%d", &size);
	}
			

    void *malloc_step = ptr + (sizeof(uint32_t)*(location-1)); //step @ starting location passed into function
    void *final_location = malloc_step + (sizeof(uint32_t)*(size)); //final location = step + number of words requested


    for (; malloc_step < final_location; (malloc_step += sizeof(int32_t)))
    {
        printf("\naddress: %x ", (uint32_t)malloc_step);
	    printf("0x%x", *((int32_t *)(malloc_step)));
    }
   }
 else
   {
	printf("No memory allocated, please use alloc function to allocate memory before reading.\n");
   }
	
}