/**************************************************
* File to allocate memory from user
* alloc function takes in number of 32bit words 
* to allocate
***************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

extern int32_t *ptr;
extern int32_t mem_size;

void alloc (void) 	//n is number of 32 bit words to allocate
{    

	printf("Enter number of words of memory to allocate:");
    scanf("%d", &mem_size);
	
   /* If memory has been previously allocated, free it and inform the user */
   if (ptr != NULL)	
   {
       free(ptr);
       printf("Old Malloc destroyed.\n\r");
   }
    

   /* Initial memory allocation */
   ptr = (int32_t *) malloc(mem_size*4);
   
   if (ptr == NULL)	//if pointer returns NULL, announce failure
   {
       printf("Malloc failed");
   }
   else printf("Address = %x\n", ptr);	//else print out memory address

}

