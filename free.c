/**************************************************
* File to free allocated memory
* 
***************************************************/
#include <stdio.h>
#include <stdint.h>

extern char *ptr;

void free(void)
{
   free(ptr);
   printf("Allocated memory freed");

}