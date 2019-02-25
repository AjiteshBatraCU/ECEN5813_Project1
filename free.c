/**************************************************
* File to free allocated memory
* 
***************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

extern char *ptr;

void mem_free()
{
   free(ptr);
   printf("Allocated memory freed");

}