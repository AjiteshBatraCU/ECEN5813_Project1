#include <stdio.h>

void help()
{
     printf("Help Menu:\n");
            printf("alloc : Allocate memory - Enter the number of words of memory to allocate. Enter the number of words followed by the command\n");
            printf("free : Free memory - Frees the previously allocated memory block.\n");
            printf("read : Display memory words - Displays contents of the memory in 32-bit hex format.\n");
            printf("write : Write memory words - Enter the address and 32-bit value to write to the address.\n");
            printf("invert : Invert block - Invert all memory bits in a specified memory area. It also reports the time taken by the operation.\n");
	    printf("set pattern : Set random pattern - Write randomly generated values to user specified length of allocated memory.\n");
	    printf("verify pattern : Verify random pattern written from set pattern command.\n>>");
}