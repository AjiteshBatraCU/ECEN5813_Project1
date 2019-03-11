#include <stdio.h>

void help()
{
     printf("Help Menu:\n");
            printf("alloc : Allocate memory - Enter the number of words of memory to allocate.\n");
            printf("free : Free memory - Frees the previously allocated memory block.\n");
            printf("read : Display memory words - Displays contents of the requested memory in 32-bit hex format.\n");
            printf("write : Write memory words - Write a requested 32-bit value to a requested memory block in the allocated memory.\n");
            printf("invert : Invert block - Invert all memory bits in the allocated memory. It also reports the time taken by the operation.\n");
	    printf("pattern : Set random pattern - Write randomly generated values to user specified length of allocated memory.\n");
	    printf("verify : Verify random pattern written from set pattern command.\n>>");
}