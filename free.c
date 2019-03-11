/**************************************************
* File to free allocated memory
* 
***************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

extern int32_t *ptr;
extern int32_t mem_size;

void mem_free()
{
   free(ptr);
   ptr = NULL;
   mem_size = 0;
   printf("Allocated memory freed\n>>");
}