/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ptr = NULL;
int mem_size = 8;

void do_malloc(int n);
void Write(int location, int value, int size);

int main () {
    
    int some_hex = 0xA0048080;
    do_malloc(mem_size);
    Write(2, some_hex, 1);
   
   return(0);
}

void do_malloc(int n)
{
    
    if (ptr != NULL)
    {
        free(ptr);
        printf("Old Malloc destroyed.\n\r");
    }
    

   /* Initial memory allocation */
   ptr = (void *) malloc((4*n));
   if (ptr == NULL)
   {
       printf("Malloc failed");
   }
   printf("Address = %x\n", ptr);
}

void Write(int location, int value, int size)
{

    void *value_ptr = &value;
    void *malloc_step = ptr + 32*location; //step @ starting location passsed into function
    void *final_location = malloc_step + 32*size - 8; //final location = step + size of the passed in value
    
    printf("Value size = %x\n", value);
    printf("Step Address = %x\n", malloc_step);
    printf("Final location = %x\n", final_location);
    

    /* Copy value of passed int to the passed location
    * value of memory pointer + (# of 32-bit words * 4), step malloc_step by 4 bits, until size of passed int
    * Copy 8 bits into malloc_step from value*/
    for (malloc_step; malloc_step <= final_location; (malloc_step += sizeof(char)))
    {
        memcpy(malloc_step, value_ptr, 1);
        value_ptr += sizeof(char);
    }
    
    value_ptr = &value;
    malloc_step = ptr + 32*location;
    final_location = malloc_step + 32*size;
    
    for (malloc_step; malloc_step <= (final_location + 4); (malloc_step += 4))
    {
       printf("%u @ address %x, compared to %u @ %x\n", *((int *)malloc_step), malloc_step, *((int*)value_ptr), value_ptr);
        value_ptr += 4;
    }
}

//void display(int amount, 
