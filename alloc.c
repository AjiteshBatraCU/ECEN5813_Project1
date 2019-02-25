/**************************************************
* File to allocate memory from user
* alloc function takes in number of 32bit words 
* to allocate
***************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

extern char *ptr;

void alloc (int32_t n) 	//n is number of 32 bit words to allocate
{    
   /* If memory has been previously allocated, free it and inform the user */
   if (ptr != NULL)	
   {
       free(ptr);
       ptr = NULL;
       printf("Old Malloc destroyed.\n");
   }
    

   /* Initial memory allocation */
   ptr = (void *) malloc(n*4);
   
   if (ptr == NULL)	//if pointer returns NULL, announce failure
   {
       printf("Malloc failed\n>>");
   }
   else printf("Address = %x\n>>", ptr);	//else print out memory address

}
